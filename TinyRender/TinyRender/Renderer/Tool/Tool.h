#pragma once
#include <tuple>
#include "../Model/Mesh.h"
#include "../../MathH/Production.h"

class Tool
{
public:
    static bool inTriangle(MATH::Vector2f point, Triangle logicTriangle);
    static std::tuple<float, float, float> computeArealCoord2D(MATH::Vector2f point, Triangle triangle);
    static float interpolation(float alpha, float beta, float gamma, float x, float y, float z);
    static MATH::Vector3f interpolation(float alpha, float beta, float gamma, MATH::Vector3f v0, MATH::Vector3f v1, MATH::Vector3f v2);
    static MATH::Vector2f interpolation(float alpha, float beta, float gamma, MATH::Vector2f v0, MATH::Vector2f v1, MATH::Vector2f v2);
};
