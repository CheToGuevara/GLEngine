//*****************************************************************
//* --------------------------------------------------------------
//* Descargo de responsabilidad.
//*
//* El códigos se proporciona únicamente a modo de ilustración. 
//* El ejemplo no se ha verificado a fondo bajo todas las 
//* condiciones. No se puede garantizar ni dar por supuesta la 
//* fiabilidad, la posibilidad de servicio, ni del funcionamiento 
//* programa.
//*
//* Este fichero se distribuye bajo una licencia no exclusiva
//* de derechos de autor para pudiendo utilizar el código para 
//* generar funciones similares que se ajusten a sus necesidades.
//*
//* El código que aquí se incluyen se ofrecen "TAL CUAL" sin  
//* garantías de ningún tipo.
//*
//* Copyright (C) 2012 by Marcos García Lorenzo (GMRV - URJC)
//* http://www.gmrv.es/
//*****************************************************************

#include "MeshLoader.h"


//matrices
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <algorithm>
#include <set>


#pragma message (__LOC__"falta meter toda la parate emissiva.")


///////////////////////////////////////////////
//// Load




Mesh *MeshLoader::loadObj(const char *fileName, bool invertNormals)
{
	/*
	std::vector<CInternalMesh *>mlist;
	mb->_loadObj(fileName, mlist, invertNormals);

	CGroup *g = new CGroup;

	for (unsigned int i = 0; i<mlist.size(); i++)
	{
		if (mlist[i] != NULL)
		{
			CGroup *gm = new CGroup;
			CMesh *mesh = new CMesh;
			CMeshMaterial *mm = mlist[i]->mat;

			g->addChild(gm);
			gm->addChild(mm);
			gm->addChild(mesh);

			mesh->_vertexList.resize(mlist[i]->vertexList.size() / (unsigned int)(3));
			mesh->_normalsList.resize(mlist[i]->normalsList.size() / (unsigned int)(3));
			mesh->_texCoordList.resize(mlist[i]->texCoordList.size() / (unsigned int)(2));
			mesh->_triangleList.resize(mlist[i]->triangleList.size());

			for (unsigned int j = 0; j< mesh->_vertexList.size(); j++)
			{
				mesh->_vertexList[j].x = mlist[i]->vertexList[3 * j];
				mesh->_vertexList[j].y = mlist[i]->vertexList[3 * j + 1];
				mesh->_vertexList[j].z = mlist[i]->vertexList[3 * j + 2];

				mesh->_normalsList[j].x = mlist[i]->normalsList[3 * j];
				mesh->_normalsList[j].y = mlist[i]->normalsList[3 * j + 1];
				mesh->_normalsList[j].z = mlist[i]->normalsList[3 * j + 2];

				mesh->_texCoordList[j].x = mlist[i]->texCoordList[2 * j];
				mesh->_texCoordList[j].y = mlist[i]->texCoordList[2 * j + 1];
			}

			//int k=0;
			for (unsigned int j = 0; j< mesh->_triangleList.size(); j++)
			{
				mesh->_triangleList[j] = mlist[i]->triangleList[j];

				//k=(k>mlist[i]->triangleList[j])?k:mlist[i]->triangleList[j];
			}
			//std::cout <<k <<std::endl;

			mesh->touch();
		}
	}

	delete mb;
	return g;*/
}



MeshLoader::MeshLoader()
{
	/*//reserva de recursos
	vertex = new floatList;
	normals = new floatList;
	texCoords = new floatList;
	vfacets = new intList;
	nfacets = new intList;
	tfacets = new intList;

	vertex->reserve(3 * 100000);
	normals->reserve(3 * 100000);
	texCoords->reserve(2 * 100000);

	vfacets->reserve(1000000);
	nfacets->reserve(1000000);
	tfacets->reserve(1000000);

	objFile = NULL;

	mats = new CMatBuilder;*/
}

MeshLoader::~MeshLoader()
{
	/*//reserva de recursos
	delete vertex;
	delete normals;
	delete texCoords;
	delete vfacets;
	delete nfacets;
	delete tfacets;
	delete mats;

	if (objFile != NULL) delete objFile;*/
};




















/*



class CInternalMesh
{
    typedef std::vector<float> floatList;
    typedef std::vector<int> intList;
public:
    floatList vertexList;
    floatList normalsList;
    floatList texCoordList;
    intList triangleList;
    CMeshMaterial *mat;
};




class CMatBuilder
{
public:
    CMatBuilder(){}

    ~CMatBuilder()
    {
        std::map <std::string, CMeshMaterial *>::iterator i (matList.begin());
        std::map <std::string, CMeshMaterial *>::iterator end (matList.end());
        for(;i!=end;i++)
            (*i).second->unref();

        defaultMat->unref();
        matList.clear();
    }

    void loatMltFile (const char *fileName)
    {
        std::ifstream mltFile(fileName);
        if (!mltFile.is_open())
        {
            std::cerr << "Error abriendo el fichero de materiales: " << fileName << std::endl;
            return;
        }

        //Se liberan los materiales anteriores
        matList.clear();
        defaultMat = new CMeshMaterial();
        defaultMat->ref();
        CMeshMaterial *cMat=defaultMat;

        //Lectura del fichero linea a linea
        std::string line;
        while(std::getline(mltFile, line))
        {
            if(line == "" || line[0] == '#')
                continue;

            std::istringstream lineParser(line);
            std::string tmp;
            lineParser >> tmp;

            if (tmp=="newmtl"){

                lineParser >> tmp;
                matList[tmp] = new CMeshMaterial();
                matList[tmp]->matName = tmp;
                cMat=(matList[tmp]);
                cMat->ref();
#pragma message (__LOC__"Falta luz emisiva")
            }else if (tmp=="Ka"){
                glm::vec4 mm(1.0f);
                cMat->getAmb().getVal(mm);
                lineParser >> mm[0] >> mm[1] >> mm[2];
                cMat->setAmb(mm);

            }else if (tmp=="Kd"){
                glm::vec4 mm(1.0f);
                cMat->getDff().getVal(mm);
                lineParser >> mm[0] >> mm[1] >> mm[2];
                cMat->setDff(mm);
            }else if (tmp=="Ks"){
                glm::vec4 mm(1.0f);
                cMat->getSpc().getVal(mm);
                lineParser >> mm[0] >> mm[1] >> mm[2];
                cMat->setSpc(mm);
            }else if (tmp=="Ns")
            {
                float mm(1.0f);
                lineParser >> mm;
                cMat->setShn(mm*= 0.128f);
            }else if (tmp=="d"||tmp=="Tr"){

                float alpha;
                lineParser >> alpha;
                alpha = 1.0f - alpha;

                glm::vec4 mm(1.0f);
                cMat->getAmb().getVal(mm);
                mm.w=alpha;
                cMat->setAmb(mm);

                cMat->getEmi().getVal(mm);
                mm.w=alpha;
                cMat->setEmi(mm);

                cMat->getDff().getVal(mm);
                mm.w=alpha;
                cMat->setDff(mm);

                cMat->getSpc().getVal(mm);
                mm.w=alpha;
                cMat->setSpc(mm);

            }else if (tmp=="map_Ka"){
                lineParser >> tmp;
                std::replace( tmp.begin(), tmp.end(), '\\', '/');
                std::string tmp2(tmp);

                std::string path(fileName);
                size_t found;
                //found = path.find_last_of("/\\");
                found = path.find_last_of("/");
                if (found == std::string::npos)
                    path = fileName;
                else
                    //path = path.substr(0,found)+"\\"+tmp;
                    path = path.substr(0,found)+"/"+tmp;

                CTexture2D *tex=new CTexture2D;
                tex->loadFile(path.c_str());
                cMat->setAmb(tex);
                tex->texName = tmp2;

            }else if (tmp=="map_Kd"){

                lineParser >> tmp;
                std::replace( tmp.begin(), tmp.end(), '\\', '/');
                std::string tmp2(tmp);

                std::string path(fileName);
                size_t found;
                //found = path.find_last_of("/\\");
                found = path.find_last_of("/");
                if (found == std::string::npos)
                    path = fileName;
                else
                    path = path.substr(0,found)+"/"+tmp;
                //path = path.substr(0,found)+"\\"+tmp;

                CTexture2D *tex=new CTexture2D;
                tex->loadFile(path.c_str());
                cMat->setDff(tex);
                tex->texName = tmp2;

            }else if (tmp=="map_Ks"){

                lineParser >> tmp;
                std::replace( tmp.begin(), tmp.end(), '\\', '/');
                std::string tmp2(tmp);

                std::string path(fileName);
                size_t found;
                //found = path.find_last_of("/\\");
                found = path.find_last_of("/");
                if (found == std::string::npos)
                    path = fileName;
                else
                    path = path.substr(0,found)+"/"+tmp;
                //path = path.substr(0,found)+"\\"+tmp;

                CTexture2D *tex=new CTexture2D;
                tex->loadFile(path.c_str());
                cMat->setSpc(tex);
                tex->texName = tmp2;

            }else if (tmp=="map_Ns"){

                lineParser >> tmp;
                std::replace( tmp.begin(), tmp.end(), '\\', '/');
                std::string tmp2(tmp);

                std::string path(fileName);
                size_t found;
                //found = path.find_last_of("/\\");
                found = path.find_last_of("/");
                if (found == std::string::npos)
                    path = fileName;
                else
                    path = path.substr(0,found)+"/"+tmp;
                //path = path.substr(0,found)+"\\"+tmp;

                CTexture2D *tex=new CTexture2D;
                tex->loadFile(path.c_str());
                cMat->setDff(tex);
                tex->texName = tmp2;

            }else if (tmp=="map_bump"||tmp=="bump"){
                lineParser >> tmp;
                std::replace( tmp.begin(), tmp.end(), '\\', '/');
                std::string tmp2(tmp);

                std::string path(fileName);
                size_t found;
                //found = path.find_last_of("/\\");
                found = path.find_last_of("/");
                if (found == std::string::npos)
                    path = fileName;
                else
                    path = path.substr(0,found)+"/"+tmp;
                //path = path.substr(0,found)+"\\"+tmp;

                CTexture2D *tex=new CTexture2D;
                tex->loadFile(path.c_str());
                cMat->setBmp(tex);
                tex->texName = tmp2;
            }//else if (tmp=="map_d",disp,decal){
        }

        mltFile.close();
    }

    CMeshMaterial *getMat(const char* matName)
    {
        std::map<std::string,CMeshMaterial *>::iterator it
                = matList.find(matName);

        if(it == matList.end())
            return defaultMat;

        return it->second;
    }

    std::map <std::string,CMeshMaterial *> matList;
    CMeshMaterial *defaultMat;
};


*/




void MeshLoader::_loadObj(const char *fileName,
	bool invertNormals)
{
    /*objFile = new std::ifstream(fileName);

    if (!objFile->is_open())
    {
        std::cerr << "Error abriendo el fichero de datos: " << fileName << std::endl;
        return;
    }

    //Tamaño del fichero
    unsigned int fileSize;
    objFile->seekg (0, std::ios::end);
    fileSize = (unsigned int) objFile->tellg();
    objFile->seekg (0,std::ios::beg);
    int timeStamp=0;

    //Lectura del fichero linea a linea
    std::string line;
    CMeshMaterial *cm=NULL;

    while(std::getline(*objFile, line))
    {
        timeStamp++;
        if (timeStamp>10280)
        {
            unsigned int cur = (unsigned int) objFile->tellg();
#ifdef COUTVERBOSE
            std::cout << "Leidos: " << cur/1028 << "KB de " << fileSize/1028 << "KB. Total: " << (unsigned int)(((float)cur/(float)fileSize)*100.0f) <<"%" <<std::endl;
#endif
            timeStamp=0;
        }

        if(line == "" || line[0] == '#')
            continue;

        std::istringstream lineParser(line);
        std::string tmp;
        lineParser >> tmp;

        if (tmp=="v"){
            float x,y,z;
            lineParser >> x >> y >> z;
            vertex->push_back(x);
            vertex->push_back(y);
            vertex->push_back(z);
        }else if (tmp=="f"){
            while (lineParser.good())
                //for (int i=0;i<3;i++)
            {
                lineParser >> tmp;
                std::istringstream tmpParser(tmp);
                int v=-1,t=-1,n=-1;

                tmpParser >> v;
                v--;

                if (tmpParser.good())
                {
                    char c = tmpParser.get();
                    // Miramos el caso v//vn
                    if (tmpParser.good())
                    {
                        c = tmpParser.get();
                        if (c == '/')//v//vn
                        {
                            tmpParser >> n;
                            n--;
                        }else{//v/t*
                            tmpParser.unget();
                            tmpParser >> t;
                            t--;
                            tmpParser.get();
                            if (tmpParser.good())
                            {
                                tmpParser >> n;
                                n--;
                            }//v/vt/vn
                        }//v/vt*
                    }
                }

                vfacets->push_back(v);
                nfacets->push_back(n);
                tfacets->push_back(t);
            }
            vfacets->push_back(-1);
            nfacets->push_back(-1);
            tfacets->push_back(-1);
        }else if (tmp=="vt"){
            float x,y;
            lineParser >> x >> y;
            texCoords->push_back(x);
            texCoords->push_back(y);

        }else if (tmp=="vn"){
            float x,y,z;
            lineParser >> x >> y >> z;
            normals->push_back(x);
            normals->push_back(y);
            normals->push_back(z);
        }else if (tmp=="g"||tmp=="o"){

            CInternalMesh *mesh=_createMesh(invertNormals);

            if (mesh!=NULL)
            {
                if (cm==NULL)
                    cm=new CMeshMaterial;
                mesh->mat=cm;
                meshList.push_back(mesh);
            }

        }else if (tmp=="mtllib"){

            lineParser >> tmp;

            std::string path(fileName);
            size_t found;
            //found = path.find_last_of("/\\");
            found = path.find_last_of("/");
            if (found == std::string::npos)
                path = fileName;
            else
                //path = path.substr(0,found)+"\\"+tmp;
                path = path.substr(0,found)+"/"+tmp;

            mats->loatMltFile(path.c_str());

        }else if (tmp=="usemtl"){
            CInternalMesh *mesh=_createMesh(invertNormals);

            if (mesh!=NULL)
            {
                if (cm==NULL)cm=new CMeshMaterial;
                mesh->mat=cm;
                meshList.push_back(mesh);
            }

            lineParser >> tmp;
            cm = mats->getMat(tmp.c_str());
        }

    }

    CInternalMesh *mesh=_createMesh(invertNormals);

    if (mesh!=NULL)
    {
        if (cm==NULL) cm=new CMeshMaterial;
        mesh->mat=cm;
        meshList.push_back(mesh);
    }

    objFile->close();*/

}

/*int MeshLoader::_addVertex(int &i, CInternalMesh *mesh)
{
   /* //Add vertex
    int vIdx = (*vfacets)[i];
    if (vIdx == -1) return -1;

    bool fin=false;
    for (int j=i-1;j>-1&&!fin;j--)
    {
        if((*vfacets)[j]==vIdx)
        {
            i++;
            return _addVertex(i,mesh);
        }
        fin=((*vfacets)[j]==-1);
    }



    int tIdx = ((*tfacets)[i]==-1)?-1:(*tfacets)[i]*2;
    int nIdx = ((*nfacets)[i]==-1)?-1:(*nfacets)[i]*3;

    int idx=v2Mesh[vIdx];//Indice del vertice que se añade


    if (idx==-1||nIdx==-1)
    {
        int oldIdx=idx;
        while (idx!=-1)
        {oldIdx =idx; idx = next[idx];}

        idx = mesh->vertexList.size()/3;
        if(oldIdx == -1) v2Mesh[vIdx] = idx;
        else next[oldIdx] = idx;

        next.push_back(-1);

        numNormal.push_back(nIdx);
        numText.push_back(tIdx);

        vIdx*=3;
        mesh->vertexList.push_back((*vertex)[vIdx++]);
        mesh->vertexList.push_back((*vertex)[vIdx++]);
        mesh->vertexList.push_back((*vertex)[vIdx]);

        if (nIdx==-1){
            mesh->normalsList.push_back(-1);
            mesh->normalsList.push_back(-1);
            mesh->normalsList.push_back(-1);
        }else{
            mesh->normalsList.push_back((*normals)[nIdx++]);
            mesh->normalsList.push_back((*normals)[nIdx++]);
            mesh->normalsList.push_back((*normals)[nIdx]);
        }

        if (tIdx==-1){
            mesh->texCoordList.push_back(-1);
            mesh->texCoordList.push_back(-1);
        }else{
            mesh->texCoordList.push_back((*texCoords)[tIdx++]);
            mesh->texCoordList.push_back((*texCoords)[tIdx]);
        }
    }else{ //El vertice ya estaba, hay que comprobar si la normal y las texturas son la misma
        bool fin=false;

        while (!fin){
            if (numNormal[idx] == nIdx && numText[idx] == tIdx)
                fin=true;
            else {
                int oldIdx = idx;
                idx = next[idx];

                //Añadimos un nuevo punto y salimos
                if (idx == -1)
                {
                    fin=true;

                    idx = mesh->vertexList.size()/3;
                    next[oldIdx]= idx;
                    next.push_back(-1);

                    numNormal.push_back(nIdx);
                    numText.push_back(tIdx);

                    vIdx*=3;
                    mesh->vertexList.push_back((*vertex)[vIdx++]);
                    mesh->vertexList.push_back((*vertex)[vIdx++]);
                    mesh->vertexList.push_back((*vertex)[vIdx]);

                    mesh->normalsList.push_back((*normals)[nIdx++]);
                    mesh->normalsList.push_back((*normals)[nIdx++]);
                    mesh->normalsList.push_back((*normals)[nIdx]);

                    if (tIdx==-1){
                        mesh->texCoordList.push_back(-1);
                        mesh->texCoordList.push_back(-1);
                    }else{
                        mesh->texCoordList.push_back((*texCoords)[tIdx++]);
                        mesh->texCoordList.push_back((*texCoords)[tIdx]);
                    }
                }
            } // Else
        } // While
    }// Else principal

    return idx;*/
/*};

///////////////////////////////////
////////////////////////////////////*
/*
CInternalMesh *MeshLoader::_createMesh(bool invertNormals)
{
    if (vfacets->size()<4)
    {
        vfacets->resize(0);
        nfacets->resize(0);
        tfacets->resize(0);

        return NULL;
    }

    unsigned int vSize=vertex->size();
    CInternalMesh *mesh=new CInternalMesh;
    v2Mesh.resize(0);
    v2Mesh.resize(vSize,-1);
    next.resize(0);
    numNormal.resize(0);
    numText.resize(0);


    for (int i=0;i<(int)vfacets->size();)
    {
        //Add triangle (Da por hecho que los tres primeros son distintos de 1)
        int firstPoint =_addVertex(i,mesh); i++;
        int midPoint =_addVertex(i,mesh); i++;
        int lastPoint =_addVertex(i,mesh); i++;

        //Tesselation de poligonos
        while (lastPoint != -1)
        {
            mesh->triangleList.push_back(firstPoint);
            mesh->triangleList.push_back(midPoint);
            mesh->triangleList.push_back(lastPoint);

            midPoint = lastPoint;
            lastPoint = _addVertex(i, mesh); i++;
        }
    }//For

    //Normalización a nivel de cara
    for (int i=0;i<(int) mesh->triangleList.size();i+=3)
    {
        if (numNormal[mesh->triangleList[i]]==-1 ||
                numNormal[mesh->triangleList[i+1]]==-1 ||
                numNormal[mesh->triangleList[i+2]]==-1)
        {
            float v1[3], v2[3], p1[3], p2[3], p3[3], n[3];

            int idx = 3 * mesh->triangleList[i];
            p1[0]= mesh->vertexList[idx];
            p1[1]= mesh->vertexList[idx+1];
            p1[2]= mesh->vertexList[idx+2];

            idx = 3 * mesh->triangleList[i+1];
            p2[0]= mesh->vertexList[idx];
            p2[1]= mesh->vertexList[idx+1];
            p2[2]= mesh->vertexList[idx+2];

            idx = 3 * mesh->triangleList[i+2];
            p3[0]= mesh->vertexList[idx];
            p3[1]= mesh->vertexList[idx+1];
            p3[2]= mesh->vertexList[idx+2];

            v1[0]= p2[0]-p1[0];v1[1]= p2[1]-p1[1];v1[2]= p2[2]-p1[2];
            v2[0]= p3[0]-p2[0];v2[1]= p3[1]-p2[1];v2[2]= p3[2]-p2[2];

            /n[0] = -v1[1]*v2[2] + v1[2]*v2[1];
            n[1] = -v1[2]*v2[0] + v1[0]*v2[2];
            n[2] = -v1[0]*v2[1] + v1[1]*v2[0];
            n[0] = v1[1]*v2[2] - v1[2]*v2[1];
            n[1] = v1[2]*v2[0] - v1[0]*v2[2];
            n[2] = v1[0]*v2[1] - v1[1]*v2[0];


            if (fabs(n[0])+fabs(n[1])+fabs(n[2])>0.0001)
            {
                if (numNormal[mesh->triangleList[i]]==-1)
                {
                    idx = 3 * mesh->triangleList[i];
                    mesh->normalsList[idx] = n[0];
                    mesh->normalsList[idx+1] = n[1];
                    mesh->normalsList[idx+2] = n[2];
                }

                if (numNormal[mesh->triangleList[i+1]]==-1)
                {
                    idx = 3 * mesh->triangleList[i+1];
                    mesh->normalsList[idx]   = n[0];
                    mesh->normalsList[idx+1] = n[1];
                    mesh->normalsList[idx+2] = n[2];
                }

                if (numNormal[mesh->triangleList[i+2]]==-1)
                {
                    idx = 3 * mesh->triangleList[i+2];
                    mesh->normalsList[idx]	 = n[0];
                    mesh->normalsList[idx+1] = n[1];
                    mesh->normalsList[idx+2] = n[2];
                }
            }
        }//if
    }//For

    if (invertNormals)
        for (unsigned int i=0; i<mesh->normalsList.size();i++)
            mesh->normalsList[i]=-mesh->normalsList[i];


    //Se detecta si falta alguna coordanda de textura.
    //int i=0;
    //while (i<numText.size()&&numText[i]!=-1)
    //	i++;

    float bbmax[3]={-1E+37f,-1E+37f,-1E+37f};
    float bbmin[3]={1E+37f,1E+37f,1E+37f};;

    for (int i=0;i<(int) mesh->vertexList.size();i+=3)
    {
        float v = mesh->vertexList[i];
        bbmax[0]=(bbmax[0]<v)?v:bbmax[0];
        bbmin[0]=(bbmin[0]>v)?v:bbmin[0];

        v = mesh->vertexList[i+1];
        bbmax[1]=(bbmax[1]<v)?v:bbmax[1];
        bbmin[1]=(bbmin[1]>v)?v:bbmin[1];

        v = mesh->vertexList[i+2];
        bbmax[2]=(bbmax[2]<v)?v:bbmax[2];
        bbmin[2]=(bbmin[2]>v)?v:bbmin[2];
    }
#ifdef COUTVERBOSE
    std::cout << "Malla finalizada. "<<std::endl <<
                 "BB: esquinas (" << bbmin[0] << ", " << bbmin[1] << ", " << bbmin[2] << "), ( "
              << bbmax[0] << ", " << bbmax[1] << ", " << bbmax[2] << ")" << std::endl;
#endif

    //Se han procesado ya todas estas caras!!!!
    vfacets->resize(0);
    nfacets->resize(0);
    tfacets->resize(0);
    return mesh;
}*/



//void CMesh::loadObj(const char *fileName, std::vector<CMesh *> &meshList, bool invertNormals)
//{
//	CObjMeshBuilder m;
//	m.loadObj(fileName, meshList, invertNormals);
//}






