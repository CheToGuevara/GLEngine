//#ifndef ASSIMPBUILDER_H
//#define ASSIMPBUILDER_H
#pragma once

#ifdef GMRVGL_WITH_ASSIMP

#include <vector>
#include <Textures/Texture2D.h>
#include <Scene/Nodes/MeshMaterial.h>

class CGroup;
class CMesh;
class aiNode;
class aiMesh;
class aiScene;
class CSkeleton;
class CTexture2D;
class CMeshMaterial;

class AssimpBuilder
{
public:
    static CGroup *load(std::string fileName, CSkeleton **skl, bool doLoadMaterials = true);
    static bool save();
    inline static bool hasScene(){return ((m_aiScenes.size()!=0)?false:true);}

protected:
    AssimpBuilder();
    ~AssimpBuilder();

    static CGroup *processNode(aiNode *_aiNode, const aiScene *l_aiScene, CSkeleton **skl);
    static CMesh *convertMesh(aiMesh *_aiMesh);
    static void retrieveMeshes(aiNode *node);
    static void downloadMesh(aiNode *node);


    static std::vector<std::vector<CMeshMaterial*> > m_materials;
    static std::vector<const aiScene*> m_aiScenes;
    static CGroup *m_root;
};

#endif
//#endif // ASSIMPBUILDER_H
