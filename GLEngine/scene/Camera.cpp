
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

	proj = glm::mat4(1.0f);
	view = glm::mat4(1.0f);

	proj = glm::perspective(glm::radians(60.0f), 1.0f, 1.0f, 50.0f);
	view = glm::mat4(1.0f);
	view[3].z = -6.0f;	
}

Camera::~Camera(void)
{


}

glm::mat4 Camera::getProjMat()
{
	return proj;
}
glm::mat4 Camera::getViewMat()
{
	return view;
}

void Camera::setWindowSize(int width, int height)
{
	proj = glm::perspective(glm::radians(60.0f), float(width) / float(height), 1.0f, 50.0f);
}

