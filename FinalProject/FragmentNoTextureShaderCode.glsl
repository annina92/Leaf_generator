#version 140 

in vec3 theColor;

out vec4 color;

void main(){
	color = vec4(theColor, 0.0f);
}