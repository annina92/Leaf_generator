#version 140 

uniform sampler2D tex;
in vec3 theColor;
in vec2 texture;

out vec4 color;

void main(){
	color = texture(tex, texture);

}