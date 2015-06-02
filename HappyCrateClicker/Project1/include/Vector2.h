#ifndef _VECTOR2_H_
#define _VECTOR2_H_
#include <cmath>

class Matrix2x2;

class Vector2
{
public:
	Vector2();
	Vector2(float a, float b);
	Vector2(const Vector2 &rhs);

	float Magnatude();
	float SqrMagnatude();

	void Normalise();
	Vector2 Normalised();

	float Dot(const Vector2 &a);
	Vector2 Perpendicular();

	float AngleOf();
	float AngleBetween(const Vector2 &a);

	Vector2 operator+(const Vector2 &rhs)const;
	Vector2 operator-(const Vector2 &rhs)const;
	void operator+=(const Vector2 &rhs);
	void operator-=(const Vector2 &rhs);

	Vector2 operator*(float rhs)const;
	void operator*=(float rhs);



	Vector2 operator/(float rhs)const;
	void operator/=(float rhs);

	bool operator>(const Vector2 &rhs);
	bool operator<(const Vector2 &rhs);

	void operator=(const Vector2 &rhs);
	bool operator==(const Vector2 &rhs)const;
	bool operator!=(const Vector2 &rhs)const;

	friend Vector2 operator*(float lhs, const Vector2 &rhs)
	{
		return rhs * lhs;
	}
	friend void operator*=(float lhs, Vector2 &rhs)
	{
		rhs *= lhs;
	}

	~Vector2();

	float x;
	float y;
};

#endif