#pragma once
#include "../../MathH/Production.h"

class Camera
{
public:
	MATH::Vector3f up;
	MATH::Vector3f target;
	MATH::Vector3f position;


	Camera();
	Camera(MATH::Vector3f p, MATH::Vector3f t, MATH::Vector3f u);
	MATH::Mat4X4f getLookAtMat();
};


