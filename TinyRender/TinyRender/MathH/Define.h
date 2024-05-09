#pragma once
#include <iostream>
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"
#include "Mat/Mat2X2.h"
#include "Mat/Mat3X3.h"
#include "Mat/Mat4X4.h"

namespace MATH
{
	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;

	typedef Vector3<unsigned char> Vector3uc;
	typedef Vector3<int> Vector3i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;

	typedef Vector4<int> Vector4i;
	typedef Vector4<float> Vector4f;
	typedef Vector4<double> Vector4d;

	typedef Mat2X2<int> Mat2x2i;
	typedef Mat2X2<float> Mat2x2f;
	typedef Mat2X2<double> Mat2x2d;

	typedef Mat3X3<int> Mat3x3i;
	typedef Mat3X3<float> Mat3x3f;
	typedef Mat3X3<double> Mat3x3d;

	typedef Mat4X4<int> Mat4x4i;
	typedef Mat4X4<float> Mat4X4f;
	typedef Mat4X4<double> Mat4X4d;
}

