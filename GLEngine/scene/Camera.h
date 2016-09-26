/**
* @file    Camera.h
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/
#ifndef __Camera__
#define __Camera__


#include "../config.h"


class  Camera
{

public:

	/** @name Constructors and destructors  */
	///@{

	/**
	* Description
	*
	*/
	Camera();
	/**
	* Description
	*
	*/
	~Camera(void);

	///@}

	/** @name Methods */
	///@{

	/**
	* Description
	* Method to add Resource
	*/


	///@}


	

protected:
	glm::mat4	proj;
	glm::mat4	view;

}

#endif //__Camera__