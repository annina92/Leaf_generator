#version 140
in  vec3 position;
in  vec3 vertexColor;
in  vec2 UVTexture;

out vec3 theColor;
out vec2 texture;

uniform mat4 fullMatrix;




void main()
{
	gl_Position = fullMatrix * vec4(position, 1.0);
	gl_PointSize = 0.1f;
	theColor = vertexColor;
	texture = UVTexture;
}

