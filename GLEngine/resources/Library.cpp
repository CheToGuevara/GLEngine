/**
* @file    Library.cpp
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#include "Library.h"


Library * _Library = NULL;

const Library* Library::get()
{
	if (_Library == NULL)
		_Library = new Library();

	return _Library;
}



Library::Library(void)
{
}

Library::~Library(void)
{

}

void Library::addResource(Node * node)
{

	
}

Node *  Library::getChildren(std::string name)
{
	
}


