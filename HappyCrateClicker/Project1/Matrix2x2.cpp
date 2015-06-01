#include "Matrix2x2.h"
#include "Vector2.h"

Matrix2x2::Matrix2x2()
{
	float m_mat[2][2] =
	{
		{ 1, 0 },
		{ 0, 1 },
	};
}

Matrix2x2::Matrix2x2(const Vector2 &rowOne, const Vector2 &rowTwo)
{

}


Matrix2x2::~Matrix2x2()
{
}
