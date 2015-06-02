#ifndef _VECTOR4_H_
#define _VECTOR4_H_
#include <cmath>

class Vector4
{
public:
	Vector4();
	Vector4(float a, float b, float c, float d);
	Vector4(const Vector4 &rhs);

	float Magnatude();
	float SqrMagnatude();

	void Normalise();
	Vector4 Normalised();

	float Dot(const Vector4 &a);
	Vector4 Cross(const Vector4 &a);

	float AngleBetween(const Vector4 &a);

	Vector4 operator+(const Vector4 &rhs)const;
	Vector4 operator-(const Vector4 &rhs)const;
	void operator+=(const Vector4 &rhs);
	void operator-=(const Vector4 &rhs);

	Vector4 operator*(float rhs)const;
	void operator*=(float rhs);

	Vector4 operator/(float rhs)const;
	void operator/=(float rhs);

	bool operator>(const Vector4 &rhs);
	bool operator<(const Vector4 &rhs);

	void operator=(const Vector4 &rhs);
	bool operator==(const Vector4 &rhs)const;
	bool operator!=(const Vector4 &rhs)const;

	friend Vector4 operator*(float lhs, const Vector4 &rhs)
	{
		return rhs * lhs;
	}
	friend void operator*=(float lhs, Vector4 &rhs)
	{
		rhs *= lhs;
	}

	~Vector4();

	float x;
	float y;
	float z;
	float w;
};

#endif