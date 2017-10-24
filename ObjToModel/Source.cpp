#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "glm\glm.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void main()
{
	
	std::ifstream       file("dragon.myobject");
	if (file)
	{
		/*
		* Get the size of the file
		*/
		file.seekg(0, std::ios::end);
		std::streampos          length = file.tellg();
		file.seekg(0, std::ios::beg);

		/*
		* Use a vector as the buffer.
		* It is exception safe and will be tidied up correctly.
		* This constructor creates a buffer of the correct length.
		*
		* Then read the whole file into the buffer.
		*/
		std::vector<char>       buffer(length);
		file.read(&buffer[0], length);

		/*
		* Create your string stream.
		* Get the stringbuffer from the stream and set the vector as it source.
		*/
		std::stringstream       localStream;
		localStream.rdbuf()->pubsetbuf(&buffer[0], length);
		
		/*
		* Note the buffer is NOT copied, if it goes out of scope
		* the stream will be reading from released memory.
		*/
	}
	
	
	/*
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};
	
	vector<Vertex> vertices;
	vector<int> indices;
	Assimp::Importer a;
	
	const aiScene* scene = a.ReadFile("dragon.obj", aiProcess_Triangulate | aiProcess_FlipUVs);

	aiMesh* mesh = scene->mMeshes[0];
	glm::vec3 temp;
	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;

		glm::vec3 vector;
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		
		vertex.Position = vector;

		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		vertex.Normal = vector;

		if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
		{
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);

		vertices.push_back(vertex);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	

	

	std::filebuf fb;
 	fb.open("dragon.myobject", std::ios::out);
	std::ostream os(&fb);
	std::filebuf fbi;
	fb.open("dragonIndices.myobject", std::ios::out);
	std::ostream osi(&fbi);


	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		os << vertices[i].Position.x << " " << vertices[i].Position.y << " " << vertices[i].Position.z << " " << vertices[i].TexCoords.x << " " << vertices[i].TexCoords.y << " " << vertices[i].Normal.x << " " <<  vertices[i].Normal.y << " " << vertices[i].Normal.z << "\n";
	}
	os << "\b";
	fb.close();
	
	fbi.open("dragonIndices.myobject", std::ios::out);
	for (int i = 0; i < indices.size(); i++)
		osi << indices[i] << "\n";
	osi << "\b";
	fbi.close();



	*/
}