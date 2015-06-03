#ifndef _MATRIX2X2_H_
#define _MATRIX2X2_H_

class Vector2;

class Matrix2x2
{
public:
	Matrix2x2();
	Matrix2x2(Vector2 &rowOne, Vector2 &rowTwo);
	Matrix2x2(const Matrix2x2 &a_mat);
	~Matrix2x2();

	void Transpose();
	Matrix2x2 Transposed();

	Matrix2x2 operator+(const Matrix2x2 &rhs);
	void operator+=(Matrix2x2 &rhs);
	Matrix2x2 operator-(const Matrix2x2 &rhs);
	void operator-=(Matrix2x2 &rhs);
	Matrix2x2 operator*(const Matrix2x2 &rhs);
	void operator*=(Matrix2x2 &rhs);
	Vector2 operator*(Vector2 &rhs);

	float m_mat[2][2];
};

#endif