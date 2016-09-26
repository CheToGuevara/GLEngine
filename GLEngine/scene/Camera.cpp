
/**
* @file    Camera.cpp
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#include "Camera.h"


Camera::Camera(){

	glm::mat4	proj = glm::mat4(1.0f);
	glm::mat4	view = glm::mat4(1.0f);

	proj = glm::perspective(glm::radians(60.0f), 1.0f, 1.0f, 50.0f);
	view = glm::mat4(1.0f);
	view[3].z = -25.0f;	
}

Camera::~Camera(void)
{


}

