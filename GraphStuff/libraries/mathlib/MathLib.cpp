// This is the main DLL file.

#include "stdafx.h"

#include "MathLib.h"

using namespace MathLib;

namespace MathLib
{
Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float a, float b)
{
	x = a;
	y = b;
}

Vector2::Vector2(const Vector2 &rhs)
{
	*this = rhs;
}

float Vector2::Magnatude()
{
	return sqrt(SqrMagnatude());
}

float Vector2::SqrMagnatude()
{
	float mag = (x*x) + (y*y);
	return mag;
}

void Vector2::Normalise()
{
	float mag = Magnatude();
	x /= mag;
	y /= mag;
}

Vector2 Vector2::Normalised()
{
	float mag = Magnatude();
	Vector2 temp(x / mag, y / mag);
	return temp;
}

float Vector2::Dot(const Vector2 &a)
{
	float temp = 0.0f;
	temp += a.x*x;
	temp += a.y*y;
	return temp;
}

Vector2 Vector2::Perpendicular()
{
	return Vector2(-y, x);
}

float Vector2::AngleOf()
{
	return AngleBetween(Vector2(1, 0));
}

float Vector2::AngleBetween(const Vector2 &a)
{
	return acos(Dot(a) / Magnatude());
}

Vector2 Vector2::operator+(const Vector2 &rhs) const
{
	Vector2 temp;
	temp.x = x + rhs.x;
	temp.y = y + rhs.y;
	return temp;
}

Vector2 Vector2::operator-(const Vector2 &rhs) const
{
	Vector2 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	return temp;
}

void Vector2::operator+=(const Vector2 &rhs)
{
	x += rhs.x;
	y += rhs.y;
}

void Vector2::operator-=(const Vector2 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}

Vector2 Vector2::operator*(float rhs)const
{
	Vector2 temp(x*rhs, y*rhs);
	return temp;
}

void Vector2::operator*=(float rhs)
{
	x *= rhs;
	y *= rhs;
}

Vector2 Vector2::operator/(float rhs)const
{
	Vector2 temp(x / rhs, y / rhs);
	return temp;
}

void Vector2::operator/=(float rhs)
{
	x /= rhs;
	y /= rhs;
}

bool Vector2::operator>(const Vector2 &rhs)
{
	if (x > rhs.x && y > rhs.y)
		return true;
	else
		return false;
}

bool Vector2::operator<(const Vector2 &rhs)
{
	if (x < rhs.x && y < rhs.y)
		return true;
	else
		return false;
}

void Vector2::operator=(const Vector2 &rhs)
{
	x = rhs.x;
	y = rhs.y;
}

bool Vector2::operator==(const Vector2 &rhs) const
{
	if (x == rhs.x && y == rhs.y)
		return true;
	return false;
}

bool Vector2::operator!=(const Vector2 &rhs) const
{
	return !(*this == rhs);
}

float& Vector2::operator[](const int index)
{
	switch (index)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	default:
		break;
	}
}

Vector2::~Vector2()
{
}

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

Vector3::Vector3(const Vector3 &rhs)
{
	*this = rhs;
}

float Vector3::Magnatude()
{
	return sqrt(SqrMagnatude());
}

float Vector3::SqrMagnatude()
{
	float mag = (x*x) + (y*y) + (z*z);
	return mag;
}

void Vector3::Normalise()
{
	float mag = Magnatude();
	x /= mag;
	y /= mag;
	z /= mag;
}

Vector3 Vector3::Normalised()
{
	float mag = Magnatude();
	Vector3 temp(x / mag, y / mag, z / mag);
	return temp;
}

float Vector3::Dot(const Vector3 &a)
{
	float temp = 0.0f;
	temp += a.x*x;
	temp += a.y*y;
	temp += a.z*z;
	return temp;
}

Vector3 Vector3::Cross(const Vector3 &a)
{
	return Vector3(y*a.z - z*a.y, z*a.x - x*a.z, x*a.y - y*a.x).Normalised();
}

float Vector3::AngleBetween(const Vector3 &a)
{
	return acos(Dot(a) / Magnatude());
}

Vector3 Vector3::operator+(const Vector3 &rhs) const
{
	Vector3 temp;
	temp.x = x + rhs.x;
	temp.y = y + rhs.y;
	temp.z = y + rhs.z;
	return temp;
}

Vector3 Vector3::operator-(const Vector3 &rhs) const
{
	Vector3 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	temp.z = y - rhs.z;
	return temp;
}

void Vector3::operator+=(const Vector3 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

void Vector3::operator-=(const Vector3 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}

Vector3 Vector3::operator*(float rhs)const
{
	Vector3 temp(x*rhs, y*rhs, z*rhs);
	return temp;
}

void Vector3::operator*=(float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
}

Vector3 Vector3::operator/(float rhs)const
{
	Vector3 temp(x / rhs, y / rhs, z / rhs);
	return temp;
}

void Vector3::operator/=(float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
}

bool Vector3::operator>(const Vector3 &rhs)
{
	if (x > rhs.x && y > rhs.y && z > rhs.z)
		return true;
	else
		return false;
}

bool Vector3::operator<(const Vector3 &rhs)
{
	if (x < rhs.x && y < rhs.y && z < rhs.z)
		return true;
	else
		return false;
}

void Vector3::operator=(const Vector3 &rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

bool Vector3::operator==(const Vector3 &rhs) const
{
	if (x == rhs.x && y == rhs.y && z == rhs.z)
		return true;
	return false;
}

bool Vector3::operator!=(const Vector3 &rhs) const
{
	return !(*this == rhs);
}

float& Vector3::operator[](const int index)
{
	switch (index)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	default:
		break;
	}
}

Vector3::~Vector3()
{
}

Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

Vector4::Vector4(const Vector4 &rhs)
{
	*this = rhs;
}

float Vector4::Magnatude()
{
	return sqrt(SqrMagnatude());
}

float Vector4::SqrMagnatude()
{
	float mag = (x*x) + (y*y) + (z*z);
	return mag;
}

void Vector4::Normalise()
{
	float mag = Magnatude();
	x /= mag;
	y /= mag;
	z /= mag;
}

Vector4 Vector4::Normalised()
{
	float mag = Magnatude();
	Vector4 temp(x / mag, y / mag, z / mag, w);
	return temp;
}

float Vector4::Dot(const Vector4 &a)
{
	float temp = 0.0f;
	temp += a.x*x;
	temp += a.y*y;
	temp += a.z*z;
	return temp;
}

Vector4 Vector4::Cross(const Vector4 &a)
{
	return Vector4(y*a.z - z*a.y, z*a.x - x*a.z, x*a.y - y*a.x, w).Normalised();
}

float Vector4::AngleBetween(const Vector4 &a)
{
	return acos(Dot(a) / Magnatude());
}

Vector4 Vector4::operator+(const Vector4 &rhs) const
{
	Vector4 temp;
	temp.x = x + rhs.x;
	temp.y = y + rhs.y;
	temp.z = y + rhs.z;
	return temp;
}

Vector4 Vector4::operator-(const Vector4 &rhs) const
{
	Vector4 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	temp.z = y - rhs.z;
	return temp;
}

void Vector4::operator+=(const Vector4 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

void Vector4::operator-=(const Vector4 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}

Vector4 Vector4::operator*(float rhs)const
{
	Vector4 temp(x*rhs, y*rhs, z*rhs, w);
	return temp;
}

void Vector4::operator*=(float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
}

Vector4 Vector4::operator/(float rhs)const
{
	Vector4 temp(x / rhs, y / rhs, z / rhs, w);
	return temp;
}

void Vector4::operator/=(float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
}

bool Vector4::operator>(const Vector4 &rhs)
{
	if (x > rhs.x && y > rhs.y && z > rhs.z)
		return true;
	else
		return false;
}

bool Vector4::operator<(const Vector4 &rhs)
{
	if (x < rhs.x && y < rhs.y && z < rhs.z)
		return true;
	else
		return false;
}

void Vector4::operator=(const Vector4 &rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

bool Vector4::operator==(const Vector4 &rhs) const
{
	if (x == rhs.x && y == rhs.y && z == rhs.z)
		return true;
	return false;
}

bool Vector4::operator!=(const Vector4 &rhs) const
{
	return !(*this == rhs);
}

float& Vector4::operator[](const int index)
{
	switch (index)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	case 3:
		return w;
		break;
	default:
		break;
	}
}

Vector4::~Vector4()
{
}

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

ostream& operator <<(ostream& os, const Matrix3x3& rhs)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			os << rhs.m_mat[j][i] << "	,	";
		}
		os << endl;
	}
	return os;
}

Matrix4x4::Matrix4x4()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
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

Matrix4x4::Matrix4x4(Vector4 &rowOne, Vector4 &rowTwo, Vector4 &rowThree, Vector4 &rowFour)
{
	for (int j = 0; j < 4; j++)
	{
		m_mat[j][0] = rowOne[j];
		m_mat[j][1] = rowTwo[j];
		m_mat[j][2] = rowThree[j];
		m_mat[j][3] = rowFour[j];
	}
}

Matrix4x4::Matrix4x4(const Matrix4x4 &a_mat)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_mat[i][j] = a_mat.m_mat[i][j];
		}
	}
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

void Matrix4x4::operator*=(Vector4 &rhs)
{
	Vector4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			temp[j] += m_mat[j][i] * rhs[i];
		}
	}
	rhs = temp;
}

Vector3 Matrix4x4::operator*(Vector3 &rhs)
{
	Vector4 rhsTemp(rhs.x, rhs.y, rhs.z, 1.0f);
	Vector4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			temp[j] += m_mat[j][i] * rhsTemp[i];
		}
	}

	return Vector3(temp.x, temp.y, temp.z);
}

void Matrix4x4::operator*=(Vector3 &rhs)
{
	Vector4 rhsTemp(rhs.x, rhs.y, rhs.z, 1.0);
	Vector4 temp;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			temp[j] += m_mat[j][i] * rhsTemp[i];
		}
	}

	rhs = Vector3(temp.x, temp.y, temp.z);
}

ostream& operator<<(ostream& os, const Matrix4x4& rhs)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			os << rhs.m_mat[j][i] << "	,	";
		}
		os << endl;
	}
	return os;
}
}