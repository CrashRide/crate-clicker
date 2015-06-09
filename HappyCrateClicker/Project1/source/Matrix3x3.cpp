#include "Matrix3x3.h"
#include "Vector2.h"
#include "Vector3.h"

Matrix3x3::Matrix3x3()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
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

Matrix3x3::Matrix3x3(Vector3 &rowOne, Vector3 &rowTwo, Vector3 &rowThree)
{
	for (int j = 0; j < 3; j++)
	{
		m_mat[j][0] = rowOne[j];
		m_mat[j][1] = rowTwo[j];
		m_mat[j][2] = rowThree[j];
	}
}

Matrix3x3::Matrix3x3(const Matrix3x3 &a_mat)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			m_mat[i][j] = a_mat.m_mat[i][j];
		}
	}
}


Matrix3x3::~Matrix3x3()
{
}

void Matrix3x3::Transpose()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = j; i < 3; i++)
		{
			if (j == i)
				break;
			else
			{
				float temp = m_mat[j][i];
				m_mat[j][i] = m_mat[i][j];
				m_mat[i][j] = temp;
			}
		}
	}
}

Matrix3x3 Matrix3x3::Transposed()
{
	Matrix3x3 tempm;
	for (int j = 0; j < 3; j++)
	{
		for (int i = j; i < 3; i++)
		{
			if (j == i)
				break;
			else
			{
				float temp = tempm.m_mat[j][i];
				tempm.m_mat[j][i] = tempm.m_mat[i][j];
				tempm.m_mat[i][j] = temp;
			}
		}
	}
	return tempm;
}

void Matrix3x3::ScaleMat(float xScale, float yScale)
{
	Matrix3x3 temp;
	temp.m_mat[0][0] = xScale;
	temp.m_mat[1][1] = yScale;
	*this *= temp;
}

void Matrix3x3::RotateMat(float angle)
{
	Matrix3x3 temp;
	temp.m_mat[0][0] = cos(angle);
	temp.m_mat[0][1] = -(sin(angle));
	temp.m_mat[1][0] = sin(angle);
	temp.m_mat[1][1] = temp.m_mat[0][0];
	*this *= temp;
}

void Matrix3x3::TranslateMat(float xTrans, float yTrans)
{
	Matrix3x3 temp;
	temp.m_mat[0][2] = xTrans;
	temp.m_mat[1][2] = yTrans;
	*this *= temp;
}

Matrix3x3 Matrix3x3::CreateScaleMat(float xScale, float yScale)
{
	Matrix3x3 temp;
	temp.m_mat[0][0] = xScale;
	temp.m_mat[1][1] = yScale;
	return temp;
}

Matrix3x3 Matrix3x3::CreateRotateMat(float angle)
{
	Matrix3x3 temp;
	temp.m_mat[0][0] = cos(angle);
	temp.m_mat[0][1] = -(sin(angle));
	temp.m_mat[1][0] = sin(angle);
	temp.m_mat[1][1] = temp.m_mat[0][0];
	return temp;
}

Matrix3x3 Matrix3x3::CreateTranslateMat(float xTrans, float yTrans)
{
	Matrix3x3 temp;
	temp.m_mat[0][2] = xTrans;
	temp.m_mat[1][2] = yTrans;
	return temp;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &rhs)
{
	Matrix3x3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp.m_mat[j][i] = m_mat[j][i] + rhs.m_mat[j][i];
		}
	}
	return temp;
}

void Matrix3x3::operator+=(Matrix3x3 &rhs)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			m_mat[j][i] += rhs.m_mat[j][i];
		}
	}
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &rhs)
{
	Matrix3x3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp.m_mat[j][i] = m_mat[j][i] - rhs.m_mat[j][i];
		}
	}
	return temp;
}

void Matrix3x3::operator-=(Matrix3x3 &rhs)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			m_mat[j][i] -= rhs.m_mat[j][i];
		}
	}
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &rhs)
{
	Matrix3x3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (j == i)
				temp.m_mat[j][i] = 0;
			for (int h = 0; h < 3; h++)
			{
				temp.m_mat[j][i] += (m_mat[j][h] * rhs.m_mat[h][i]);
			}
		}
	}
	return temp;
}

void Matrix3x3::operator*=(Matrix3x3 &rhs)
{
	Matrix3x3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (j == i)
				temp.m_mat[j][i] = 0;
			for (int h = 0; h < 3; h++)
			{
				temp.m_mat[j][i] += (m_mat[j][h] * rhs.m_mat[h][i]);
			}
		}
	}
	*this = temp;
}

Vector3 Matrix3x3::operator*(Vector3 &rhs)
{
	Vector3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp[j] += m_mat[j][i] * rhs[i];
		}
	}
	return temp;
}

void Matrix3x3::operator*=(Vector3 &rhs)
{
	Vector3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp[j] += m_mat[j][i] * rhs[i];
		}
	}
	rhs = temp;
}

Vector2 Matrix3x3::operator*(Vector2 &rhs)
{
	Vector3 rhsTemp(rhs.x, rhs.y, 1.0);
	Vector3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp[j] += m_mat[j][i] * rhsTemp[i];
		}
	}
	
	return Vector2(temp.x, temp.y);
}

void Matrix3x3::operator*=(Vector2 &rhs)
{
	Vector3 rhsTemp(rhs.x, rhs.y, 1.0);
	Vector3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp[j] += m_mat[j][i] * rhsTemp[i];
		}
	}

	rhs = Vector2(temp.x, temp.y);
}
