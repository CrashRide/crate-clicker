#include "GameObj.h"

GameObj::GameObj()
{
	m_pos = Vector2(1.0f, 1.0f);
	m_scale = Vector2(1.0f,1.0f);
	m_rot = 0.0f;
	m_velo.x = 1.0f;
	m_velo.y = 1.0f;
}

GameObj::~GameObj()
{
}

void GameObj::SetPos(Vector2 &rhs)
{
	m_pos = rhs;
	UpdateMat();
}

void GameObj::Translate(Vector2 &rhs)
{
	SetPos(rhs + m_pos);
}

Vector2 GameObj::GetPos()
{
	return m_pos;
}

void GameObj::SetRot(float a_rad)
{
	m_rot = a_rad;
	UpdateMat();
}

void GameObj::Rot(float a_rad)
{
	SetRot(m_rot + a_rad);
}

float GameObj::GetRot()
{
	return m_rot;
}

void GameObj::SetScale(Vector2 &rhs)
{
	m_scale = rhs;
	UpdateMat();
}

void GameObj::Scale(Vector2 &rhs)
{
	SetScale(m_scale + rhs);
}

Vector2 GameObj::GetScale()
{
	return m_scale;
}

void GameObj::UpdateMat()
{
	Matrix3x3 temp = Matrix3x3::CreateTranslateMat(m_pos.x, m_pos.y) * Matrix3x3::CreateRotateMat(m_rot) * Matrix3x3::CreateScaleMat(m_scale.x, m_scale.y);
	m_localTrans.SetLocal(temp);
}