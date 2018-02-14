#include "GLShaderProgram.h"

static const GLfloat BASIC_TRIANGLE_COORDINATES[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f,
};

int main( int argc, char** args )
{
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
	GLuint vertexArrayId, vertexBuffer;
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
	/////////////////////////////////////////////////////////////////////////////////
	////////////////////////////Hello Triangle///////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	glGenVertexArrays( 1, &vertexArrayId );
	glBindVertexArray( vertexArrayId );
	glGenBuffers( 1, &vertexBuffer );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
	glBufferData( GL_ARRAY_BUFFER, sizeof( BASIC_TRIANGLE_COORDINATES ), BASIC_TRIANGLE_COORDINATES, GL_STATIC_DRAW );
	glEnableVertexAttribArray( 0 );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		( void* ) 0            // array buffer offset
	);		// Rendering Loop
	while( glfwWindowShouldClose( window ) == false )
	{
		if( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
			glfwSetWindowShouldClose( window, true );

		// Background Fill Color
		glClearColor( 0.5f, 0.25f, 0.25f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );//glClear( GL_COLOR_BUFFER_BIT );
		glDrawArrays( GL_TRIANGLES, 0, 3 );
		// Flip Buffers and Draw
		glfwSwapBuffers( window );
		glfwPollEvents();
	}
	glDisableVertexAttribArray( 0 );
	glfwTerminate();
	return EXIT_SUCCESS;
}
