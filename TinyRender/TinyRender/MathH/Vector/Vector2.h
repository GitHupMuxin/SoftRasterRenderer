#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
namespace MATH
{
	template<typename T>
	class Vector2
	{
	public:
		union
		{
			struct { T x, y; };
			struct { T r, g; };
			struct { T data[2]; };
		};

		Vector2<T> getInvVector() const;

		T length() const;

		Vector2();

		explicit Vector2(const T value);
		template<typename U>
		explicit Vector2(const U* d);
		template<typename U>
		explicit Vector2(const std::vector<U>& vec);
		template<typename U>
		Vector2(const Vector2<U>& vec);
		template<typename U>
		Vector2(const Vector2<U>* vec);
		template<typename X, typename Y>
		Vector2(X x, Y y);

		template<typename U>
		Vector2<T> operator=(const Vector2<U>& vec);
		template<typename U>
		Vector2<T> operator=(const Vector2<U>* vec);
		template<typename U>
		Vector2<T> operator+(const Vector2<U>& vec) const;
		template<typename U>
		Vector2<T> operator-(const Vector2<U>& vec) const;
		template<typename U>
		Vector2<T> operator*(const Vector2<U>& vec) const;
		Vector2<T> operator*(const T scale) const;
		template<typename U>
		Vector2<T> operator/(const Vector2<U>& vec) const;
		Vector2<T> operator/(const T scale) const;
		template<typename U>
		Vector2<T> operator+=(const Vector2<U>& vec);
		template<typename U>
		Vector2<T> operator-=(const Vector2<U>& vec);
		template<typename U>
		Vector2<T> operator*=(const Vector2<U>& vec);
		Vector2<T> operator*=(const T scale);
		template<typename U>
		Vector2<T> operator/=(const Vector2<U>& vec);
		Vector2<T> operator/=(const T scale);

		T& operator[](const int i);
		const T& operator[](const int i) const;

		friend Vector2<T> operator*(const T num, const Vector2<T>& vec)
		{
			T n = static_cast<T>(num);
			return Vector2<T>(vec.x * n, vec.y * n);
		}

		friend std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec)
		{
			for (int i = 0; i < 2; i++)
				os << vec.data[i] << " ";
			return os;
		}
	};

}

#include "Vector2.hpp"


