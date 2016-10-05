/**
* @file    Mesh.h
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/
#ifndef __MESH__
#define __MESH__


#include "../config.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>




class  Mesh
{

public:

	/** @name Constructors and destructors  */
	///@{
	/**
	* Description
	*
	*/
	Mesh(void);

	Mesh(const char *fileName);
	/**
	* Description
	*
	*/
	~Mesh(void);


	///@}

	/** @name Methods */
	///@{

	/**
	* Description
	* Method to add Resource
	*/
	void render();


	unsigned int getposVBO(){ return posVBO; }
	unsigned int getcolorVBO(){ return colorVBO; }
	unsigned int getnormalVBO(){ return normalVBO; }
	unsigned int gettexCoordVBO(){ return texCoordVBO; }



	///@}

	/** @name Attributes */
	///@{



	///@}

protected:

	
	void convertMesh(aiMesh* _aiMesh);


private:
	
	//VAO
	unsigned int vao;

	//VBOs que forman parte del objeto
	unsigned int posVBO;
	unsigned int colorVBO;
	unsigned int normalVBO;
	unsigned int texCoordVBO;
	unsigned int triangleIndexVBO;

	//Vectores
	std::vector<unsigned int> _TriangleIndex;
	std::vector<glm::vec3> _VertexPos;
	std::vector<glm::vec3> _VertexNormal;
	std::vector<glm::vec3> _VertexColor;
	std::vector<glm::vec2> _VertexTexCoord;
	std::vector<glm::vec3> _VertexTangent;
	unsigned int _numTriangleIndex;
};

#endif ///__MESH__