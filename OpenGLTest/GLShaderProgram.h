#include "GLShader.h"

#ifndef GL_TEST_GL_SHADER_PROGRAM_H
#define GL_TEST_GL_SHADER_PROGRAM_H
	typedef GLuint GL_SHADER_PROGRAM_ID_T;

	struct GLShaderProgram : public GLDebugLog
	{
		GL_SHADER_PROGRAM_ID_T programId;
		GLShaderProgram();
		GLShaderProgram( const GLShaderProgram& other_ );
		GL_SHADER_PROGRAM_ID_T CreateProgram();
		std::string Link();
		void AddShader( GLShader shader );
		GLShader ObtainShader( size_t index );
		GLShader operator[]( size_t index );
		std::vector< GLShader > GetShaders();
		void SetShaders( std::vector< GLShader > shaders_ );
		protected:
		std::vector< GLShader > shaders;
	};
#endif
