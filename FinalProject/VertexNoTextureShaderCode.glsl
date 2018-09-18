#version 140
in  vec3 position;
in  vec3 vertexColor;
in  vec3 normal;

out vec3 theColor;

uniform vec3 lightPosition;
uniform mat4 fullMatrix;
uniform float lightIsOn;


void main()
{
	gl_Position = fullMatrix * vec4(position, 1.0);
	gl_PointSize = 3.0f;


	vec3 lightVector = normalize(lightPosition-position);
	if(lightIsOn==0){
		theColor = vertexColor ;
	}

	else if (lightIsOn==1){

		float brightness = dot(lightVector, normal);
		theColor = vec3(brightness, brightness, brightness);
	}

}





