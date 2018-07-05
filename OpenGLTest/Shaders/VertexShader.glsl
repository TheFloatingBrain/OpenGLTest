#version 330	 core
layout(location = 0) in vec3 vertexPosition_modelspace;
uniform mat4 rotation_Matrix;
void main()
{
	gl_Position.xyz = vertexPosition_modelspace;
	gl_Position.w = 1.0;
	gl_Position = gl_Position * rotation_Matrix;
}
