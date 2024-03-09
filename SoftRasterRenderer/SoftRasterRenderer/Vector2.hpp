#include "Vector2.h"
namespace MATH
{
	template<typename T>
	Vector2<T> Vector2<T>::getInvVector()
	{
		return Vector2<T>(1.0f / this->x, 1.0f / this->y);
	}

	template<typename T>
	T Vector2<T>::length()
	{
		T x = this->x;
		T y = this->y;
		return std::sqrt(x * x + y * y);
	}

	template<typename T>
	Vector2<T>::Vector2()
	{
		T tempValue = static_cast<T>(0.0f);
		this->x = tempValue;
		this->y = tempValue;
	}

	template<typename T>
	Vector2<T>::Vector2(const T value)
	{
		T tempValue = static_cast<T>(value);
		this->x = tempValue;
		this->y = tempValue;
	}

	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const U* d)
	{
		for (int i = 0; i < 2; i++)
			this->data[i] = d[i];
	}

	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const std::vector<U>& vec)
	{
		this->x = static_cast<T>(vec[0]);
		this->y = static_cast<T>(vec[1]);
	}

	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const Vector2<U>& vec)
	{
		this->x = static_cast<T>(vec.x);
		this->y = static_cast<T>(vec.y);
	}

	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const Vector2<U>* vec)
	{
		this->x = static_cast<T>(vec->x);
		this->y = static_cast<T>(vec->y);
	}

	template<typename T>
	template<typename X, typename Y>
	Vector2<T>::Vector2(X x, Y y)
	{
		this->x = static_cast<T>(x);
		this->y = static_cast<T>(y);
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator=(const Vector2<U>& vec)
	{
		this->x = static_cast<T>(vec.x);
		this->y = static_cast<T>(vec.y);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator=(const Vector2<U>* vec)
	{
		this->x = static_cast<T>(vec->x);
		this->x = static_cast<T>(vec->y);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator+(const Vector2<U>& vec)
	{
		return Vector2(this->x + static_cast<T>(vec.x), this->y + static_cast<T>(vec.y));
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator-(const Vector2<U>& vec)
	{
		return Vector2(this->x - static_cast<T>(vec.x), this->y - static_cast<T>(vec.y));
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator*(const Vector2<U>& vec)
	{
		return Vector2(this->x * static_cast<T>(vec.x), this->y * static_cast<T>(vec.y));
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator*(const T scale)
	{
		return Vector2<T>(this->x * scale, this->y * scale);
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator/(const Vector2<U>& vec)
	{
		Vector2<T> temp = this->getInvVector();
		return *(this) * temp;
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator/(const T scale)
	{
		T invScale = 1.0f / scale;
		return *(this) * scale;
	}
	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator+=(const Vector2<U>& vec)
	{
		*(this) = *(this) + vec;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator-=(const Vector2<U>& vec)
	{
		*(this) = *(this) - vec;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator*=(const Vector2<U>& vec)
	{
		*(this) = *(this) * vec;
		return *(this);
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator*=(const T scale)
	{
		this->x *= scale;
		this->y *= scale;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector2<T> Vector2<T>::operator/=(const Vector2<U>& vec)
	{
		*(this) = *(this) / vec.getInvVector();
		return *(this);
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator/=(const T scale)
	{
		T inv = 1.0f / scale;
		return *(this) *= inv;
	}

	template<typename T>
	T& Vector2<T>::operator[](const int i)
	{
		return data[i];
	}

	template<typename T>
	const T& Vector2<T>::operator[](const int i) const
	{
		return data[i];
	}

}
