#pragma once
#include <functional>
#include <iostream>
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

namespace MATH
{
	template<typename T>
	static Vector2<T> normalize(const Vector2<T> vec)
	{
		return vec / vec.length();
	}

	template<typename T>
	static float dotProduction(const Vector2<T> vec1, const Vector2<T> vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}

	template<typename T>
	static Vector3<T> normalize(const Vector3<T> vec)
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
	static Vector2<T> multiple(const Mat2X2<U>& mat2, const Vector2<T>& vec2)
	{
		Vector2<T> result(1.0f);
		Mat2X2<T> m = Mat2X2<T>(mat2);
		for (int i = 0; i < 2; i++)
			result[i] = dotProduction(m[i], vec2);
		return result;
	}

	template<typename T, typename U>
	static Vector3<T> multiple(const Mat3X3<U>& mat3, const Vector3<T>& vec3)
	{
		Vector3<T> result(1.0f);
		Mat3X3<T> m = Mat3X3<T>(mat3);
		for (int i = 0; i < 3; i++)
			result[i] = dotProduction(m[i], vec3);
		return result;
	}

	template<typename T, typename U>
	static Vector4<T> multiple(const Mat4X4<U>& mat4, const Vector4<T>& vec4)
	{
		Vector4<T> result(1.0f);
		Mat4X4<T> m = Mat4X4<T>(mat4);
		for (int i = 0; i < 4; i++)
			result[i] = dotProduction(m[i], vec4);
		return result;
	}

	template<typename T, typename U>
	static Mat2X2<T> multiple(const Mat2X2<T>& mat1, const Mat2X2<U>& mat2)
	{
		Mat2X2<T> result(1.0f);
		Mat2X2<T> m = Mat2X2<T>(transpose(mat2));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				result[i][j] = MATH::dotProduction(mat1[i], m[j]);
		return result;
	}

	template<typename T, typename U>
	static Mat3X3<T> multiple(const Mat3X3<T>& mat1, const Mat3X3<U>& mat2)
	{
		Mat3X3<T> result(1.0f);
		Mat3X3<T> m = Mat3X3<T>(transpose(mat2));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				result[i][j] = MATH::dotProduction(mat1[i], m[j]);
		return result;
	}

	template<typename T, typename U>
	static Mat4X4<T> multiple(const Mat4X4<T>& mat1, const Mat4X4<U>& mat2)
	{
		Mat4X4<T> result(1.0f);
		Mat4X4<T> m = Mat4X4<T>(transpose(mat2));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				result[i][j] = MATH::dotProduction(mat1[i], m[j]);
		return result;
	}

	template<typename T>
	static Mat2X2<T> transpose(const Mat2X2<T>& mat)
	{
		Mat2X2<T> result = Mat2X2<T>(1.0f);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				result[i][j] = mat.data[j][i];
		return result;
	}

	template<typename T>
	static Mat3X3<T> transpose(const Mat3X3<T>& mat)
	{
		Mat3X3<T> result = Mat3X3<T>(1.0f);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				result[i][j] = mat.data[j][i];
		return result;
	}

	template<typename T>
	static Mat4X4<T> transpose(const Mat4X4<T>& mat)
	{
		Mat4X4<T> result = Mat4X4<T>(1.0f);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				result[i][j] = mat.data[j][i];
		return result;
	}

	template<typename T>
	static Mat2X2<T> InverseMatrix(const Mat2X2<T>& mat)
	{
		Mat2X2<T> result;
		result[0][0] = mat[1][1];
		result[0][1] = -mat[0][1];
		result[1][0] = -mat[1][0];
		result[1][1] = mat[0][0];
		T getDetereminant = mat.detereminant();
		return result / getDetereminant;
	}

	template<typename T>
	static Mat3X3<T> InverseMatrix(const Mat3X3<T>& mat)
	{
		Mat3X3<T> temp = mat;
		std::function<Mat2X2<T>(int, int, Mat3X3<T>)> func = [&](int x, int y, Mat3X3<T> mat3) -> Mat2X2<T>
		{
			Mat2X2<T> result;
			int baseX = 0, baseY = 0;
			for (int i = 0; i < 3; i++)
			{
				if (i == x)
					continue;
				for (int j = 0; j < 3; j++)
				{
					if (j == y)
						continue;
					result[baseX][baseY++] = mat3[i][j];
				}
				baseX++;
			}
		};
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp[i][j] = func(i, j, mat).detereminant();
		transpose(temp);
		return temp / mat.detereminant();
	}

	template<typename T>
	static Mat4X4<T> InverseMatrix(const Mat4X4<T>& mat)
	{
		Mat4X4<T> temp = mat;
		std::function<Mat3X3<T>(int, int, const Mat4X4<T>&)> func = [&](int x, int y, const Mat4X4<T>& mat3) -> Mat3X3<T>
		{
			Mat3X3<T> result;
			int baseX = 0, baseY = 0;
			for (int i = 0; i < 4; i++)
			{
				if (i == x)
					continue;
				for (int j = 0, baseY = 0; j < 4; j++)
				{
					if (j == y)
						continue;
					result[baseX][baseY++] = mat3[i][j];
				}
				baseX++;
			}
			return result;
		};
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				temp[i][j] = func(i, j, mat).detereminant();
		transpose(temp);
		return temp / mat.detereminant();
	}
}