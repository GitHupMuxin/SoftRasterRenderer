#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Production.h"

namespace MATH
{
	template<typename T>
	class Mat2X2
	{
	public:
		std::vector<Vector2<T>> data;
		void init();

		Mat2X2();

		Mat2X2(const T value);

		template<typename U>
		Mat2X2(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2(const Mat2X2<U>* mat);

		template<typename X, typename Y>
		Mat2X2(const Vector2<X>& vec1, const Vector2<Y>& vec2);

		template<typename X, typename Y>
		Mat2X2(const Vector2<X>* vec1, const Vector2<Y>* vec2);

		Mat2X2<T> transpose();

		Mat2X2<T> inverse();

		template<typename U>
		Mat2X2<T> operator=(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator+(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator-(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator*(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator*(const U value);

		template<typename U>
		Mat2X2<T> operator/(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator/(const U value);

		template<typename U>
		Mat2X2<T> operator+=(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator-=(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator*=(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator*=(const U value);

		template<typename U>
		Mat2X2<T> operator/=(const Mat2X2<U>& mat);

		template<typename U>
		Mat2X2<T> operator/=(const U value);

		Vector2<T>& operator[](const int i);

		const Vector2<T>& operator[](const int i) const;

		friend std::ostream& operator<<(std::ostream& os, const Mat2X2<T>& mat)
		{
			for (int i = 0; i < 2; i++)
				os << mat.data[i] << "\n";
			return os;
		}
	};
}

#include "Mat2X2.hpp"
