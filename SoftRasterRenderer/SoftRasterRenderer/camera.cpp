#include "camera.h"

Camera::Camera() { }

Camera::Camera(MATH::Vector3f p, MATH::Vector3f t, MATH::Vector3f u) : position(p), target(t), up(u) { }

MATH::Mat4X4f Camera::getLookAtMat()
{
	MATH::Vector3f dircetion = MATH::normalize(target - position);
	MATH::Vector3f u = MATH::normalize(up);
	MATH::Vector3f left = MATH::crossProduction(u, dircetion);
	MATH::Mat4X4f translate(1.0f, 0, 0, -position.x,
							0, 1.0f, 0, -position.y,
							0, 0, 1.0f, -position.z,
							0, 0, 0, 1.0f);
	MATH::Mat4X4f result(MATH::Mat3x3f(left, u, dircetion));
	return MATH::multiple(result, translate);
}





