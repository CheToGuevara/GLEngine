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

	



private:
	
	//VAO
	unsigned int vao;

	//VBOs que forman parte del objeto
	unsigned int posVBO;
	unsigned int colorVBO;
	unsigned int normalVBO;
	unsigned int texCoordVBO;
	unsigned int triangleIndexVBO;


};

#endif ///__MESH__