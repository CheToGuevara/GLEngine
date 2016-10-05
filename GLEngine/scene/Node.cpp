/**
* @file    Node.cpp
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#include "Node.h"
static float angle = 0.0f;

Node::Node(){

	_textures.clear();
	model = glm::mat4(1.0f);

	myMesh = new Mesh("models/sphere.obj");

	Material * forwardRender = new Material(Material::FORDWARD, "shaders/fwRendering.v1.vert", "shaders/fwRendering.v1.frag");
	myMaterial = forwardRender;

	Texture *colorTexId = new Texture("img/color.png",Texture::DIFFUSE);
	_textures[Texture::DIFFUSE]= colorTexId;
	Texture *emiTexId = new Texture("img/emissive.png", Texture::EMISIVE);
	_textures[Texture::EMISIVE] = emiTexId;
}

Node::~Node(){


}

void Node::render(glm::mat4 viewMat, glm::mat4 projMat)
{
	model = glm::mat4(1.0f);
	

	if (angle > (3.1415f * 2.0f))
		angle = 0;
	else
		angle = angle + 0.01f;

	model = glm::rotate(model, angle, glm::vec3(1, 1, 0));

	myMaterial->active();

	glm::mat4 modelView = viewMat * model;
	glm::mat4 normal = glm::transpose(glm::inverse(modelView));

	myMaterial->setMatrices(modelView, normal,projMat);
	//LUCES TODO
	
	for (std::map< int, Texture* >::iterator it = _textures.begin();
		it != _textures.end(); it++)
	{
		myMaterial->activeTexture(it->second);
	}

	myMaterial->setAttributes(myMesh->getposVBO(), myMesh->getcolorVBO(),
		myMesh->getnormalVBO(), myMesh->gettexCoordVBO());

	myMesh->render();
	


}

