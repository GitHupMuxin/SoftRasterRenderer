#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Production.h"

namespace MATH
{
	template<typename T>
	class Mat3X3
	{
	public:
		std::vector<Vector3<T>> data;
		void init();

		Mat3X3();

		Mat3X3(const T value);

		template<typename U>
		Mat3X3(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3(const Mat3X3<U>* mat3);

		template<typename X, typename Y, typename Z>
		Mat3X3(const Vector3<X>& vec1, const Vector3<Y>& vec2, const Vector3<Z>& vec3);

		template<typename X, typename Y, typename Z>
		Mat3X3(const Vector3<X>* vec1, const Vector3<Y>* vec2, const Vector3<Z>* vec3);

		Mat3X3<T> transpose();

		Mat3X3<T> getInvMatrices();

		template<typename U>
		Mat3X3<T> operator=(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator+(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator-(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator*(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator*(const U value);

		template<typename U>
		Mat3X3<T> operator/(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator/(const U value);

		template<typename U>
		Mat3X3<T> operator+=(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator-=(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator*=(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator*=(const U value);

		template<typename U>
		Mat3X3<T> operator/=(const Mat3X3<U>& mat3);

		template<typename U>
		Mat3X3<T> operator/=(const U value);

		Vector3<T>& operator[](const int i);

		const Vector3<T>& operator[](const int i) const;

		friend std::ostream& operator<<(std::ostream& os, const Mat3X3<T>& mat)
		{
			for (int i = 0; i < 3; i++)
				os << mat.data[i] << "\n";
			return os;
		}
	};

}

#include "Mat3X3.hpp"





