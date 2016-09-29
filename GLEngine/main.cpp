
#include "config.h"

#include "resources/Library.h"
#include "resources/Material.h"









int main(int argc, char** argv)
{
	Library * myLibrary = Library::get(argc,argv);


	myLibrary->InitOGL();

	Camera* m_camera = new Camera();
	myLibrary->addCamera(m_camera);
	Light * m_light = new Light();
	myLibrary->addLight(m_light);

	Node *myNode = new Node();
		
	myLibrary->addResource("Cubo",myNode);
	
	myLibrary->MainLoop();

	

	return 0;
}











