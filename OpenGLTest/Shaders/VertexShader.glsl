out vec4 derp;

void main() {
	derp = vec4( 0.0, 0.0, 5.0, 1.0 );
	gl_Position  = gl_ModelViewProjectionMatrix * gl_Vertex;
}
