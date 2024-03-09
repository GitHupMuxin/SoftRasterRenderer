#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Production.h"

namespace MATH
{
	template<typename T>
	class Mat4X4
	{
	public:
		std::vector<Vector4<T>> data;
		void init();

		Mat4X4();

		Mat4X4(const T value);

		template<typename U>
		Mat4X4(const Mat4X4<U>& mat4);

		template<typename U>
		Mat4X4(const Mat4X4<U>* mat4);

		template<typename U>
		Mat4X4(const Mat3X3<U> mat3);

		template<typename U>
		Mat4X4(const Mat3X3<U>* mat3);

		template<typename X, typename Y, typename Z, typename W>
		Mat4X4(const Vector4<X>& vec1, const Vector4<Y>& vec2, const Vector4<Z>& vec3, const Vector4<W>& vec4);

		template<typename X, typename Y, typename Z, typename W>
		Mat4X4(const Vector4<X>* vec1, const Vector4<Y>* vec2, const Vector4<Z>* vec3, const Vector4<W>* vec4);

		template<typename X1, typename X2, typename X3, typename X4,
				 typename Y1, typename Y2, typename Y3, typename Y4,
				 typename Z1, typename Z2, typename Z3, typename Z4,
				 typename W1, typename W2, typename W3, typename W4>
		Mat4X4( const X1& x1, const X2& x2, const X3& x3, const X4& x4,
				const Y1& y1, const Y2& y2, const Y3& y3, const Y4& y4,
				const Z1& z1, const Z2& z2, const Z3& z3, const Z4& z4,
				const W1& w1, const W2& w2, const W3& w3, const W4& w4
		);

		template<typename U>
		Mat4X4<T> operator=(const Mat4X4<U>& mat4);

		template<typename U>
		Mat4X4<T> operator+(const Mat4X4<U>& mat4) const;

		template<typename U>
		Mat4X4<T> operator-(const Mat4X4<U>& mat4) const;

		template<typename U>
		Mat4X4<T> operator*(const Mat4X4<U>& mat4) const;

		template<typename U>
		Mat4X4<T> operator*(const U value) const;

		template<typename U>
		Mat4X4<T> operator/(const Mat4X4<U>& mat4) const;

		template<typename U>
		Mat4X4<T> operator/(const U value) const;

		template<typename U>
		Mat4X4<T> operator+=(const Mat4X4<U>& mat4);

		template<typename U>
		Mat4X4<T> operator-=(const Mat4X4<U>& mat4);

		template<typename U>
		Mat4X4<T> operator*=(const Mat4X4<U>& mat4);

		template<typename U>
		Mat4X4<T> operator*=(const U value);

		template<typename U>
		Mat4X4<T> operator/=(const Mat4X4<U>& mat4);

		template<typename U>
		Mat4X4<T> operator/=(const U value);

		Vector4<T>& operator[](const int i);

		const Vector4<T>& operator[](const int i) const;

		T detereminant() const;

		friend std::ostream& operator<<(std::ostream& os, const Mat4X4<T>& mat)
		{
			for (int i = 0; i < 4; i++)
				os << mat.data[i] << "\n";
			return os;
		}
	};

}

#include "Mat4X4.hpp"