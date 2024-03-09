#include "Tool.h"

bool Tool::inTriangle(MATH::Vector2f P, Triangle triangle)
{
	bool test[3];
	MATH::Vector2f V[3] =
	{
		MATH::Vector2f(triangle.point[1].position.x - triangle.point[0].position.x, triangle.point[1].position.y - triangle.point[0].position.y),
		MATH::Vector2f(triangle.point[2].position.x - triangle.point[1].position.x, triangle.point[2].position.y - triangle.point[1].position.y),
		MATH::Vector2f(triangle.point[0].position.x - triangle.point[2].position.x, triangle.point[0].position.y - triangle.point[2].position.y)

	};
	for (int i = 0; i < 3; i++)
	{
		MATH::Vector2f now;
		now = MATH::Vector2f(P.x - triangle.point[i].position.x, P.y - triangle.point[i].position.y);
		test[i] = (now.x * V[i].y - now.y * V[i].x) >= 0 ? true : false;
	}
	return (test[0] && test[1] && test[2]) || (!test[0] && !test[1] && !test[2]);
}

std::tuple<float, float, float> Tool::computeArealCoord2D(MATH::Vector2f point, Triangle triangle)
{
	float& x = point.x, y = point.y;
	float& xA = triangle.point[0].position.x, yA = triangle.point[0].position.y;
	float& xB = triangle.point[1].position.x, yB = triangle.point[1].position.y;
	float& xC = triangle.point[2].position.x, yC = triangle.point[2].position.y;
	float gamma = ((yA - yB) * x + (xB - xA) * y + xA * yB - xB * yA) / ((yA - yB) * xC + (xB - xA) * yC + xA * yB - xB * yA);
	float beta = ((yA - yC) * x + (xC - xA) * y + xA * yC - xC * yA) / ((yA - yC) * xB + (xC - xA) * yB + xA * yC - xC * yA);
	float alpha = 1.0 - beta - gamma;
	return { alpha, beta, gamma };
}

float Tool::interpolation(float alpha, float beta, float gamma, float x, float y, float z)
{
	return alpha * x + beta * y + gamma * z;
}

MATH::Vector3f Tool::interpolation(float alpha, float beta, float gamma, MATH::Vector3f v0, MATH::Vector3f v1, MATH::Vector3f v2)
{
	return alpha * v0 + beta * v1 + gamma * v2;
}

MATH::Vector2f Tool::interpolation(float alpha, float beta, float gamma, MATH::Vector2f v0, MATH::Vector2f v1, MATH::Vector2f v2)
{
	return alpha * v0 + beta * v1 + gamma * v2;
}

