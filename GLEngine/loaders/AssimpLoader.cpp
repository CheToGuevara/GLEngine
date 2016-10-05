#ifdef GMRVGL_WITH_ASSIMP
#include "AssimpBuilder.h"

#include <Scene/Nodes/Group.h>
#include <Scene/Nodes/Mesh.h>
#include <Scene/Nodes/MeshMaterial.h>
#include <Textures/Texture2D.h>
#include <Scene/Nodes/Switch.h>
#include <Others/Skeleton/Skeleton.h>
#include <Loaders/SkeletonLoader.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Exporter.hpp>

#include <iostream>
#include <fstream>

std::vector<std::vector<CMeshMaterial*> > AssimpBuilder::m_materials;
std::vector<const aiScene*> AssimpBuilder::m_aiScenes;
CGroup *AssimpBuilder::m_root;

CGroup *AssimpBuilder::load(std::string fileName, CSkeleton **skl, bool doLoadMaterials)
{
    m_root = new CGroup;

    /*
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error abriendo el fichero: " << fileName << std::endl;
        return NULL;
    }*/


    /*
    std::string line;
    while (std::getline(file, line))
    {
    */
        //line = fileName.replace((fileName.begin()+1+fileName.find_last_of('/')), fileName.end(), line);
        Assimp::Importer *l_importer = new Assimp::Importer;

        const aiScene *m_aiScene = l_importer->ReadFile(fileName, aiProcessPreset_TargetRealtime_Fast);
        m_aiScenes.push_back(m_aiScene);

        if (m_aiScene == NULL)
        {
            std::cerr << l_importer->GetErrorString();
            return m_root;
        }

        //TODO Crear un gestor de mallas para no repetir

        //TODO Gestor de texturas
        if (doLoadMaterials){
        if (m_aiScene->HasMaterials())
        {
            std::vector<CMeshMaterial*> scene_materials;
            std::vector<aiString> texture_paths;
            for (unsigned int mat_id = 0; mat_id < m_aiScene->mNumMaterials; ++mat_id)
            {
                aiMaterial *ai_mat = m_aiScene->mMaterials[mat_id];
                unsigned int ai_diff_textures = ai_mat->GetTextureCount(aiTextureType_DIFFUSE);

                CMeshMaterial *mat = new CMeshMaterial;
                if (ai_diff_textures > 0){
                    aiString ai_diff_texture_path;
                    ai_mat->GetTexture(aiTextureType_DIFFUSE, 0, &ai_diff_texture_path);
#ifdef COUTVERBOSE
                    std::cout << ai_diff_texture_path.C_Str() << std::endl;
#endif
                    if (std::find(texture_paths.begin(), texture_paths.end(), ai_diff_texture_path) == texture_paths.end())
                    {
                        texture_paths.push_back(ai_diff_texture_path);
                        CTexture2D *tex2d = new CTexture2D;
                        tex2d->loadFile(ai_diff_texture_path.C_Str());
                        mat->setDff(tex2d);
                    }
                    else
                    {
                        //mat->setDff(*(std::find(texture_paths.begin(), texture_paths.end(), ai_diff_texture_path)));
                    }
                }
                else{
                    aiColor3D ai_color;
                    ai_mat->Get(AI_MATKEY_COLOR_DIFFUSE, ai_color);
                    glm::vec4 color = glm::vec4(ai_color.r, ai_color.g, ai_color.b,1);
                    mat->setDff(color);

                }
                scene_materials.push_back(mat);
                m_materials.push_back(scene_materials);
            }
        }
        }


        //Pido el root de Assimp
        aiNode *l_aiNode = m_aiScene->mRootNode;

        //Proceso la escena de Assimp
        CGroup *assimp_group = processNode(l_aiNode, m_aiScene, skl);
        m_root->addChild(assimp_group);


    //Devuelvo el root convertido
    return m_root;
}

bool AssimpBuilder::save()
{
    /*
    retrieveMeshes(m_aiScene->mRootNode);
    Assimp::Exporter *exporter = new Assimp::Exporter;
    if ((exporter->Export(m_aiScene, "collada", "export.dae")) != AI_SUCCESS){
        for (unsigned int i = 0; i < exporter->GetExportFormatCount(); ++i)
        {
            std::cout << "Formatos: " << exporter->GetExportFormatDescription(i)->id << std::endl;
        }
        std::cout << exporter->GetErrorString() << std::endl;
        return false;
    }
    return true;
    */
	return true;
}

AssimpBuilder::AssimpBuilder()
{
    m_aiScenes.clear();
}

AssimpBuilder::~AssimpBuilder()
{
}

CGroup *AssimpBuilder::processNode(aiNode *_aiNode, const aiScene *m_aiScene, CSkeleton **skl)
{
    if (_aiNode != NULL)
    {
        if (std::string(_aiNode->mName.C_Str()) == "Skeleton")
        {
            *skl = CSkeletonLoader::loadSkl(_aiNode);
			if (m_aiScene->HasAnimations())
			{
				
				CSkeletonLoader::loadAnimSkl(_aiNode,m_aiScene->mAnimations[0],m_aiScene->mMeshes[0],*skl);
			}
            return NULL;
        }

		//Aqui añado el switch
		CSwitch* s = new CSwitch();
        CGroup *g = new CGroup;
		s->addChild(g);
        //Cambio la última barra baja de los nombres por un '.'
        std::string name = _aiNode->mName.C_Str();
        unsigned int pos = name.find_last_of('_');
        if (pos < name.length())
            name.replace(name.find_last_of('_'), 1, ".");

        g->setName(name);
		s->setName(name.append("S"));

        CGroup *l_mesh_group;
        CMesh *l_mesh;
        aiMesh *l_aiMesh;
        CGroup *l_child_group;


        //Recorro las mallas del nodo
        for (unsigned int i = 0; i < _aiNode->mNumMeshes; ++i)
        {
            l_aiMesh = m_aiScene->mMeshes[_aiNode->mMeshes[i]];

            //Convierto la malla al formato propio
            l_mesh = convertMesh(l_aiMesh);
            if (l_mesh != NULL)
            {
                //La asigno al nodo y sigo
                l_mesh_group = new CGroup;
                g->addChild(l_mesh_group);
                if (m_materials.size() > 0)
                    l_mesh_group->addChild(m_materials.at(m_materials.size()-1).at(l_aiMesh->mMaterialIndex));
                l_mesh_group->addChild(l_mesh);
            }
        }

        //Busco los hijos y aplico recursividad
        for (unsigned int i = 0; i < _aiNode->mNumChildren; ++i)
        {
            l_child_group = processNode(_aiNode->mChildren[i], m_aiScene, skl);
            if (l_child_group != NULL)
                g->addChild(l_child_group);
        }

        return s;
    }

    return NULL;
}

CMesh *AssimpBuilder::convertMesh(aiMesh *_aiMesh)
{
    if (_aiMesh != NULL)
    {
        CMesh *l_mesh = new CMesh;
        unsigned int vertex_size = _aiMesh->mNumVertices;
        unsigned int triangles_size = _aiMesh->mNumFaces;

        std::vector<glm::vec3> l_points;
        std::vector<glm::vec3> l_normals;
        std::vector<glm::vec2> l_uvws;
        std::vector<unsigned int> l_triangles;

        l_points.resize(vertex_size);
        l_normals.resize(vertex_size);
        l_uvws.resize(vertex_size);
        l_triangles.resize(3*triangles_size);

        //Copio los datos
        glm::vec3 l_point;
        glm::vec3 l_normal;
        glm::vec2 l_uvw;

        aiVector3D l_aiPoint, l_aiNormal, l_aiTextureCoords;
        for (unsigned int i = 0; i < vertex_size; ++i)
        {
            l_aiPoint = _aiMesh->mVertices[i];
            l_aiNormal = _aiMesh->mNormals[i];
            l_aiTextureCoords = (_aiMesh->HasTextureCoords(0))?_aiMesh->mTextureCoords[0][i]:aiVector3D(0,0,0);

            l_point = glm::vec3(l_aiPoint.x, l_aiPoint.y, l_aiPoint.z);
            l_normal = glm::vec3(l_aiNormal.x, l_aiNormal.y, l_aiNormal.z);
            l_uvw = glm::vec2(l_aiTextureCoords.x, l_aiTextureCoords.y);

            l_points[i] = l_point;
            l_normals[i] = l_normal;
            l_uvws[i] = l_uvw;
        }

        aiFace l_aiFace;
        for (unsigned int i = 0; i < triangles_size; ++i)
        {
            l_aiFace = _aiMesh->mFaces[i];

            l_triangles[3*i+0] = l_aiFace.mIndices[0];
            l_triangles[3*i+1] = l_aiFace.mIndices[1];
            l_triangles[3*i+2] = l_aiFace.mIndices[2];
        }

        l_mesh->_vertexList = l_points;
        l_mesh->_normalsList = l_normals;
        l_mesh->_texCoordList = l_uvws;
        l_mesh->_triangleList = l_triangles;

        l_mesh->touch();

        return l_mesh;
    }

    return NULL;
}

void AssimpBuilder::retrieveMeshes(aiNode *node)
{
    if (node->mNumMeshes > 0)
        downloadMesh(node);

    //Recorro el arbol
    for (unsigned int i = 0; i < node->mNumChildren; ++i)
    {
        retrieveMeshes(node->mChildren[i]);
    }
}

void AssimpBuilder::downloadMesh(aiNode *node)
{
    /*
    //Busco el nodo equivalente en el arbol de escena
    CGroup *meshGroup = m_root->getChildByName(node->mName.C_Str());
    if (meshGroup == NULL)
        return;

    CMesh  *mesh;
    CGroup *actualMesh;
    aiMesh *ai_mesh;
    for (unsigned int i = 0; i < meshGroup->numChildren(); ++i)
    {
        actualMesh = dynamic_cast<CGroup*>(meshGroup->getChild(i));
        if (actualMesh != NULL)
        {
            mesh = dynamic_cast<CMesh*>(actualMesh->getChild(1));

            //Me bajo los vertices modificados
            glm::vec3 *v;// = new glm::vec3[mesh->_vertexList.size()];
            //v = (glm::vec3*)malloc(mesh->_vertexList.size()*sizeof(glm::vec3));

            std::cout << glGetError() << std::endl;
            GLuint buffer = mesh->getBuffers()[0];
            glBindBuffer(GL_ARRAY_BUFFER, mesh->getBuffers()[0]);
            v = (glm::vec3*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
            std::cout << glGetError() << std::endl;
            //glGetBufferSubData(GL_ARRAY_BUFFER, 0, mesh->_vertexList.size()*sizeof(glm::vec3), v);
            //glBindBuffer(GL_ARRAY_BUFFER, 0);

            ai_mesh = m_aiScene->mMeshes[node->mMeshes[i]];

            for (unsigned int j = 0; j < ai_mesh->mNumVertices; ++j)
            {
                ai_mesh->mVertices[j].x = v[j].x;
                ai_mesh->mVertices[j].y = v[j].y;
                ai_mesh->mVertices[j].z = v[j].z;
            }

            glUnmapBuffer(GL_ARRAY_BUFFER);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    }
    */
}

/*
bool AssimpBuilder::saveMesh(CNode *node)
{
    CMesh *mesh;
    if ((mesh = dynamic_cast<CMesh*>(node)) != NULL)
    {
        //Vertices modificados
        glm::vec3 *v;
        v = (glm::vec3*)malloc(mesh->_vertexList.size()*sizeof(glm::vec3));
        glBindBuffer(GL_ARRAY_BUFFER, mesh->getBuffers()[0]);
        glGetBufferSubData(GL_ARRAY_BUFFER, 0, mesh->_vertexList.size()*sizeof(glm::vec3), v  );
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        //Lista de triangulos
        unsigned int *t;
        t = (unsigned int*)malloc(mesh->_triangleList.size()*sizeof(unsigned int));
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->getBuffers()[3]);
        glGetBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, mesh->_triangleList.size()*sizeof(unsigned int), t);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        for (unsigned int i = 0; i < m_aiScene->mMeshes[meshPosition]->mNumVertices; ++i)
        {
            m_aiScene->mMeshes[meshPosition]->mVertices[i].x = v[i].x;
            m_aiScene->mMeshes[meshPosition]->mVertices[i].y = v[i].y;
            m_aiScene->mMeshes[meshPosition]->mVertices[i].z = v[i].z;
        }

        ++meshPosition;
        return true;
    }

    CGroup *g;
    if ((g = dynamic_cast<CGroup*>(node)) != NULL)
    {
        for (unsigned int i = 0; i < g->numChildren(); ++i)
        {
             saveMesh(g->getChild(i));
        }
    }

    return true;
}
*/
#endif
