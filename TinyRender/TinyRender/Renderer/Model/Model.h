#pragma once
#include "Mesh.h"
#include "../texture/texture.h"
#include "../triangle/triangle.h"

namespace MODEL
{
	class Model
	{
	private:
		std::vector<Mesh> meshes;
		std::string directory;
		std::vector<Texture> textures_loaded;
		void loadModel(std::string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	public:

		Model(char* path);
		inline Mesh& getMesh(unsigned int i) { return meshes[i]; }
		inline std::vector<Mesh> getMeshArray() { return meshes; }
	};
}

