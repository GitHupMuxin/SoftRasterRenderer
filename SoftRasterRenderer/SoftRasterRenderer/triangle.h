#pragma once
#include <vector>
#include "Production.h"

struct Vertex
{
	MATH::Vector3f position;
	MATH::Vector3f Normal;
	MATH::Vector2f TexCoord;
};

class Triangle
{
public:
	std::vector<Vertex> point;
	Triangle();
};
