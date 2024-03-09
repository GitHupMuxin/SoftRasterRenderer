#include <cmath>
#include "Vector3.h"
#include <assert.h>
namespace MATH
{
	template<typename T>
	Vector3<T> Vector3<T>::getInvVector()
	{
		return Vector3<T>(1.0f / this->x, 1.0f / this->y, 1.0f / this->z);
	}

	template<typename T>
	T Vector3<T>::length()
	{
		T x = this->x;
		T y = this->y;
		T z = this->z;
		return std::sqrt(x * x + y * y + z * z);
	}

	template<typename T>
	Vector3<T>::Vector3()
	{
		T tempValue = static_cast<T>(0.0f);
		this->x = tempValue;
		this->y = tempValue;
		this->z = tempValue;
	}


	template<typename T>
	Vector3<T>::Vector3(const T value)
	{
		T tempValue = static_cast<T>(value);
		this->x = tempValue;
		this->y = tempValue;
		this->z = tempValue;
	}

	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(const U* d)
	{
		for (int i = 0; i < 3; i++)
			this->data[i] = d[i];
	}

	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(const std::vector<U>& vec)
	{
		this->x = static_cast<T>(vec[0]);
		this->y = static_cast<T>(vec[1]);
		this->z = static_cast<T>(vec[2]);
	}

	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(const Vector3<U>& vec)
	{
		this->x = static_cast<T>(vec.x);
		this->y = static_cast<T>(vec.y);
		this->z = static_cast<T>(vec.z);
	}

	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(const Vector3<U>* vec)
	{
		this->x = static_cast<T>(vec->x);
		this->y = static_cast<T>(vec->y);
		this->z = static_cast<T>(vec->z);
	}

	template<typename T>
	template<typename X, typename Y, typename Z>
	Vector3<T>::Vector3(X x, Y y, Z z)
	{
		this->x = static_cast<T>(x);
		this->y = static_cast<T>(y);
		this->z = static_cast<T>(z);
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator=(const Vector3<U>& vec)
	{
		this->x = static_cast<T>(vec.x);
		this->y = static_cast<T>(vec.y);
		this->z = static_cast<T>(vec.z);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator=(const Vector3<U>* vec)
	{
		this->x = static_cast<T>(vec->x);
		this->y = static_cast<T>(vec->y);
		this->z = static_cast<T>(vec->z);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator+(const Vector3<U>& vec)
	{
		return Vector3(this->x + static_cast<T>(vec.x), this->y + static_cast<T>(vec.y), this->z + static_cast<T>(vec.z));
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator-(const Vector3<U>& vec)
	{
		return Vector3(this->x - static_cast<T>(vec.x), this->y - static_cast<T>(vec.y), this->z - static_cast<T>(vec.z));
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator*(const Vector3<U>& vec)
	{
		return Vector3(this->x * static_cast<T>(vec.x), this->y * static_cast<T>(vec.y), this->z * static_cast<T>(vec.z));
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator*(const T scale)
	{
		return Vector3<T>(this->x * scale, this->y * scale, this->z * scale);
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator/(const Vector3<U>& vec)
	{
		Vector3<T> temp = this->getInvVector();
		return *(this) * temp;
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator/(const T scale)
	{
		T inv = 1.0f / scale;
		return *(this) * inv;
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator+=(const Vector3<U>& vec)
	{
		*(this) = *(this) + vec;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator-=(const Vector3<U>& vec)
	{
		*(this) = *(this) - vec;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator*=(const Vector3<U>& vec)
	{
		*(this) = *(this) * vec;
		return *(this);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator*=(const T scale)
	{
		this->x *= scale;
		this->y *= scale;
		this->z *= scale;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector3<T> Vector3<T>::operator/=(const Vector3<U>& vec)
	{
		*(this) = *(this) / vec.getInvVector();
		return *(this);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator/=(const T scale)
	{
		T inv = 1.0f / scale;
		return *(this) *= inv;
	}

	template<typename T>
	T& Vector3<T>::operator[](const int i)
	{
		return data[i];
	}
	template<typename T>
	const T& Vector3<T>::operator[](const int i) const
	{
		return data[i];
	}

}

