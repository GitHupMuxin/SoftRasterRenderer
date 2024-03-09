#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <iostream>

namespace MATH
{
	template<typename T>
	static Vector2<T> normalize(Vector2<T> vec)
	{
		return vec / vec.length();
	}

	template<typename T>
	static float dotProduction(Vector2<T> vec1, Vector2<T> vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}

	template<typename T>
	static Vector3<T> normalize(Vector3<T> vec)
	{
		return vec / vec.length();
	}

	template<typename T>
	static float dotProduction(Vector3<T> vec1, Vector3<T> vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}

	template<typename T>
	static Vector3<T> crossProduction(Vector3<T> vec1, Vector3<T> vec2)
	{
		Vector3<T> result = Vector3<T>(1.0f);
		result.x = vec1.y * vec2.z - vec1.z * vec2.y;
		result.y = vec1.z * vec2.x - vec1.x * vec2.z;
		result.z = vec1.x * vec2.y - vec1.y * vec2.x;
		return result;
	}

	template<typename T>
	static float dotProduction(Vector4<T> vec1, Vector4<T> vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
	}

	template<typename T>
	static Vector4<T> normalize(Vector4<T> vec)
	{
		return vec / vec.length();
	}

}

#include "Define.h"


namespace MATH
{
	template<typename T, typename U>
	static Vector2<T> multiple(Mat2X2<U> mat2, Vector2<T> vec2)
	{
		Vector2<T> result(1.0f);
		Mat2X2<T> m = Mat2X2<T>(mat2);
		for (int i = 0; i < 2; i++)
			result[i] = dotProduction(m[i], vec2);
		return result;
	}

	template<typename T, typename U>
	static Vector3<T> multiple(Mat3X3<U> mat3, Vector3<T> vec3)
	{
		Vector3<T> result(1.0f);
		Mat3X3<T> m = Mat3X3<T>(mat3);
		for (int i = 0; i < 3; i++)
			result[i] = dotProduction(m[i], vec3);
		return result;
	}

	template<typename T, typename U>
	static Vector4<T> multiple(Mat4X4<U> mat4, Vector4<T> vec4)
	{
		Vector4<T> result(1.0f);
		Mat4X4<T> m = Mat4X4<T>(mat4);
		for (int i = 0; i < 4; i++)
			result[i] = dotProduction(m[i], vec4);
		return result;
	}

	template<typename T, typename U>
	static Mat2X2<T> multiple(Mat2X2<T> mat1, Mat2X2<U> mat2)
	{
		Mat2X2<T> result(1.0f);
		Mat2X2<T> m = Mat2X2<T>(mat2).transpose();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				result[i][j] = MATH::dotProduction(mat1[i], m[j]);
		return result;
	}

	template<typename T, typename U>
	static Mat3X3<T> multiple(Mat3X3<T> mat1, Mat3X3<U> mat2)
	{
		Mat3X3<T> result(1.0f);
		Mat3X3<T> m = Mat3X3<T>(mat2).transpose();
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				result[i][j] = MATH::dotProduction(mat1[i], m[j]);
		return result;
	}

	template<typename T, typename U>
	static Mat4X4<T> multiple(Mat4X4<T> mat1, Mat4X4<U> mat2)
	{
		Mat4X4<T> result(1.0f);
		Mat4X4<T> m = Mat4X4<T>(mat2).transpose();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				result[i][j] = MATH::dotProduction(mat1[i], m[j]);
		return result;
	}
}