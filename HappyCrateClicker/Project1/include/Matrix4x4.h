#ifndef _MATRIX4x4_H_
#define _MATRIX4x4_H_

class Vector4;

class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(Vector4 &rowOne, Vector4 &rowTwo, Vector4 &rowThree, Vector4 &rowFour);
	Matrix4x4(const Matrix4x4 &a_mat);
	~Matrix4x4();

	void Transpose();
	Matrix4x4 Transposed();
	static Matrix4x4 CreateScaleMat(float xScale, float yScale, float zScale);
	static Matrix4x4 CreateZRotateMat(float angle);
	static Matrix4x4 CreateYRotateMat(float angle);
	static Matrix4x4 CreateXRotateMat(float angle);
	static Matrix4x4 CreateTranslateMat(float xTrans, float yTrans, float zTrans);

	void ScaleMat(float xScale, float yScale, float zScale);
	void ZRotateMat(float angle);
	void YRotateMat(float angle);
	void XRotateMat(float angle);
	void TranslateMat(float xTrans, float yTrans, float zTrans);

	Matrix4x4 operator+(const Matrix4x4 &rhs);
	void operator+=(Matrix4x4 &rhs);
	Matrix4x4 operator-(const Matrix4x4 &rhs);
	void operator-=(Matrix4x4 &rhs);
	Matrix4x4 operator*(const Matrix4x4 &rhs);
	void operator*=(Matrix4x4 &rhs);
	Vector4 operator*(Vector4 &rhs);

	float m_mat[4][4];
};

#endif