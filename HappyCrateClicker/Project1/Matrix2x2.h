#ifndef _MATRIX2X2_H_
#define _MATRIX2X2_H_

class Vector2;

class Matrix2x2
{
public:
	Matrix2x2();
	Matrix2x2(const Vector2 &rowOne, const Vector2 &rowTwo);
	~Matrix2x2();
private:
	float m_mat[2][2];
};

#endif