/**
* @file    Node.h
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/
#ifndef __NODE__
#define __NODE__


#include "../config.h"
#include "Node.h"
#include "../resources/Texture.h"
#include "../resources/Material.h"
#include "../resources/Mesh.h"


class  Node
{

public:

	/** @name Constructors and destructors  */
	///@{

	/**
	* Description
	*
	*/
	Node(void);
	/**
	* Description
	*
	*/
	~Node(void);

	///@}

	/** @name Methods */
	///@{

	/**
	* Description
	* Method to add Resource
	*/
	void render(glm::mat4 viewMat, glm::mat4 projMat);

	



	///@}

	/** @name Attributes */
	///@{



	///@}

protected:

	



private:

	Mesh * myMesh;
	Material * myMaterial;
	std::map< int, Texture* > _textures;

	glm::mat4 model;


};


#endif  //__NODE__