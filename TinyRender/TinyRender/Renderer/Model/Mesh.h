#pragma once
#include <string>
#include <vector>
#include "../../MathH/Production.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../texture/texture.h"
#include "../triangle/triangle.h"

namespace MODEL
{


	class Mesh
	{
	public:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;

		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	};
}

