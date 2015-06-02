#ifndef _MATRIX3X3_H_
#define _MATRIX3X3_H_

class Vector3;

class Matrix3x3
{
public:
	Matrix3x3();
	Matrix3x3(Vector3 &rowOne, Vector3 &rowTwo, Vector3 &rowThree);
	Matrix3x3(const Matrix3x3 &a_mat);
	~Matrix3x3();

	void Transpose();
	void ScaleMat(float xScale, float yScale);
	void RotateMat(float angle);
	void TranslateMat(float xTrans, float yTrans);

	Matrix3x3 operator+(const Matrix3x3 &rhs);
	void operator+=(Matrix3x3 &rhs);
	Matrix3x3 operator-(const Matrix3x3 &rhs);
	void operator-=(Matrix3x3 &rhs);
	Matrix3x3 operator*(const Matrix3x3 &rhs);
	void operator*=(Matrix3x3 &rhs);
	Vector3 operator*(Vector3 &rhs);

	float m_mat[3][3];
};

#endif