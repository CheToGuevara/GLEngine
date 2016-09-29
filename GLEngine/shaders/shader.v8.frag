#version 330 core
in vec2 texCoord;
in vec3 normal;
out vec4 outColor;

uniform sampler2D colorTex;
void main()
{
		outColor = vec4(normal,1.0);
}
