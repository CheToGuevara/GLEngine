#version 330 core

in vec3 inPos;		
#define M_PI 3.1415926535897932384626433832795	
void main()
{
	mat4 modelView = mat4(1.0);
	modelView[3].z = -3;

	mat4 proj = mat4 (1.0);
	float f = 1.0f / tan (M_PI/6.0);
	float far = 10.0;
	float near = 0.1;
 
    proj[0].x = f;
    proj[1].y = f;
    proj[2].z = (far + near) / (near - far);
    proj[2].w = -1.0;
	proj[3].z = (2.0 * far * near) / (near - far);
    proj[3].w = 0.0;

	gl_Position =  proj * modelView * vec4(inPos, 1);
}
