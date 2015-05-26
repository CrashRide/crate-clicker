#include "Vector2.h"


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

float Vector2::GetX()
{
	return x;
}

float Vector2::GetY()
{
	return y;
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
	float mag = this->Magnatude();
	x /= mag;
	y /= mag;
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
	Vector2 temp(x/rhs, y/rhs);
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

Vector2::~Vector2()
{
}
