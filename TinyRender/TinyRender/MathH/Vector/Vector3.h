#pragma once
#include <vector>
#include <iostream>
#include <fstream>
namespace MATH
{
	template <typename T>
	class Vector3
	{
	public:
		union 
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T data[3]; };
		};

		Vector3<T> getInvVector() const;

		T length() const;

		Vector3();

		explicit Vector3(const T value);
		template<typename U>
		explicit Vector3(const U* d);
		template<typename U>
		explicit Vector3(const std::vector<U>& vec);
		template<typename U>
		Vector3(const Vector3<U>& vec);
		template<typename U>
		Vector3(const Vector3<U>* vec);
		template<typename X, typename Y, typename Z>
		Vector3(X x, Y y, Z z);

		template<typename U>
		Vector3<T> operator=(const Vector3<U>& vec);
		template<typename U>
		Vector3<T> operator=(const Vector3<U>* vec);
		template<typename U>
		Vector3<T> operator+(const Vector3<U>& vec) const;
		template<typename U>
		Vector3<T> operator-(const Vector3<U>& vec) const;
		template<typename U>
		Vector3<T> operator*(const Vector3<U>& vec) const;
		Vector3<T> operator*(const T scale) const;
		template<typename U>
		Vector3<T> operator/(const Vector3<U>& vec) const;
		Vector3<T> operator/(const T scale) const;
		template<typename U>
		Vector3<T> operator+=(const Vector3<U>& vec);
		template<typename U>
		Vector3<T> operator-=(const Vector3<U>& vec);
		template<typename U>
		Vector3<T> operator*=(const Vector3<U>& vec);
		Vector3<T> operator*=(const T scale);
		template<typename U>
		Vector3<T> operator/=(const Vector3<U>& vec);
		Vector3<T> operator/=(const T scale);

		T& operator[](const int i);
		const T& operator[](const int i) const;

		friend Vector3<T> operator*(const T num, const Vector3<T>& vec)
		{
			T n = static_cast<T>(num);
			return Vector3<T>(vec.x * n, vec.y * n, vec.z * n);
		}

		friend std::ostream& operator<<(std::ostream& os, const Vector3<T>& vec)
		{
			for (int i = 0; i < 3; i++)
				os << vec.data[i] << " ";
			return os;
		}
	};
}

#include "Vector3.hpp"
