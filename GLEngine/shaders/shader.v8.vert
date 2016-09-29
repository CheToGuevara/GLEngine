#version 330 core

in vec3 inPos;
in vec2 inTexCoord;
in vec3 inNormal;
uniform mat4 modelViewProj;
uniform mat4 modelView;

out vec2 texCoord;
out vec3 normal;

void main()
{
	
		texCoord =inTexCoord;   
		normal = inNormal;


	gl_Position =  modelViewProj* vec4(inPos, 1.0);
}
