#pragma once
#include <functional>
#include "camera.h"
#include "screen.h"
#include "rasterization.h"
#include "triangle.h"
#include "texture.h"
#include "Model.h"

class light
{
public:
	MATH::Vector3f lightPos;
	MATH::Vector3f lightInstensity;
};

class VertexShaderData
{
public:
	Triangle triangle;
	MATH::Vector3f cameraPos;
	std::vector<light> light;
	Texture texture;
	VertexShaderData();
};

class fragmentShaderData
{
public:
	MATH::Vector3f fagPos;
	MATH::Vector3f Normal;
	MATH::Vector3f diffuseColor;
	MATH::Vector3f cameraPos;
	std::vector<light> light;
};


class Render
{

	typedef std::function<void(VertexShaderData data)> vertexShader;
	typedef std::function<MATH::Vector3f(fragmentShaderData data)> fragmentShader;

private:
	void init();
public:
	Screen screen;
	Camera camera;
	Rasterization rasterization;
	vertexShader vShader;
	fragmentShader fShader;
	Render();
	void Rendering(MODEL::Model& model);
	void mapToScreen(Triangle& triangle);
};

