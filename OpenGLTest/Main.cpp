#include "GLShaderProgram.h"

int main( int argc, char** args )
{
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
		std::cout << "Compiling Vertex Shader\n";
		vertexShader.LoadShaderSource( "Shaders\\VertexShader.glsl" );
		std::cout << "Vertex Shader Source\n" << vertexShader.sourceCode << "\n";
		std::cout << vertexShader.Compile() << "\n";
		std::cout << "Compiling Fragment Shader\n";
		fragmentShader.LoadShaderSource( "Shaders\\FragmentShader.glsl" );
		std::cout << "Fragment Shader Source\n" << fragmentShader.sourceCode << "\n";
		std::cout << fragmentShader.Compile() << "\n";
		shaderProgram.AddShader( vertexShader );
		shaderProgram.AddShader( fragmentShader );
		std::cout << "Linking Shader Program\n";
		std::cout << shaderProgram.Link() << "\n";
		// Rendering Loop
		while( glfwWindowShouldClose( window ) == false )
		{
			if( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
				glfwSetWindowShouldClose( window, true );

			// Background Fill Color
			glClearColor( 0.25f, 0.25f, 0.25f, 1.0f );
			glClear( GL_COLOR_BUFFER_BIT );

			// Flip Buffers and Draw
			glfwSwapBuffers( window );
			glfwPollEvents();
		}

		glfwTerminate();
	}
	char c;
	std::cin >> c;
	return EXIT_SUCCESS;
}
