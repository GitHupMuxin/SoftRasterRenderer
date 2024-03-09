#include "Mat4X4.h"
namespace MATH
{
	template<typename T>
	void Mat4X4<T>::init()
	{
		this->data.resize(4);
	}

	template<typename T>
	Mat4X4<T>::Mat4X4()
	{
		this->init();
	}

	template<typename T>
	Mat4X4<T>::Mat4X4(const T value)
	{
		this->init();
		for (int i = 0; i < 4; i++)
			this->data[i][i] = value;
	}

	template<typename T>
	template<typename U>
	Mat4X4<T>::Mat4X4(const Mat4X4<U>& mat4)
	{
		this->init();
		for (int i = 0; i < 4; i++)
			this->data[i] = mat4[i];
	}

	template<typename T>
	template<typename U>
	Mat4X4<T>::Mat4X4(const Mat4X4<U>* mat4)
	{
		this->init();
		for (int i = 0; i < 4; i++)
			this->data[i] = *(mat4)[i];
	}

	template<typename T>
	template<typename U>
	Mat4X4<T>::Mat4X4(const Mat3X3<U> mat3)
	{
		this->init();
		for (int i = 0; i < 3; i++)
		{
			Vector4<T> t(mat3[i], 0.0f);
			this->data[i] = t;
		}
		this->data[3][3] = static_cast<T>(1.0f);
	}

	template<typename T>
	template<typename U>
	Mat4X4<T>::Mat4X4(const Mat3X3<U>* mat3)
	{
		this->init();
		for (int i = 0; i < 3; i++)
			this->data[i] = Vector4<T>(*(mat3)[i], 0.0f);
		this->data[3][3] = static_cast<T>(1.0f);
	}

	template<typename T>
	template<typename X, typename Y, typename Z, typename W>
	Mat4X4<T>::Mat4X4(const Vector4<X>& vec1, const Vector4<Y>& vec2, const Vector4<Z>& vec3, const Vector4<W>& vec4)
	{
		this->init();
		this->data[0] = Vector4<T>(vec1);
		this->data[1] = Vector4<T>(vec2);
		this->data[2] = Vector4<T>(vec3);
		this->data[4] = Vector4<T>(vec4);
	}

	template<typename T>
	template<typename X, typename Y, typename Z, typename W>
	Mat4X4<T>::Mat4X4(const Vector4<X>* vec1, const Vector4<Y>* vec2, const Vector4<Z>* vec3, const Vector4<W>* vec4)
	{
		this->init();
		this->data[0] = vec1;
		this->data[1] = vec2;
		this->data[2] = vec3;
		this->data[4] = vec4;
	}

	template<typename T>
	template<typename X1, typename X2, typename X3, typename X4, 
			 typename Y1, typename Y2, typename Y3, typename Y4, 
			 typename Z1, typename Z2, typename Z3, typename Z4, 
			 typename W1, typename W2, typename W3, typename W4>
	Mat4X4<T>::Mat4X4(const X1& x1, const X2& x2, const X3& x3, const X4& x4, 
					  const Y1& y1, const Y2& y2, const Y3& y3, const Y4& y4, 
					  const Z1& z1, const Z2& z2, const Z3& z3, const Z4& z4, 
					  const W1& w1, const W2& w2, const W3& w3, const W4& w4)
	{
		init();
		Vector4<T> v0(x1, x2, x3, x4);
		Vector4<T> v1(y1, y2, y3, y4);
		Vector4<T> v2(z1, z2, z3, z4);
		Vector4<T> v3(w1, w2, w3, w4);
		this->data[0] = v0;
		this->data[1] = v1;
		this->data[2] = v2;
		this->data[3] = v3;
	}



	template<typename T>
	Mat4X4<T> Mat4X4<T>::transpose()
	{
		Mat4X4<T> result = Mat4X4<T>(1.0f);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result[i][j] = this->data[j][i];
			}
		}
		return result;
	}

	template<typename T>
	Mat4X4<T> Mat4X4<T>::getInvMatrices()
	{
		Mat4X4<T> result = Mat4X4<T>(1.0f);

		return result;
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator=(const Mat4X4<U>& mat4)
	{
		for (int i = 0; i < 4; i++)
			this->data[i] = static_cast<T>(mat4[i]);
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator+(const Mat4X4<U>& mat4)
	{
		Mat4X4<T> result = Mat4X4<T>(1.0f);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				result[i][j] += static_cast<T>(mat4[i][j]);
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator-(const Mat4X4<U>& mat4)
	{
		Mat4X4<T> result = Mat4X4<T>(1.0f);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				result[i][j] -= static_cast<T>(mat4[i][j]);
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator*(const Mat4X4<U>& mat4)
	{
		Mat4X4<T> result = Mat4X4(1.0f);
		Mat4X4<T> mat4Transpose = mat4.transpose();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				result.data[i][j] = MATH::dotProduction(*(this)[i], mat4Transpose[j]);
		}
		return result;
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator*(const U value)
	{
		Mat4X4<T> result = Mat4X4(1.0f);
		T v = static_cast<T>(value);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				result[i][j] = *(this)[i][j] * v;
		}
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator/(const Mat4X4<U>& mat4)
	{
		Mat4X4<T> result = *(this);
		Mat4X4<T> mat3Transpose = mat4.transpose();
		return result * mat3Transpose;
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator/(const U value)
	{
		Mat4X4<T> result = Mat4X4<T>(1.0f);
		T v = 1.0f / static_cast<T>(value);
		return *(this) * v;
	}


	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator+=(const Mat4X4<U>& mat4)
	{
		*(this) = *(this) + mat4;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator-=(const Mat4X4<U>& mat4)
	{
		*(this) = *(this) - mat4;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator*=(const Mat4X4<U>& mat4)
	{
		*(this) = *(this) * mat4;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator*=(const U value)
	{
		T v = static_cast<T>(value);
		*(this) = *(this) * v;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator/=(const Mat4X4<U>& mat4)
	{
		Mat4X4<T> inverse = mat4.getInvMatrices();
		*(this) = *(this) * inverse;
		return *(this);
	}

	template<typename T>
	template<typename U>
	Mat4X4<T> Mat4X4<T>::operator/=(const U value)
	{
		T v = 1.0f / static_cast<T>(value);
		*(this) = *(this) * v;
		return *(this);
	}

	template<typename T>
	Vector4<T>& Mat4X4<T>::operator[](const int i)
	{
		return this->data[i];
	}

	template<typename T>
	inline const Vector4<T>& Mat4X4<T>::operator[](const int i) const
	{
		return this->data[i];
	}

}
