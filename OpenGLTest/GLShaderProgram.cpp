#include "GLShaderProgram.h"

GLShaderProgram::GLShaderProgram() {
	CreateProgram();
}
GLShaderProgram::GLShaderProgram( const GLShaderProgram& other_ )
{
	GLShaderProgram& other = ( ( GLShaderProgram& ) other_ );
	programId = other.programId;
	shaders = other.GetShaders();
}
GL_SHADER_PROGRAM_ID_T GLShaderProgram::CreateProgram() {
	programId = glCreateProgram();
	return programId;
}
std::string GLShaderProgram::Link()
{
	std::stringstream toString;
	for( GLShader currentShader : shaders )
		glAttachShader( programId, currentShader.shaderId );
	glLinkProgram( programId );
	glGetProgramiv( programId, GL_LINK_STATUS, &result );
	glGetProgramiv( programId, GL_INFO_LOG_LENGTH, &logLength );
	GLchar* programError = ( ( GLchar* ) malloc( ( sizeof( GLchar ) * ( ( logLength > 1 ) ? logLength : 1 ) ) ) );
	glGetProgramInfoLog( programId, ( logLength + 1 ), &logLength, programError );
	toString << programError;
	log = toString.str();
	return log;
}
void GLShaderProgram::AddShader( GLShader shader ) {
	shaders.push_back( shader );
}
GLShader GLShaderProgram::ObtainShader( size_t index ) {
	return shaders[ index ];
}
GLShader GLShaderProgram::operator[]( size_t index ) {
	return ObtainShader( index );
}
std::vector< GLShader > GLShaderProgram::GetShaders() {
	return shaders;
}
void GLShaderProgram::SetShaders( std::vector< GLShader > shaders_ ) {
	shaders = shaders_;
}
