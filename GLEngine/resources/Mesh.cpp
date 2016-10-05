/**
* @file    Mesh.cpp
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/

#include "Mesh.h"

#include "BOX.h"
#include <assimp/postprocess.h>


Mesh::Mesh()
{

	posVBO = -1;
	colorVBO = -1;
	normalVBO = -1;
	texCoordVBO = -1;
	triangleIndexVBO = -1;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//if (inPos != -1)
	{
		glGenBuffers(1, &posVBO);
		glBindBuffer(GL_ARRAY_BUFFER, posVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 3,
			cubeVertexPos, GL_STATIC_DRAW);
		
		/*glBindBuffer(GL_ARRAY_BUFFER, posVBO);
		glVertexAttribPointer(inPos, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inPos);*/
	}

	//if (inColor != -1)
	{
		glGenBuffers(1, &colorVBO);
		glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 3,
			cubeVertexColor, GL_STATIC_DRAW);
		
		/*glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
		glVertexAttribPointer(inColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inColor);*/
	}

	//if (inNormal != -1)
	{
		glGenBuffers(1, &normalVBO);
		glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 3,
			cubeVertexNormal, GL_STATIC_DRAW);
		
		/*glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
		glVertexAttribPointer(inNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inNormal);*/
	}


	//if (inTexCoord != -1)
	{
		glGenBuffers(1, &texCoordVBO);
		glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 2,
			cubeVertexTexCoord, GL_STATIC_DRAW);

		/*glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
		glVertexAttribPointer(inTexCoord, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inTexCoord);*/
	}

	glGenBuffers(1, &triangleIndexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIndexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		cubeNTriangleIndex*sizeof(unsigned int)* 3, cubeTriangleIndex,
		GL_STATIC_DRAW);

	_numTriangleIndex = cubeNTriangleIndex * 3;

}

Mesh::Mesh(const char *fileName)
{
	posVBO = -1;
	colorVBO = -1;
	normalVBO = -1;
	texCoordVBO = -1;
	triangleIndexVBO = -1;

	Assimp::Importer *l_importer = new Assimp::Importer;

	const aiScene *m_aiScene = l_importer->ReadFile(fileName, aiProcessPreset_TargetRealtime_Fast);
	
	if (m_aiScene->mNumMeshes > 0)
		convertMesh(m_aiScene->mMeshes[0]);
	else 
		return;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	if (_VertexPos.size()>0)
	{
		glGenBuffers(1, &posVBO);
		glBindBuffer(GL_ARRAY_BUFFER, posVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*_VertexPos.size(),
			&(_VertexPos.front()), GL_STATIC_DRAW);

		/*glBindBuffer(GL_ARRAY_BUFFER, posVBO);
		glVertexAttribPointer(inPos, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inPos);*/
	}

	if (_VertexColor.size()>0)
	{
		glGenBuffers(1, &colorVBO);
		glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*_VertexColor.size(),
			&(_VertexColor.front()), GL_STATIC_DRAW);

		/*glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
		glVertexAttribPointer(inColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inColor);*/
	}

	if (_VertexNormal.size()>0)
	{
		glGenBuffers(1, &normalVBO);
		glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*_VertexNormal.size(),
			&(_VertexNormal.front()), GL_STATIC_DRAW);

		/*glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
		glVertexAttribPointer(inNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inNormal);*/
	}


	if (_VertexTexCoord.size()>0)
	{
		glGenBuffers(1, &texCoordVBO);
		glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*_VertexTexCoord.size(),
			&(_VertexTexCoord.front()), GL_STATIC_DRAW);

		/*glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
		glVertexAttribPointer(inTexCoord, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inTexCoord);*/
	}

	glGenBuffers(1, &triangleIndexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIndexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		_TriangleIndex.size() * sizeof(unsigned int) , &(_TriangleIndex.front()),
		GL_STATIC_DRAW);

	_numTriangleIndex = _TriangleIndex.size();

}

Mesh::~Mesh()
{


}

void Mesh::render()
{
	
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, _numTriangleIndex,
		GL_UNSIGNED_INT, (void*)0);
} 

/*
void initPlane()
{
	glGenVertexArrays(1, &planeVAO);
	glBindVertexArray(planeVAO);

	glGenBuffers(1, &planeVertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, planeVertexVBO);
	glBufferData(GL_ARRAY_BUFFER, planeNVertex*sizeof(float)* 3,
		planeVertexPos, GL_STATIC_DRAW);
	glVertexAttribPointer(inPosPP, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(inPosPP);

}

void initFBO()
{
	glGenFramebuffers(1, &fbo);
	glGenTextures(1, &colorBuffTexId);
	glGenTextures(1, &depthBuffTexId);
	glGenTextures(1, &vertexBuffTexId);

}

void initObj()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	if (inPos != -1)
	{
		glGenBuffers(1, &posVBO);
		glBindBuffer(GL_ARRAY_BUFFER, posVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 3,
			cubeVertexPos, GL_STATIC_DRAW);
		glVertexAttribPointer(inPos, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inPos);
	}

	if (inColor != -1)
	{
		glGenBuffers(1, &colorVBO);
		glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 3,
			cubeVertexColor, GL_STATIC_DRAW);
		glVertexAttribPointer(inColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inColor);
	}

	if (inNormal != -1)
	{
		glGenBuffers(1, &normalVBO);
		glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 3,
			cubeVertexNormal, GL_STATIC_DRAW);
		glVertexAttribPointer(inNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inNormal);
	}


	if (inTexCoord != -1)
	{
		glGenBuffers(1, &texCoordVBO);
		glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
		glBufferData(GL_ARRAY_BUFFER, cubeNVertex*sizeof(float)* 2,
			cubeVertexTexCoord, GL_STATIC_DRAW);
		glVertexAttribPointer(inTexCoord, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(inTexCoord);
	}

	glGenBuffers(1, &triangleIndexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIndexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		cubeNTriangleIndex*sizeof(unsigned int)* 3, cubeTriangleIndex,
		GL_STATIC_DRAW);

	model = glm::mat4(1.0f);

	colorTexId = loadTex("../img/color2.png");
	emiTexId = loadTex("../img/emissive.png");
}



void renderCube()
{
	glm::mat4 modelView = view * model;
	glm::mat4 modelViewProj = proj * view * model;
	glm::mat4 normal = glm::transpose(glm::inverse(modelView));

	if (uModelViewMat != -1)
		glUniformMatrix4fv(uModelViewMat, 1, GL_FALSE,
		&(modelView[0][0]));
	if (uModelViewProjMat != -1)
		glUniformMatrix4fv(uModelViewProjMat, 1, GL_FALSE,
		&(modelViewProj[0][0]));
	if (uNormalMat != -1)
		glUniformMatrix4fv(uNormalMat, 1, GL_FALSE,
		&(normal[0][0]));

	glBindVertexArray(vao);
	glDrawElements(G_TriangleIndex, cubeNTriangleIndex * 3,
		GL_UNSIGNED_INT, (void*)0);
}
*/

void Mesh::convertMesh(aiMesh *_aiMesh)
{
	if (_aiMesh != NULL)
	{

		unsigned int vertex_size = _aiMesh->mNumVertices;
		unsigned int triangles_size = _aiMesh->mNumFaces;

		/*std::vector<glm::vec3> _VertexPos;
		std::vector<glm::vec3> _VertexNormal;
		std::vector<glm::vec2> _VertexTexCoord;
		std::vector<unsigned int> _TriangleIndex;
		_VertexColor;
		_VertexTexCoord;
		_VertexTangent;
		*/

		_VertexPos.resize(vertex_size);
		_VertexNormal.resize(vertex_size);
		_VertexTexCoord.resize(vertex_size);
		_TriangleIndex.resize(3 * triangles_size);

		//Copio los datos
		glm::vec3 l_point;
		glm::vec3 l_normal;
		glm::vec2 l_uvw;

		aiVector3D l_aiPoint, l_aiNormal, l_aiTextureCoords;
		for (unsigned int i = 0; i < vertex_size; ++i)
		{
			l_aiPoint = _aiMesh->mVertices[i];
			l_aiNormal = _aiMesh->mNormals[i];
			l_aiTextureCoords = (_aiMesh->HasTextureCoords(0)) ? _aiMesh->mTextureCoords[0][i] : aiVector3D(0, 0, 0);

			l_point = glm::vec3(l_aiPoint.x, l_aiPoint.y, l_aiPoint.z);
			l_normal = glm::vec3(l_aiNormal.x, l_aiNormal.y, l_aiNormal.z);
			l_uvw = glm::vec2(l_aiTextureCoords.x, l_aiTextureCoords.y);

			_VertexPos[i] = l_point;
			_VertexNormal[i] = l_normal;
			_VertexTexCoord[i] = l_uvw;
		}

		aiFace l_aiFace;
		for (unsigned int i = 0; i < triangles_size; ++i)
		{
			l_aiFace = _aiMesh->mFaces[i];

			_TriangleIndex[3 * i + 0] = l_aiFace.mIndices[0];
			_TriangleIndex[3 * i + 1] = l_aiFace.mIndices[1];
			_TriangleIndex[3 * i + 2] = l_aiFace.mIndices[2];
		}

		/*l_mesh->_vertexList = _VertexPos;
		l_mesh->_normalsList = _VertexNormal;
		l_mesh->_texCoordList = _VertexTexCoord;
		l_mesh->_triangleList = _TriangleIndex;*/
	}
		
}