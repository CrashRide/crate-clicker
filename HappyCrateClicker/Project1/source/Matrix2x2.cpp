#include "Matrix2x2.h"
#include "Vector2.h"

Matrix2x2::Matrix2x2()
{
	float m_mat[2][2] =
	{
		{ 1, 0 },
		{ 0, 1 },
	};
}

Matrix2x2::Matrix2x2(Vector2 &rowOne, Vector2 &rowTwo)
{
	float m_mat[2][2] =
	{
		{ rowOne.x, rowOne.y },
		{ rowTwo.x, rowTwo.y },
	};
}

Matrix2x2::Matrix2x2(const Matrix2x2 &a_mat)
{
	float m_mat[2][2] = 
	{
		{ a_mat.m_mat[0][0], a_mat.m_mat[0][1] },
		{ a_mat.m_mat[1][0], a_mat.m_mat[1][1] }
	};
}


Matrix2x2::~Matrix2x2()
{
}

void Matrix2x2::Transpose()
{
	float temp = m_mat[0][1];
	m_mat[0][1] = m_mat[1][0];
	m_mat[1][0] = temp;
}

Matrix2x2 Matrix2x2::Transposed()
{
	Matrix2x2 tempF;
	float temp = tempF.m_mat[0][1];
	tempF.m_mat[0][1] = tempF.m_mat[1][0];
	tempF.m_mat[1][0] = temp;
	return tempF;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2 &rhs)
{
	Vector2 rowOne(m_mat[0][0] + rhs.m_mat[0][0], m_mat[0][1] + rhs.m_mat[0][1]);
	Vector2 rowTwo(m_mat[1][0] + rhs.m_mat[1][0], m_mat[1][1] + rhs.m_mat[1][1]);
	return Matrix2x2(rowOne, rowTwo);
}

void Matrix2x2::operator+=(Matrix2x2 &rhs)
{
	m_mat[0][0] += rhs.m_mat[0][0], m_mat[0][1] += rhs.m_mat[0][1];
	m_mat[1][0] += rhs.m_mat[1][0], m_mat[1][1] += rhs.m_mat[1][1];
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2 &rhs)
{
	Vector2 rowOne(m_mat[0][0] - rhs.m_mat[0][0], m_mat[0][1] - rhs.m_mat[0][1]);
	Vector2 rowTwo(m_mat[1][0] - rhs.m_mat[1][0], m_mat[1][1] - rhs.m_mat[1][1]);
	return Matrix2x2(rowOne, rowTwo);
}

void Matrix2x2::operator-=(Matrix2x2 &rhs)
{
	m_mat[0][0] -= rhs.m_mat[0][0], m_mat[0][1] -= rhs.m_mat[0][1];
	m_mat[1][0] -= rhs.m_mat[1][0], m_mat[1][1] -= rhs.m_mat[1][1];
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2 &rhs)
{
	Vector2 rowOne((m_mat[0][0] * rhs.m_mat[0][0]) + (m_mat[0][1] * rhs.m_mat[1][0]), (m_mat[0][0] * rhs.m_mat[1][0]) + (m_mat[0][1] * rhs.m_mat[1][1]));
	Vector2 rowTwo((m_mat[1][0] * rhs.m_mat[0][0]) + (m_mat[1][1] * rhs.m_mat[1][0]), (m_mat[1][0] * rhs.m_mat[0][1]) + (m_mat[1][1] * rhs.m_mat[1][1]));
	return Matrix2x2(rowOne, rowTwo);
}

void Matrix2x2::operator*=(Matrix2x2 &rhs)
{
	Vector2 rowOne((m_mat[0][0] * rhs.m_mat[0][0]) + (m_mat[0][1] * rhs.m_mat[1][0]), (m_mat[0][0] * rhs.m_mat[1][0]) + (m_mat[0][1] * rhs.m_mat[1][1]));
	Vector2 rowTwo((m_mat[1][0] * rhs.m_mat[0][0]) + (m_mat[1][1] * rhs.m_mat[1][0]), (m_mat[1][0] * rhs.m_mat[0][1]) + (m_mat[1][1] * rhs.m_mat[1][1]));
	*this = Matrix2x2(rowOne, rowTwo);
}

Vector2 Matrix2x2::operator*(Vector2 &rhs)
{
	return Vector2((m_mat[0][0] * rhs.x) + (m_mat[0][1] * rhs.y), (m_mat[1][0] * rhs.x) + (m_mat[1][1] * rhs.y));
}
