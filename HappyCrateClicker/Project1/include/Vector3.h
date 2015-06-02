#ifndef _VECTOR3_H_
#define _VECTOR3_H_
#include <cmath>

class Vector3
{
public:
	Vector3();
	Vector3(float a, float b, float c);
	Vector3(const Vector3 &rhs);

	float Magnatude();
	float SqrMagnatude();

	void Normalise();
	Vector3 Normalised();

	float Dot(const Vector3 &a);
	Vector3 Cross(const Vector3 &a);

	float AngleBetween(const Vector3 &a);

	Vector3 operator+(const Vector3 &rhs)const;
	Vector3 operator-(const Vector3 &rhs)const;
	void operator+=(const Vector3 &rhs);
	void operator-=(const Vector3 &rhs);

	Vector3 operator*(float rhs)const;
	void operator*=(float rhs);

	Vector3 operator/(float rhs)const;
	void operator/=(float rhs);

	bool operator>(const Vector3 &rhs);
	bool operator<(const Vector3 &rhs);

	void operator=(const Vector3 &rhs);
	bool operator==(const Vector3 &rhs)const;
	bool operator!=(const Vector3 &rhs)const;

	friend Vector3 operator*(float lhs, const Vector3 &rhs)
	{
		return rhs * lhs;
	}
	friend void operator*=(float lhs, Vector3 &rhs)
	{
		rhs *= lhs;
	}

	~Vector3();

	float x;
	float y;
	float z;
};

#endif