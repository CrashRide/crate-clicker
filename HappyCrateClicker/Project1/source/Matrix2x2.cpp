#include "Matrix2x2.h"
#include "Vector2.h"

Matrix2x2::Matrix2x2()
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (j == i)
				m_mat[i][j] = 1;
			else
			{
				m_mat[i][j] = 0;
			}
		}
	}
}

Matrix2x2::Matrix2x2(Vector2 &rowOne, Vector2 &rowTwo)
{
	for (int j = 0; j < 2; j++)
	{
		m_mat[j][0] = rowOne[j];
		m_mat[j][1] = rowTwo[j];
	}
}

Matrix2x2::Matrix2x2(const Matrix2x2 &a_mat)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			m_mat[i][j] = a_mat.m_mat[i][j];
		}
	}
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
