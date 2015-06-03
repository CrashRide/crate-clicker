#include "Matrix4x4.h"
#include "Vector4.h"

Matrix4x4::Matrix4x4()
{
	float m_mat[4][4] =
	{
		{ 1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 },
	};
}

Matrix4x4::Matrix4x4(Vector4 &rowOne, Vector4 &rowTwo, Vector4 &rowThree, Vector4 &rowFour)
{
	float m_mat[4][4] =
	{
		{ rowOne.x, rowOne.y, rowOne.z, rowOne.w },
		{ rowTwo.x, rowTwo.y, rowTwo.z, rowTwo.w },
		{ rowThree.x, rowThree.y, rowThree.z, rowThree.w },
		{ rowFour.x, rowFour.y, rowFour.z, rowFour.w },
	};
}

Matrix4x4::Matrix4x4(const Matrix4x4 &a_mat)
{
	float m_mat[4][4] =
	{
		{ a_mat.m_mat[0][0], a_mat.m_mat[0][1], a_mat.m_mat[0][2], a_mat.m_mat[0][3] },
		{ a_mat.m_mat[1][0], a_mat.m_mat[1][1], a_mat.m_mat[1][2], a_mat.m_mat[1][3] },
		{ a_mat.m_mat[2][0], a_mat.m_mat[2][1], a_mat.m_mat[2][2], a_mat.m_mat[2][3] },
		{ a_mat.m_mat[3][0], a_mat.m_mat[3][1], a_mat.m_mat[3][2], a_mat.m_mat[3][3] },
	};
}


Matrix4x4::~Matrix4x4()
{
}

void Matrix4x4::Transpose()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = j; i < 4; i++)
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

Matrix4x4 Matrix4x4::Transposed()
{
	Matrix4x4 temp(*this);
	
	for (int j = 0; j < 4; j++)
	{
		for (int i = j; i < 4; i++)
		{
			if (j == i)
				break;
			else
			{
				float tempF = temp.m_mat[j][i];
				temp.m_mat[j][i] = temp.m_mat[i][j];
				temp.m_mat[i][j] = tempF;
			}
		}
	}
	return temp;
}

Matrix4x4 Matrix4x4::CreateScaleMat(float xScale, float yScale, float zScale)
{
	Matrix4x4 temp;
	temp.m_mat[0][0] = xScale;
	temp.m_mat[1][1] = yScale;
	temp.m_mat[2][2] = zScale;
	return temp;
}

Matrix4x4 Matrix4x4::CreateZRotateMat(float angle)
{
	Matrix4x4 temp;
	temp.m_mat[0][0] = cos(angle);
	temp.m_mat[0][1] = -sin(angle);
	temp.m_mat[1][0] = sin(angle);
	temp.m_mat[1][1] = temp.m_mat[0][0];
	return temp;
}

Matrix4x4 Matrix4x4::CreateYRotateMat(float angle)
{
	Matrix4x4 temp;
	temp.m_mat[0][0] = cos(angle);
	temp.m_mat[0][1] = sin(angle);
	temp.m_mat[2][0] = -sin(angle);
	temp.m_mat[2][1] = temp.m_mat[0][0];
	return temp;
}

Matrix4x4 Matrix4x4::CreateXRotateMat(float angle)
{
	Matrix4x4 temp;
	temp.m_mat[1][1] = cos(angle);
	temp.m_mat[1][2] = -sin(angle);
	temp.m_mat[2][1] = sin(angle);
	temp.m_mat[2][2] = temp.m_mat[0][0];
	return temp;
}

Matrix4x4 Matrix4x4::CreateTranslateMat(float xTrans, float yTrans, float zTrans)
{
	Matrix4x4 temp;
	temp.m_mat[0][3] = xTrans;
	temp.m_mat[1][3] = yTrans;
	temp.m_mat[2][3] = zTrans;
	return temp;
}

void Matrix4x4::ScaleMat(float xScale, float yScale, float zScale)
{
	Matrix4x4 temp;
	temp.m_mat[0][0] = xScale;
	temp.m_mat[1][1] = yScale;
	temp.m_mat[2][2] = zScale;
	*this *= temp;
}

void Matrix4x4::ZRotateMat(float angle)
{
	Matrix4x4 temp;
	temp.m_mat[0][0] = cos(angle);
	temp.m_mat[0][1] = -sin(angle);
	temp.m_mat[1][0] = sin(angle);
	temp.m_mat[1][1] = temp.m_mat[0][0];
	*this *= temp;
}

void Matrix4x4::YRotateMat(float angle)
{
	Matrix4x4 temp;
	temp.m_mat[0][0] = cos(angle);
	temp.m_mat[0][1] = sin(angle);
	temp.m_mat[2][0] = -sin(angle);
	temp.m_mat[2][1] = temp.m_mat[0][0];
	*this *= temp;
}

void Matrix4x4::XRotateMat(float angle)
{
	Matrix4x4 temp;
	temp.m_mat[1][1] = cos(angle);
	temp.m_mat[1][2] = -sin(angle);
	temp.m_mat[2][1] = sin(angle);
	temp.m_mat[2][2] = temp.m_mat[0][0];
	*this *= temp;
}

void Matrix4x4::TranslateMat(float xTrans, float yTrans, float zTrans)
{
	Matrix4x4 temp;
	temp.m_mat[0][3] = xTrans;
	temp.m_mat[1][3] = yTrans;
	temp.m_mat[2][3] = zTrans;
	*this *= temp;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &rhs)
{
	Matrix4x4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			temp.m_mat[j][i] = m_mat[j][i] + rhs.m_mat[j][i];
		}
	}
	return temp;
}

void Matrix4x4::operator+=(Matrix4x4 &rhs)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_mat[j][i] += rhs.m_mat[j][i];
		}
	}
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &rhs)
{
	Matrix4x4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			temp.m_mat[j][i] = m_mat[j][i] - rhs.m_mat[j][i];
		}
	}
	return temp;
}

void Matrix4x4::operator-=(Matrix4x4 &rhs)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_mat[j][i] -= rhs.m_mat[j][i];
		}
	}
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &rhs)
{
	Matrix4x4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (j == i)
				temp.m_mat[j][i] = 0;
			for (int h = 0; h < 4; h++)
			{
				temp.m_mat[j][i] += (m_mat[j][h] * rhs.m_mat[h][i]);
			}
		}
	}
	return temp;
}

void Matrix4x4::operator*=(Matrix4x4 &rhs)
{
	Matrix4x4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (j == i)
				temp.m_mat[j][i] = 0;
			for (int h = 0; h < 4; h++)
			{
				temp.m_mat[j][i] += (m_mat[j][h] * rhs.m_mat[h][i]);
			}
		}
	}
	*this = temp;
}

Vector4 Matrix4x4::operator*(Vector4 &rhs)
{
	Vector4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			temp[j] += m_mat[j][i] * rhs[i];
		}
	}
	return temp;
}