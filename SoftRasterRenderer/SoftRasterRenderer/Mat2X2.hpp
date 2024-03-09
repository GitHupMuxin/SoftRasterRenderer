#include "Mat2X2.h"
namespace MATH
{
	template<typename T>
	void Mat2X2<T>::init()
	{
		this->data.resize(2);
	}

	template<typename T>
	Mat2X2<T>::Mat2X2()
	{
		this->init();
	}

	template<typename T>
	Mat2X2<T>::Mat2X2(const T value)
	{
		this->init();
		for (int i = 0; i < 2; i++)
			this->data[i][i] = value;
	}

	template<typename T>
	template<typename U>
	Mat2X2<T>::Mat2X2(const Mat2X2<U>& mat)
	{
		this->init();
		for (int i = 0; i < 2; i++)
		{
			this->data[i] = mat[i];
		}
	}

	template<typename T>
	template<typename U>
	Mat2X2<T>::Mat2X2(const Mat2X2<U>* mat)
	{
		this->init();
		for (int i = 0; i < 2; i++)
			this->data[i] = *(mat)[i];
	}

	template<typename T>
	template<typename X, typename Y>
	Mat2X2<T>::Mat2X2(const Vector2<X>& vec1, const Vector2<Y>& vec2)
	{
		this->init();
		this->data[0] = vec1;
		this->data[1] = vec2;
	}

	template<typename T>
	template<typename X, typename Y>
	Mat2X2<T>::Mat2X2(const Vector2<X>* vec1, const Vector2<Y>* vec2)
	{
		this->init();
		this->data[0] = vec1;
		this->data[1] = vec2;
	}

	template<typename T>
	Mat2X2<T> Mat2X2<T>::transpose()
	{
		Mat2X2<T> result = Mat2X2<T>(1.0f);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				result[i][j] = this->data[j][i];
			}
		}
		return result;
	}

	template<typename T>
	Mat2X2<T> Mat2X2<T>::inverse()
	{

	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator=(const Mat2X2<U>& mat)
	{
		for (int i = 0; i < 2; i++)
			this->data[i] = mat[i];
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator+(const Mat2X2<U>& mat)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				this->data[i][j] = mat[i][j];
		}
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator-(const Mat2X2<U>& mat)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				this->data[i][j] = mat[i][j];
		}
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator*(const Mat2X2<U>& mat)
	{
		Mat2X2<T> result = Mat2X2<T>(1.0f);
		Mat2X2<T> transpose = mat.transpose();
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				result[i][j] = MATH::dotProduction(this->data[i], mat[j]);
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator*(const U value)
	{
		T v = static_cast<T>(value);
		Mat2X2<T> result = *(this);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				result[i][j] *= value;
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator/(const Mat2X2<U>& mat)
	{
		Mat2X2<T> inverse = mat.inverse();
		return *(this) * inverse;
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator/(const U value)
	{
		T v = 1.0f / static_cast<T>(value);
		return *(this) * v;
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator+=(const Mat2X2<U>& mat)
	{
		*(this) = *(this) + mat;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator-=(const Mat2X2<U>& mat)
	{
		*(this) = *(this) - mat;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator*=(const Mat2X2<U>& mat)
	{
		*(this) = *(this) * mat;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator*=(const U value)
	{
		*(this) = *(this) * value;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator/=(const Mat2X2<U>& mat)
	{
		*(this) = *(this) / mat;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat2X2<T> Mat2X2<T>::operator/=(const U value)
	{
		*(this) = *(this) / value;
		return *(this);
	}

	template<typename T>
	inline const Vector2<T>& Mat2X2<T>::operator[](const int i) const
	{
		return this->data[i];
	}

	template<typename T>
	Vector2<T>& Mat2X2<T>::operator[](const int i)
	{
		return this->data[i];
	}
}

