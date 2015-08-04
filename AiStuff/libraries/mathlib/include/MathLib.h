// MathLib.h
#ifndef MATHLIB_H
#define MATHLIB_H


#if MATHDLLEXPORT
#define MATHDLLAPI _declspec(dllexport)
#else
#define MATHDLLAPI _declspec(dllimport)
#endif

#include <cmath>
#include <iostream>
using namespace std;


namespace MathLib 
{
	class Vector2
	{
	public:
		MATHDLLAPI Vector2();
		MATHDLLAPI Vector2(float a, float b);
		MATHDLLAPI Vector2(const Vector2 &rhs);

		MATHDLLAPI float Magnatude();
		MATHDLLAPI float SqrMagnatude();

		MATHDLLAPI void Normalise();
		MATHDLLAPI Vector2 Normalised();

		MATHDLLAPI float Dot(const Vector2 &a);
		MATHDLLAPI Vector2 Perpendicular();

		MATHDLLAPI float AngleOf();
		MATHDLLAPI float AngleBetween(const Vector2 &a);

		MATHDLLAPI Vector2 operator+(const Vector2 &rhs)const;
		MATHDLLAPI Vector2 operator-(const Vector2 &rhs)const;
		MATHDLLAPI void operator+=(const Vector2 &rhs);
		MATHDLLAPI void operator-=(const Vector2 &rhs);

		MATHDLLAPI Vector2 operator*(float rhs)const;
		MATHDLLAPI void operator*=(float rhs);

		MATHDLLAPI float& operator[](const int index);

		MATHDLLAPI Vector2 operator/(float rhs)const;
		MATHDLLAPI void operator/=(float rhs);

		MATHDLLAPI bool operator>(const Vector2 &rhs);
		MATHDLLAPI bool operator<(const Vector2 &rhs);

		MATHDLLAPI void operator=(const Vector2 &rhs);
		MATHDLLAPI bool operator==(const Vector2 &rhs)const;
		MATHDLLAPI bool operator!=(const Vector2 &rhs)const;

		friend MATHDLLAPI Vector2 operator*(float lhs, const Vector2 &rhs)
		{
			return rhs * lhs;
		}
		friend MATHDLLAPI void operator*=(float lhs, Vector2 &rhs)
		{
			rhs *= lhs;
		}

		MATHDLLAPI ~Vector2();

		float x;
		float y;
	};

	class Vector3
	{
	public:
		MATHDLLAPI Vector3();
		MATHDLLAPI Vector3(float a, float b, float c);
		MATHDLLAPI Vector3(const Vector3 &rhs);

		MATHDLLAPI float Magnatude();
		MATHDLLAPI float SqrMagnatude();

		MATHDLLAPI void Normalise();
		MATHDLLAPI Vector3 Normalised();

		MATHDLLAPI float Dot(const Vector3 &a);
		MATHDLLAPI Vector3 Cross(const Vector3 &a);

		MATHDLLAPI float AngleBetween(const Vector3 &a);

		MATHDLLAPI Vector3 operator+(const Vector3 &rhs)const;
		MATHDLLAPI Vector3 operator-(const Vector3 &rhs)const;
		MATHDLLAPI void operator+=(const Vector3 &rhs);
		MATHDLLAPI void operator-=(const Vector3 &rhs);

		MATHDLLAPI Vector3 operator*(float rhs)const;
		MATHDLLAPI void operator*=(float rhs);

		MATHDLLAPI Vector3 operator/(float rhs)const;
		MATHDLLAPI void operator/=(float rhs);

		MATHDLLAPI bool operator>(const Vector3 &rhs);
		MATHDLLAPI bool operator<(const Vector3 &rhs);

		MATHDLLAPI void operator=(const Vector3 &rhs);
		MATHDLLAPI bool operator==(const Vector3 &rhs)const;
		MATHDLLAPI bool operator!=(const Vector3 &rhs)const;

		MATHDLLAPI float& operator[](const int index);

		friend MATHDLLAPI Vector3 operator*(float lhs, const Vector3 &rhs)
		{
			return rhs * lhs;
		}
		friend MATHDLLAPI void operator*=(float lhs, Vector3 &rhs)
		{
			rhs *= lhs;
		}

		MATHDLLAPI ~Vector3();

		float x;
		float y;
		float z;
	};

	class Vector4
	{
	public:
		MATHDLLAPI Vector4();
		MATHDLLAPI Vector4(float a, float b, float c, float d);
		MATHDLLAPI Vector4(const Vector4 &rhs);

		MATHDLLAPI float Magnatude();
		MATHDLLAPI float SqrMagnatude();

		MATHDLLAPI void Normalise();
		MATHDLLAPI Vector4 Normalised();

		MATHDLLAPI float Dot(const Vector4 &a);
		MATHDLLAPI Vector4 Cross(const Vector4 &a);

		MATHDLLAPI float AngleBetween(const Vector4 &a);

		MATHDLLAPI Vector4 operator+(const Vector4 &rhs)const;
		MATHDLLAPI Vector4 operator-(const Vector4 &rhs)const;
		MATHDLLAPI void operator+=(const Vector4 &rhs);
		MATHDLLAPI void operator-=(const Vector4 &rhs);

		MATHDLLAPI Vector4 operator*(float rhs)const;
		MATHDLLAPI void operator*=(float rhs);

		MATHDLLAPI Vector4 operator/(float rhs)const;
		MATHDLLAPI void operator/=(float rhs);

		MATHDLLAPI bool operator>(const Vector4 &rhs);
		MATHDLLAPI bool operator<(const Vector4 &rhs);

		MATHDLLAPI void operator=(const Vector4 &rhs);
		MATHDLLAPI bool operator==(const Vector4 &rhs)const;
		MATHDLLAPI bool operator!=(const Vector4 &rhs)const;

		MATHDLLAPI float& operator[](const int index);

		friend MATHDLLAPI Vector4 operator*(float lhs, const Vector4 &rhs)
		{
			return rhs * lhs;
		}
		friend MATHDLLAPI void operator*=(float lhs, Vector4 &rhs)
		{
			rhs *= lhs;
		}

		MATHDLLAPI ~Vector4();

		float x;
		float y;
		float z;
		float w;
	};

	class Matrix2x2
	{
	public:
		MATHDLLAPI Matrix2x2();
		MATHDLLAPI Matrix2x2(Vector2 &rowOne, Vector2 &rowTwo);
		MATHDLLAPI Matrix2x2(const Matrix2x2 &a_mat);
		MATHDLLAPI ~Matrix2x2();

		MATHDLLAPI void Transpose();
		MATHDLLAPI Matrix2x2 Transposed();

		MATHDLLAPI Matrix2x2 operator+(const Matrix2x2 &rhs);
		MATHDLLAPI void operator+=(Matrix2x2 &rhs);
		MATHDLLAPI Matrix2x2 operator-(const Matrix2x2 &rhs);
		MATHDLLAPI void operator-=(Matrix2x2 &rhs);
		MATHDLLAPI Matrix2x2 operator*(const Matrix2x2 &rhs);
		MATHDLLAPI void operator*=(Matrix2x2 &rhs);
		MATHDLLAPI Vector2 operator*(Vector2 &rhs);

		float m_mat[2][2];
	};

	class Matrix3x3
	{
	public:
		MATHDLLAPI Matrix3x3();
		MATHDLLAPI Matrix3x3(Vector3 &rowOne, Vector3 &rowTwo, Vector3 &rowThree);
		MATHDLLAPI Matrix3x3(const Matrix3x3 &a_mat);
		MATHDLLAPI ~Matrix3x3();

		MATHDLLAPI void Transpose();
		MATHDLLAPI Matrix3x3 Transposed();
		MATHDLLAPI void ScaleMat(float xScale, float yScale);
		MATHDLLAPI void RotateMat(float angle);
		MATHDLLAPI void TranslateMat(float xTrans, float yTrans);

		static MATHDLLAPI Matrix3x3 CreateScaleMat(float xScale, float yScale);
		static MATHDLLAPI Matrix3x3 CreateRotateMat(float angle);
		static MATHDLLAPI Matrix3x3 CreateTranslateMat(float xTrans, float yTrans);

		MATHDLLAPI Matrix3x3 operator+(const Matrix3x3 &rhs);
		MATHDLLAPI void operator+=(Matrix3x3 &rhs);
		MATHDLLAPI Matrix3x3 operator-(const Matrix3x3 &rhs);
		MATHDLLAPI void operator-=(Matrix3x3 &rhs);
		MATHDLLAPI Matrix3x3 operator*(const Matrix3x3 &rhs);
		MATHDLLAPI void operator*=(Matrix3x3 &rhs);
		MATHDLLAPI Vector3 operator*(Vector3 &rhs);
		MATHDLLAPI void operator*=(Vector3 &rhs);
		MATHDLLAPI Vector2 operator*(Vector2 &rhs);
		MATHDLLAPI void operator*=(Vector2 &rhs);
		friend MATHDLLAPI ostream& operator<< (ostream& stream, const Matrix3x3& matrix);

		float m_mat[3][3];
	};

	class Matrix4x4
	{
	public:
		MATHDLLAPI Matrix4x4();
		MATHDLLAPI Matrix4x4(Vector4 &rowOne, Vector4 &rowTwo, Vector4 &rowThree, Vector4 &rowFour);
		MATHDLLAPI Matrix4x4(const Matrix4x4 &a_mat);
		MATHDLLAPI ~Matrix4x4();

		MATHDLLAPI void Transpose();
		MATHDLLAPI Matrix4x4 Transposed();
		static MATHDLLAPI Matrix4x4 CreateScaleMat(float xScale, float yScale, float zScale);
		static MATHDLLAPI Matrix4x4 CreateZRotateMat(float angle);
		static MATHDLLAPI Matrix4x4 CreateYRotateMat(float angle);
		static MATHDLLAPI Matrix4x4 CreateXRotateMat(float angle);
		static MATHDLLAPI Matrix4x4 CreateTranslateMat(float xTrans, float yTrans, float zTrans);

		MATHDLLAPI void ScaleMat(float xScale, float yScale, float zScale);
		MATHDLLAPI void ZRotateMat(float angle);
		MATHDLLAPI void YRotateMat(float angle);
		MATHDLLAPI void XRotateMat(float angle);
		MATHDLLAPI void TranslateMat(float xTrans, float yTrans, float zTrans);

		MATHDLLAPI Matrix4x4 operator+(const Matrix4x4 &rhs);
		MATHDLLAPI void operator+=(Matrix4x4 &rhs);
		MATHDLLAPI Matrix4x4 operator-(const Matrix4x4 &rhs);
		MATHDLLAPI void operator-=(Matrix4x4 &rhs);
		MATHDLLAPI Matrix4x4 operator*(const Matrix4x4 &rhs);
		MATHDLLAPI void operator*=(Matrix4x4 &rhs);
		MATHDLLAPI Vector4 operator*(Vector4 &rhs);
		MATHDLLAPI void operator*=(Vector4 &rhs);
		MATHDLLAPI Vector3 operator*(Vector3 &rhs);
		MATHDLLAPI void operator*=(Vector3 &rhs);
		friend MATHDLLAPI ostream& operator<< (ostream& stream, const Matrix4x4& matrix);

		float m_mat[4][4];
	};

}

#endif