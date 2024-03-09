#pragma once
#include <iostream>
#include <string>
#include "Production.h"

class Texture
{
private:
	std::pair<int, int> mapToIndex(float x, float y);
public:
	int width, height, nrComponents;
	unsigned char* data;
	std::string path;
	std::string type;
	Texture();
	Texture(const char* path, const std::string& directory, bool gamma = false);
	std::vector<float> getColor(MATH::Vector2f texColor);
};
