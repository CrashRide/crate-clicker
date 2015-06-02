#include "Vector4.h"


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

Vector4::~Vector4()
{
}
