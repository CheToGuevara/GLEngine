/**
* @file    Light.cpp
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#include "Light.h"

Light::Light()
{
	Ia = glm::vec3(0.3);
	Id = glm::vec3(1.0);
	Is = glm::vec3(1.0);
	lpos = glm::vec3(0.0,1.0,1.0);
}