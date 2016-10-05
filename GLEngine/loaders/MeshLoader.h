//*****************************************************************
//* --------------------------------------------------------------
//* Descargo de responsabilidad.
//*
//* El c�digos se proporciona �nicamente a modo de ilustraci�n. 
//* El ejemplo no se ha verificado a fondo bajo todas las 
//* condiciones. No se puede garantizar ni dar por supuesta la 
//* fiabilidad, la posibilidad de servicio, ni del funcionamiento 
//* programa.
//*
//* Este fichero se distribuye bajo una licencia no exclusiva
//* de derechos de autor para pudiendo utilizar el c�digo para 
//* generar funciones similares que se ajusten a sus necesidades.
//*
//* El c�digo que aqu� se incluyen se ofrecen "TAL CUAL" sin  
//* garant�as de ning�n tipo.
//*
//* Copyright (C) 2012 by Marcos Garc�a Lorenzo (GMRV - URJC)
//* http://www.gmrv.es/
//*****************************************************************
#pragma once 

#include <vector>
#include "../config.h"

#include "../resources/Mesh.h"

class MeshLoader
{


public:
	static Mesh *loadObj(const char *fileName, bool invertNormals=false);	
	

protected:
	protected:
	typedef std::vector<float> floatList;
	typedef std::vector<unsigned int> uintList;
	typedef std::vector<int> intList;

	MeshLoader();
	~MeshLoader();


	void _loadObj(const char *fileName,  
					bool invertNormals);

/*	int _addVertex(int &i, CInternalMesh *mesh);	
	CInternalMesh *_createMesh(bool invertNormals);

	//Atributos del vertice
	floatList *vertex;
	floatList *normals;
	floatList *texCoords;

	//Definici�n de triangulos
	intList *vfacets;
	intList *nfacets;
	intList *tfacets;

	//Creaci�n de mallas
	intList v2Mesh;
	intList next;
	intList numNormal;
	intList numText;

	//Ficheros
	std::ifstream *objFile;

	CMatBuilder *mats;*/
};

