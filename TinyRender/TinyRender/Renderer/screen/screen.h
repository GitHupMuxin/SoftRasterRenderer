#pragma once
#include <vector>
#include "../../MathH/Production.h"
class Screen
{
private:
	void init(int width, int height);
public:
	int width, height;
	std::vector<MATH::Vector3f> frameBuffer;
	std::vector<float> depthBuffer;

	void mapToScreen(float& x, float& y);
	int getIndex(int x, int y);
	Screen();
	Screen(int width, int height);
	void Draw(const char* path);
};

