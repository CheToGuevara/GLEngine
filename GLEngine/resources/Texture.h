/**
* @file    Texture.h
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#ifndef __Texture__
#define __Texture__

#include "../config.h"

#include "BOX.h"
#include "PLANE.h"


class  Texture
{

public:

	typedef enum{
		DIFFUSE=0,
		NORMAL,
		EMISIVE,
		SPECULAR,
		BUMP,
		AUXILIAR
		
	} TTexture;

	/** @name Constructors and destructors  */
	///@{
	Texture(const char *fileName,TTexture typeoftexture);

	~Texture();

	unsigned int useTexture();

	TTexture getType();


	///@}

	

	/** @name Methods */
	///@{

	/**
	* Description
	* Method to add Resource
	*/
	

	//Caraga una textura y devuelve un puntero a su ubicacion en mememoria principal
	//también devuelve el tamaño de la textura (w,h)
	//!!Ya implementada
	unsigned char *loadTexture(const char* fileName, unsigned int &w, unsigned int &h);

	//Carga un fichero en una cadena de caracteres
	char *loadStringFromFile(const char *fileName, unsigned int &fileLen);

protected:
	/** @name Attributes */
	///@{
	TTexture _typeoftexture;


	unsigned int _texId;


	///@}

	unsigned int loadTex(const char *fileName);



};






#endif //__Texture__