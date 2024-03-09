#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include "Enum.h"
#include "Vector3.h"

namespace MATH
{

	template<typename T>
	class Vector4
	{
	public:
		union
		{
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			struct { T data[4]; };
		};

		Vector4<T> getInvVector();
		Vector3<T> toVector3();

		T length();

		Vector4();

		explicit Vector4(const T value, VectorType type = VectorType::point);
		template<typename U>
		explicit Vector4(const U* d);
		template<typename U>
		explicit Vector4(const std::vector<U>& vec);
		template<typename U>
		Vector4(const Vector4<U>& vec);
		template<typename U>
		Vector4(const Vector4<U>* vec);

		template<typename X, typename Y, typename Z, typename W>
		Vector4(X x, Y y, Z z, W w);
		template<typename X, typename Y, typename Z>
		Vector4(X x, Y y, Z z, VectorType type = VectorType::point);

		template<typename U>
		Vector4(Vector3<U> vec3, VectorType type = VectorType::point);

		template<typename U>
		Vector4(Vector3<U> vec3, U w);
		
		template<typename U>
		Vector4<T> operator=(const Vector4<U>& vec);
		template<typename U>
		Vector4<T> operator=(const Vector4<U>* vec);
		template<typename U>
		Vector4<T> operator+(const Vector4<U>& vec);
		template<typename U>
		Vector4<T> operator-(const Vector4<U>& vec);
		template<typename U>
		Vector4<T> operator*(const Vector4<U>& vec);
		Vector4<T> operator*(const T scale);
		template<typename U>
		Vector4<T> operator/(const Vector4<U>& vec);
		Vector4<T> operator/(const T scale);
		template<typename U>
		Vector4<T> operator+=(const Vector4<U>& vec);
		template<typename U>
		Vector4<T> operator-=(const Vector4<U>& vec);
		template<typename U>
		Vector4<T> operator*=(const Vector4<U>& vec);
		Vector4<T> operator*=(const T scale);
		template<typename U>
		Vector4<T> operator/=(const Vector4<U>& vec);
		Vector4<T> operator/=(const T scale);

		T& operator[](const int i);
		const T& operator[](const int i) const;

		friend Vector4<T> operator*(const T num, const Vector4<T>& vec)
		{
			return vec * num;
		}

		friend std::ostream& operator<<(std::ostream& os, const Vector4<T>& vec)
		{
			for (int i = 0; i < 4; i++)
				os << vec.data[i] << " ";
			return os;
		}
	};

}

#include "Vector4.hpp"