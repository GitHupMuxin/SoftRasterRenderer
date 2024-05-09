#include "Mat3X3.h"
namespace MATH
{
	template<typename T>
	void Mat3X3<T>::init()
	{
		this->data.resize(3);
	}

	template<typename T>
	Mat3X3<T>::Mat3X3()
	{
		this->init();
	}

	template<typename T>
	Mat3X3<T>::Mat3X3(const T value)
	{
		this->init();
		for (int i = 0; i < 3; i++)
			this->data[i][i] = value;
	}

	template<typename T>
	template<typename U>
	Mat3X3<T>::Mat3X3(const Mat3X3<U>& mat3)
	{
		this->init();
		for (int i = 0; i < 3; i++)
			this->data[i] = mat3[i];
	}

	template<typename T>
	template<typename U>
	Mat3X3<T>::Mat3X3(const Mat3X3<U>* mat3)
	{
		this->init();
		for (int i = 0; i < 3; i++)
			this->data[i] = *(mat3)[i];
	}

	template<typename T>
	template<typename X, typename Y, typename Z>
	Mat3X3<T>::Mat3X3(const Vector3<X>& vec1, const Vector3<Y>& vec2, const Vector3<Z>& vec3)
	{
		this->init();
		this->data[0] = vec1;
		this->data[1] = vec2;
		this->data[2] = vec3;
	}

	template<typename T>
	template<typename X, typename Y, typename Z>
	Mat3X3<T>::Mat3X3(const Vector3<X>* vec1, const Vector3<Y>* vec2, const Vector3<Z>* vec3)
	{
		this->init();
		this->data[0] = vec1;
		this->data[1] = vec2;
		this->data[2] = vec3;
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator=(const Mat3X3<U>& mat3)
	{
		for (int i = 0; i < 3; i++)
			this->data[i] = static_cast<T>(mat3[i]);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator+(const Mat3X3<U>& mat3) const
	{
		Mat3X3<T> result = Mat3X3<T>(1.0f);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				result[i][j] += static_cast<T>(mat3[i][j]);
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator-(const Mat3X3<U>& mat3) const
	{
		Mat3X3<T> result = Mat3X3<T>(1.0f);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				result[i][j] -= static_cast<T>(mat3[i][j]);
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator*(const Mat3X3<U>& mat3) const
	{
		Mat3X3<T> result = Mat3X3(1.0f);
		Mat3X3<T> mat3Transpose = mat3.transpose();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				result[i][j] = MATH::dotProduction(this->data[i], mat3Transpose[j]);
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator*(const U value) const
	{
		Mat3X3<T> result = Mat3X3(1.0f);
		T v = static_cast<T>(value);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				result[i][j] = *(this)[i][j] * v;
		}
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator/(const Mat3X3<U>& mat3) const
	{
		Mat3X3<T> result = *(this);
		Mat3X3<T> mat3Transpose = mat3.transpose();
		return result * mat3Transpose;
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator/(const U value) const
	{
		Mat3X3<T> result = Mat3X3<T>(1.0f);
		T v = 1.0f / static_cast<T>(value);
		return *(this) * v;
	}


	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator+=(const Mat3X3<U>& mat3)
	{
		*(this) = *(this) + mat3;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator-=(const Mat3X3<U>& mat3)
	{
		*(this) = *(this) - mat3;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator*=(const Mat3X3<U>& mat3)
	{
		*(this) = *(this) * mat3;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator*=(const U value)
	{
		T v = static_cast<T>(value);
		*(this) = *(this) * v;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator/=(const Mat3X3<U>& mat3)
	{
		Mat3X3<T> inverse = mat3.getInvMatrices();
		*(this) = *(this) * inverse;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat3X3<T> Mat3X3<T>::operator/=(const U value)
	{
		T v = 1.0f / static_cast<T>(value);
		*(this) = *(this) * v;
		return *(this);
	}

	template<typename T>
	T Mat3X3<T>::detereminant() const
	{
		for (int i = 0; i < 3; i++)
			if (!this->data[i][i])
				return static_cast<T>(0.0f);
		Mat3X3<T> temp = *(this);
		T help = temp[1][0] / temp[0][0];
		temp[1] -= temp[0] * help;
		help = temp[2][0] / temp[0][0];
		temp[2] -= temp[0] * help;
		help = temp[2][1] / temp[1][1];
		temp[2] -= temp[1] * help;
		return temp[0][0] * temp[1][1] * temp[2][2];
	}

	template<typename T>
	const Vector3<T>& Mat3X3<T>::operator[](const int i) const
	{
		return this->data[i];
	}

	template<typename T>
	Vector3<T>& Mat3X3<T>::operator[](const int i)
	{
		return this->data[i];
	}

}
