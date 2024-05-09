#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"



std::pair<int, int> Texture::mapToIndex(float x, float y)
{
	std::pair<int, int> result;
	auto func = [](float x) -> float { return x - static_cast<int>(x); };
	x = func(abs(x));
	y = func(abs(y));
	result.first = x * (this->width - 1), result.second = y * (this->height - 1);
	return result;
}

Texture::Texture()
{
	this->data = nullptr;
}

Texture::Texture(const char* path, const std::string& directory, bool gamma)
{
	std::string fileName = std::string(path);
	fileName = directory + '/' + fileName;

	this->data = stbi_load(fileName.c_str(), &(this->width), &(this->height), &(this->nrComponents), 0);
}

std::vector<float> Texture::getColor(MATH::Vector2f texColor)
{
	if (this->data == nullptr)
		return { 255, 255, 255 };
	std::vector<float> result(this->nrComponents);
	std::pair<int, int> index = this->mapToIndex(texColor.x, texColor.y);
 	unsigned char* offset = this->data + static_cast<unsigned int>((index.first + index.second * this->width)) * static_cast<unsigned int>(this->nrComponents);
	for (int k = 0; k < nrComponents; k++)
		result[k] = offset[k];
	return result;
}
