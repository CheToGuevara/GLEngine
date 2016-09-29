/**
* @file    LIGHT.h
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/
#ifndef __LIGHT__
#define __LIGHT__


#include "../config.h"


class  Light
{

public:

	/** @name Constructors and destructors  */
	///@{



	///@}

	/** @name Methods */
	///@{

	/**
	* Description
	* Method to add Resource
	*/
	


	/**
	* Description
	*
	*/
	Light();
	/**
	* Description
	*
	*/
	~Light(void);



	glm::vec3 Ia;
	glm::vec3 Id;
	glm::vec3 Is;
	glm::vec3 lpos;

};

#endif //__LIGHT__