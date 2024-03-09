#include "Vector4.h"
namespace MATH
{
	template<typename T>
	Vector4<T> Vector4<T>::getInvVector() const
	{
		return Vector4(1.0f / this->x, 1.0f / this->y, 1.0f / this->z, 1.0f / this->w);
	}

	template<typename T>
	Vector3<T> Vector4<T>::toVector3() const
	{
		Vector3<T> result;
		if (this->data[3])
		{
			float inv = 1.0f / this->data[3];
			for (int i = 0; i < 3; i++)
				result[i] = this->data[i] * inv;
		}
		else
			for (int i = 0; i < 3; i++)
				result.data[i] = this->data[i];
		return result;
	}

	template<typename T>
	T Vector4<T>::length() const
	{
		T result = 0;
		for (int i = 0; i < 4; i++)
		{
			T temp = this;
			result += temp * temp;
		}
		return std::sqrt(result);
	}

	template<typename T>
	Vector4<T>::Vector4()
	{
		T v = static_cast<T>(0.0f);
		this->x = v;
		this->y = v;
		this->z = v;
		this->w = v;
	}

	template<typename T>
	Vector4<T>::Vector4(const T value, VectorType type)
	{
		T v = static_cast<T>(value);
		this->x = v;
		this->y = v;
		this->z = v;
		if (type == VectorType::point)
			this->w = static_cast<T>(1.0f);
		else if (type == VectorType::vector)
			this->w = static_cast<T>(0.0f);
	}

	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(const U* d)
	{
		for (int i = 0; i < 4; i++)
			this->data[i] = d[i];
	}

	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(const std::vector<U>& vec)
	{
		this->x = static_cast<U>(vec[0]);
		this->y = static_cast<U>(vec[1]);
		this->z = static_cast<U>(vec[2]);
		this->w = static_cast<U>(vec[3]);
	}

	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(const Vector4<U>& vec)
	{
		this->x = static_cast<T>(vec.x);
		this->y = static_cast<T>(vec.y);
		this->z = static_cast<T>(vec.z);
		this->w = static_cast<T>(vec.w);
	}

	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(const Vector4<U>* vec)
	{
		this->x = static_cast<T>(vec->x);
		this->y = static_cast<T>(vec->y);
		this->z = static_cast<T>(vec->z);
		this->w = static_cast<T>(vec->w);
	}

	template<typename T>
	template<typename X, typename Y, typename Z, typename W>
	Vector4<T>::Vector4(X x, Y y, Z z, W w)
	{
		this->x = static_cast<T>(x);
		this->y = static_cast<T>(y);
		this->z = static_cast<T>(z);
		this->w = static_cast<T>(w);
	}

	template<typename T>
	template<typename X, typename Y, typename Z>
	Vector4<T>::Vector4(X x, Y y, Z z, VectorType type)
	{
		this->x = static_cast<T>(x);
		this->y = static_cast<T>(y);
		this->z = static_cast<T>(z);
		if (type == VectorType::point)
			this->w = static_cast<T>(1.0f);
		else if (type == VectorType::vector)
			this->w = static_cast<T>(1.0f);
	}

	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(Vector3<U> vec3, VectorType type)
	{
		this->x = static_cast<T>(vec3.x);
		this->y = static_cast<T>(vec3.y);
		this->z = static_cast<T>(vec3.z);
		switch (type)
		{
		case VectorType::point:
			this->w = 1.0f; break;
		case VectorType::vector:
			this->w = 0.0f; break;
		default:
			break;
		}
	}

	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(Vector3<U> vec3, U w)
	{
		this->x = static_cast<T>(vec3.x);
		this->y = static_cast<T>(vec3.y);
		this->z = static_cast<T>(vec3.z);
		this->w = static_cast<T>(w);
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator=(const Vector4<U>& vec)
	{
		this->x = static_cast<T>(vec.x);
		this->y = static_cast<T>(vec.y);
		this->z = static_cast<T>(vec.z);
		this->w = static_cast<T>(vec.w);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator=(const Vector4<U>* vec)
	{
		this->x = static_cast<T>(vec->x);
		this->y = static_cast<T>(vec->y);
		this->z = static_cast<T>(vec->z);
		this->w = static_cast<T>(vec->w);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator+(const Vector4<U>& vec) const
	{
		Vector4<T> result = Vector4<T>(0.0f);
		result.x = this->x + vec.x;
		result.y = this->y + vec.y;
		result.z = this->z + vec.z;
		result.w = this->w + vec.w;
		return result;
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator-(const Vector4<U>& vec) const
	{
		Vector4<T> result = Vector4<T>(0.0f);
		result.x = this->x - vec.x;
		result.y = this->y - vec.y;
		result.z = this->z - vec.z;
		result.w = this->w - vec.w;
		return result;
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator*(const Vector4<U>& vec) const
	{
		Vector4<T> result = Vector4<T>(0.0f);
		result.x = this->x * vec.x;
		result.y = this->y * vec.y;
		result.z = this->z * vec.z;
		result.w = this->w * vec.w;
		return result;
	}

	template<typename T>
	Vector4<T> Vector4<T>::operator*(const T scale) const
	{
		Vector4<T> result = Vector4<T>(0.0f);
		result.x = this->x * scale;
		result.y = this->y * scale;
		result.z = this->z * scale;
		result.w = this->w * scale;
		return result;
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator/(const Vector4<U>& vec) const
	{
		Vector4<T> result = Vector4<T>(0.0f);
		result.x = this->x / vec.x;
		result.y = this->y / vec.y;
		result.z = this->z / vec.z;
		result.w = this->w / vec.w;
		return result;
	}

	template<typename T>
	Vector4<T> Vector4<T>::operator/(const T scale) const
	{
		T inv = 1.0f / scale;
		return *(this) * inv;
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator+=(const Vector4<U>& vec)
	{
		*(this) = *(this) + vec;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator-=(const Vector4<U>& vec)
	{
		*(this) = *(this) - vec;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator*=(const Vector4<U>& vec)
	{
		*(this) = *(this) * vec;
		return *(this);
	}

	template<typename T>
	Vector4<T> Vector4<T>::operator*=(const T scale)
	{
		*(this) = *(this) * scale;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Vector4<T> Vector4<T>::operator/=(const Vector4<U>& vec)
	{
		*(this) = *(this) / vec;
		return *(this);
	}

	template<typename T>
	Vector4<T> Vector4<T>::operator/=(const T scale)
	{
		T inv = 1.0f / scale;
		*(this) = *(this) / inv;
		return *(this);
	}

	template<typename T>
	T& Vector4<T>::operator[](const int i)
	{
		return data[i];
	}
	template<typename T>
	const T& Vector4<T>::operator[](const int i) const
	{
		return data[i];
	}
}

