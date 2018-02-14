#include "GLShader.h"

GLShader::GLShader() {
	shaderTypeIsKnown = false;
}
GLShader::GLShader( GLenum shaderType_ ) {
	CreateShader();
}
GLShader::GLShader( const GLShader& other_ )
{
	GLShader& other = ( ( GLShader& ) other_ );
	shaderId = other.shaderId;
	sourceCode = other.sourceCode;
	shaderType = other.GetShaderType();
	shaderTypeIsKnown = other.GetShaderTypeIsKnown();
	logLength = other.GetLogLength();
	log = other.GetLog();
	result = other.GetResult();
}
std::string GLShader::Compile()
{
	if( shaderId )
	{
		std::stringstream toString;
		GLchar* shaderError;
		glCompileShader( shaderId );
		glGetShaderiv( shaderId, GL_COMPILE_STATUS, &result );
		glGetShaderiv( shaderId, GL_INFO_LOG_LENGTH, &logLength );
		shaderError = ( ( GLchar* ) ( ( logLength > 1 ) ?
			malloc( sizeof( GLchar ) * logLength ) : malloc( sizeof( GLchar ) ) ) );
		glGetShaderInfoLog( shaderId, logLength + 1, &logLength, shaderError );
		toString << shaderError;
		log = toString.str();
		return log;
	}
	return ( ( GLchar* ) "GLShader::Compile() No shaderId!\n" );
}
GL_SHADER_ID_T GLShader::CreateShader( GLenum shaderType_ )
{
	ModifyShaderType( shaderType_ );
	shaderId = glCreateShader( shaderType );
	return shaderId;
}
GLShader GLShader::LoadShaderSource( std::string fileName )
{
	std::string fileSourceCode = LoadFile( fileName );
	if( fileSourceCode.size() > 0 )
	{
		sourceCode = fileSourceCode;
		auto cStringSourceCode = sourceCode.c_str();
		glShaderSource( shaderId, 1, &cStringSourceCode, NULL );
	}
	return ( *this );
}
GLShader GLShader::LoadShaderSource( std::string fileName, GLenum shaderSourceType_ )
{
	GLShader shader = LoadShaderSource( fileName );
	shaderType = shaderSourceType_;
	shaderTypeIsKnown = true;
	return shader;
}
void GLShader::ModifyShaderType( GLenum shaderType_ ) {
	shaderType = shaderType_;
	shaderTypeIsKnown = true;
}
GLenum GLShader::GetShaderType() {
	return shaderType;
}
bool GLShader::GetShaderTypeIsKnown() {
	return shaderTypeIsKnown;
}
