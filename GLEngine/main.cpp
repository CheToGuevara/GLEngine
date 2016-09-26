
#include "config.h"

#include "resources/Library.h"
#include "resources/Material.h"









int main(int argc, char** argv)
{
	const Library * myLibrary = Library::get(argc,argv);


	myLibrary->InitOGL();

	Camera* m_camera = new Camera();
	Light * m_light = new Light();


	Material * forwardRender = new Material(Material::FORDWARD,"../shaders/fwRendering.v1.vert", "../shaders/fwRendering.v1.frag");

	


	/*
	initShaderFw("../shaders/fwRendering.v1.vert", "../shaders/fwRendering.v1.frag");
	initObj();

	initShaderPP("../shaders/postProcessing.v1.vert","../shaders/postProcessing.v1.frag");
	initPlane();

	initFBO();
	resizeFBO(SCREEN_SIZE);*/


	
	
	
	myLibrary->MainLoop();

	delete myLibrary;

	return 0;
}











