/**
* @file    Material.h
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#ifndef __MATERIAL__
#define __MATERIAL__

#include "../config.h"

#include "Texture.h"

#include "BOX.h"
#include "PLANE.h"


class  Material
{

public:

	typedef enum{
		FORDWARD,
		POSTPROCCESS
	} TShader;

	/** @name Constructors and destructors  */
	///@{
	Material(TShader typeofshader, const char *vname, const char *fname);

	~Material();




	///@}

	

	/** @name Methods */
	///@{

	void setMatrices(glm::mat4 modelView, glm::mat4 normalMat,glm::mat4 projMat);
	void setMatrices(glm::mat4 modelView, glm::mat4 normalMat);
	void setMatrices(glm::mat4 modelView);

	void setAttributes(unsigned int posVBO,
						unsigned int colorVBO=-1,
						unsigned int normalVBO=-1,
						unsigned int texCoordVBO=-1);
	


	void active();
	void deactive();


	void activeTexture(Texture* texture);


	

	/**
	* Description
	* Method to add Resource
	*/
	GLuint loadShader(const char *fileName, GLenum type);

	

protected:
	/** @name Attributes */
	///@{
	TShader _typeofshader;


	///@}

	void initShaderPP(const char *vname, const char *fname);
	void initShaderFw(const char *vname, const char *fname);




	//Por definir
	unsigned int vshader;
	unsigned int fshader;
	unsigned int program;
	unsigned int postProccesVShader;
	unsigned int postProccesFShader;
	unsigned int postProccesProgram;

	//Variables Uniform 
	int uModelViewMat;
	int uModelViewProjMat;
	int uNormalMat;


	//Texturas Uniform
	int uColorTex;
	int uEmiTex;
	unsigned int uColorTexPP;

	//Atributos
	int inPos;
	int inColor;
	int inNormal;
	int inTexCoord;
	int inPosPP;

private:
	//Caraga una textura y devuelve un puntero a su ubicacion en mememoria principal
	//también devuelve el tamaño de la textura (w,h)
	//!!Ya implementada
	unsigned char *loadTexture(const char* fileName, unsigned int &w, unsigned int &h);

	//Carga un fichero en una cadena de caracteres
	char *loadStringFromFile(const char *fileName, unsigned int &fileLen);

};






#endif //__MATERIAL__