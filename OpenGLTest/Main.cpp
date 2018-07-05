#include "GLShaderProgram.h"

static /*const */ GLfloat BASIC_TRIANGLE_COORDINATES[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f,
};
static const GLfloat SIMPLE_2D_SQUARE_COORDINATES[] = {
	1.0f, 0.0f, 0.0f, 
	1.0f, 1.0f, 0.0f, 
	0.0f, 1.0f, 0.0f, 
	0.0f, 0.0f, 0.0f
};

static GLfloat currentVertex[] = { SIMPLE_2D_SQUARE_COORDINATES[ 0 ], 
		SIMPLE_2D_SQUARE_COORDINATES[ 1 ], SIMPLE_2D_SQUARE_COORDINATES[ 2 ] 
};



typedef std::pair< std::vector< GLfloat >, std::vector< GLuint > > MODEL_T;

MODEL_T DoTheImportThing( const char* pFile );
MODEL_T DoTheSceneProcessing( const aiScene* scene );

int main( int argc, char** args )
{	
	InfInt myInt = "100000000334343324424324";
	//myInt += 1;
	std::cout << "Test: " << myInt << "\n";
	// Load GLFW and Create a Window
	glfwInit();
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
	glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
	auto window = glfwCreateWindow( 1280, 800, "OpenGL", nullptr, nullptr );

	// Check for Valid Context
	if( window == nullptr ) {
		fprintf( stderr, "Failed to Create OpenGL Context" );
		return EXIT_FAILURE;
	}
	// Create Context and Load OpenGL Functions
	glfwMakeContextCurrent( window );
	gladLoadGL();
	fprintf( stderr, "OpenGL %s\n", glGetString( GL_VERSION ) );

	GLShader vertexShader( GL_VERTEX_SHADER ), fragmentShader( GL_FRAGMENT_SHADER );
	GLShaderProgram shaderProgram;
	GLuint vertexArrayId, vertexBuffer, indicyArrayId, indicyBuffer;
	std::cout << "-----Loading Vertex Shader-----\n";
	vertexShader.LoadShaderSource( "Shaders\\VertexShader.glsl" );
	std::cout << "Vertex Shader Source\n" << vertexShader.sourceCode << "\n-----Done-----\nCompiling Vertex Shader\n";
	std::cout << vertexShader.Compile() << "\n-----Done-----\n";
	std::cout << "-----Loading Fragment Shader-----\n";
	fragmentShader.LoadShaderSource( "Shaders\\FragmentShader.glsl" );
	std::cout << "Fragment Shader Source\n" << fragmentShader.sourceCode << "\n-----Done-----\nCompiling Fragment Shader\n";
	std::cout << fragmentShader.Compile() << "\n-----Done-----\n";
	shaderProgram.AddShader( vertexShader );
	shaderProgram.AddShader( fragmentShader );
	std::cout << "Linking Shader Program\n";
	std::cout << shaderProgram.Link() << "\n";

	/////////////////////////////////Use./////////////////////////////
	glUseProgram( shaderProgram.programId );
	GLint attrib = glGetAttribLocation( shaderProgram.programId, "vertexPosition_modelspace" );
	GLint rotMat = glGetUniformLocation( shaderProgram.programId, "rotation_Matrix" );
	std::cout << "Attrib: " << attrib << "\n";
	std::cout << "RotMat: " << rotMat << "\n";
	//////////////////////////////////////////////////////////////////
	MODEL_T model = DoTheImportThing( "model.obj" );
	const size_t VERTICIES_C = model.first.size();
	const size_t INDICY_SIZE_C = model.second.size();
	double a = 0.0;
	glm::mat4 rotationMatrix;
	GLuint* indicyArray = model.second.data();
	GLfloat* vertexArray = model.first.data();
	//////////////////////////////////////////////////////////////////

	for( size_t i = 0; i < model.first.size(); i += 3 ) {
		model.first[ i ] += .3f;
		model.first[ i + 1 ] += .3f;
	}

	glGenVertexArrays( 1, &vertexArrayId );
	glGenBuffers( 1, &vertexBuffer );

	glBindVertexArray( vertexArrayId );

	glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
	glBufferData( GL_ARRAY_BUFFER, VERTICIES_C * sizeof( GLfloat ), vertexArray, GL_STATIC_DRAW );

	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		( void* ) 0         // array buffer offset
	);


	glEnableVertexAttribArray( 0 );

	glGenBuffers( 1, &indicyBuffer );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indicyBuffer );

	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( GLuint ) * INDICY_SIZE_C, indicyArray, GL_STATIC_DRAW );

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indicyBuffer );


	glEnable( GL_DEPTH_TEST ); //L_CULL_FACE );


	while( glfwWindowShouldClose( window ) == false )
	{
		if( glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS )
		{
			for( size_t i = 2; i < VERTICIES_C; i += 3 ) {
				model.first[ i ] += 0.1f;
			}
		}
		if( glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS )
		{
			for( size_t i = 2; i < VERTICIES_C; i += 3 ) {
				model.first[ i ] -= 0.1f;
			}
		}
		if( glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS )
		{
			for( size_t i = 0; i < VERTICIES_C; i += 3 ) {
				model.first[ i ] += 0.1f;
			}
		}
		if( glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS )
		{
			for( size_t i = 0; i < VERTICIES_C; i += 3 ) {
				model.first[ i ] -= 0.1f;
			}
		}
		if( glfwGetKey( window, GLFW_KEY_E ) == GLFW_PRESS )
		{
			for( size_t i = 1; i < VERTICIES_C; i += 3 ) {
				model.first[ i ] += 0.1f;
			}
		}
		if( glfwGetKey( window, GLFW_KEY_Q ) == GLFW_PRESS )
		{
			for( size_t i = 1; i < VERTICIES_C; i += 3 ) {
				model.first[ i ] -= 0.1f;
			}
		}
		// Rendering Loop

		if( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
			glfwSetWindowShouldClose( window, true );


		// Background Fill Color
		glClearColor( 0.5f, 0.25f, 0.25f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//		glLoadIdentity();
		if( glfwGetKey( window, GLFW_KEY_Z ) == GLFW_PRESS )
		{
			a += 1.0;
			if( a > 360.0 )
				a -= 360.0;
			rotationMatrix = glm::rotate( rotationMatrix, glm::radians( ( float ) a ), glm::vec3( 0.0, 1.0, 1.0 ) );
			glUniformMatrix4fv( rotMat, 1, GL_FALSE, glm::value_ptr( rotationMatrix ) );
		}
		else {
			rotationMatrix = glm::rotate( rotationMatrix, glm::radians( 0.0f ), glm::vec3( 0.0, 0.0, 1.0 ) );
			glUniformMatrix4fv( rotMat, 1, GL_FALSE, glm::value_ptr( rotationMatrix ) );
		}
		glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
		glBufferData( GL_ARRAY_BUFFER, VERTICIES_C * sizeof( GLfloat ), vertexArray, GL_STATIC_DRAW );

		glDrawElements(
			GL_TRIANGLES,      // mode
			INDICY_SIZE_C,    // count
			GL_UNSIGNED_INT,   // type
			( void* ) 0           // element array buffer offset
		);
		// Flip Buffers and Draw
		glfwSwapBuffers( window );
		glfwPollEvents();
	}
	glDisableVertexAttribArray( 0 );
	glfwTerminate();
	return EXIT_SUCCESS;
}

MODEL_T DoTheImportThing( const char* pFile )
{
	MODEL_T model;
	// Start the import on the given file with some example postprocessing
	// Usually - if speed is not the most important aspect for you - you'll t
	// probably to request more postprocessing than we do in this example.
	const aiScene* scene = aiImportFile( pFile,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType );
	// If the import failed, report it
	if( !scene ) {
		std::cerr << aiGetErrorString() << "\n";
		return model;
	}
	// Now we can access the file's contents
	model = DoTheSceneProcessing( scene );
	// We're done. Release all resources associated with this import
	aiReleaseImport( scene );
	return model;
}

MODEL_T DoTheSceneProcessing( const aiScene* scene )
{
	MODEL_T model;
	std::vector< GLfloat >& verticies = model.first;
	std::vector< GLuint >& indicies = model.second;
	if( scene->HasMeshes() == true )
	{
		for( size_t i = 0; i < scene->mNumMeshes; ++i )
		{
			const size_t VERTICIES_C = scene->mMeshes[ i ]->mNumVertices;
			const size_t FACES_C = scene->mMeshes[ i ]->mNumFaces;
			const size_t INDICIES_C = scene->mMeshes[ i ]->mFaces->mNumIndices;
		//	std::cerr << "Mesh vertex size: " << VERTICIES_C << "\n";
			for( size_t j = 0; j < VERTICIES_C; ++j )
			{
				aiVector3D VECTOR_C = scene->mMeshes[ i ]->mVertices[ j ];
				std::cerr << VECTOR_C.x << ", " << VECTOR_C.y << ", " << VECTOR_C.z << "\n";
				verticies.push_back( VECTOR_C.x );
				verticies.push_back( VECTOR_C.z );
				verticies.push_back( VECTOR_C.z );
			}
		//	std::cout << "FACES: " << FACES_C << "\n";
			for( size_t j = 0; j < FACES_C; ++j )
			{
	//			std::cerr << "INDECIES: " << scene->mMeshes[ i ]->mFaces->mNumIndices << "\n";
				for( size_t k = 0; k < INDICIES_C; ++k )
				{
					indicies.push_back( scene->mMeshes[ i ]->mFaces[ j ].mIndices[ k ] );
				//	std::cerr << "\t" << scene->mMeshes[ i ]->mFaces[ j ].mIndices[ k ] << "\n";
				}
			}
		}
	}
	return model;
}
