#include "Vector3.h"


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
