#include "GLDebugLog.h"

#ifndef GL_TEST_GL_SHADER_H
#define GL_TEST_GL_SHADER_H
	typedef GLuint GL_SHADER_ID_T;

	struct GLShader : public GLDebugLog
	{
		GL_SHADER_ID_T shaderId;
		std::string sourceCode;
		GLShader();
		GLShader( GLenum shaderType_ );
		GLShader( const GLShader& other_ );
		std::string Compile();
		GL_SHADER_ID_T CreateShader( GLenum shaderType = GL_VERTEX_SHADER );
		GLShader LoadShaderSource( std::string fileName );
		GLShader LoadShaderSource( std::string fileName, GLenum shaderType );
		void ModifyShaderType( GLenum shaderType_ );
		GLenum GetShaderType();
		bool GetShaderTypeIsKnown();
		protected:
		GLenum shaderType;
		bool shaderTypeIsKnown;
	};
#endif
