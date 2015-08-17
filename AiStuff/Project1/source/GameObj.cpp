#include "GameObj.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Scene.h"

GameObj::GameObj()
{
	m_pos = Vector2(0.0f, 0.0f);
	m_scale = Vector2(1.f, 1.f);
	m_rot = 0.0f;
	m_mass = 1.0f;
	m_uVelo.x = 0.0f;
	m_uVelo.y = 0.0f;
	m_objTexture = nullptr;
	m_friction = 0.95f;
	m_heading = Vector2(0.0f, 1.0f);
	m_maxVelo = 0.f;
	m_collider = Box(Vector2(-1.f, 1.f), Vector2(1.f, 1.f));
}

GameObj::GameObj(Texture* a_objTex, float a_maxVelo)
{
	m_pos = Vector2(0.0f, 0.0f);
	m_scale = Vector2(0.1f, 0.1f);
	m_rot = 0.0f;
	m_mass = 1.0f;
	m_uVelo.x = 0.0f;
	m_uVelo.y = 0.0f;
	m_friction = 0.95f;
	m_heading = Vector2(0.0f, 1.0f);
	m_objTexture = a_objTex;
	m_maxVelo = a_maxVelo;
	m_collider = Box(Vector2(m_pos.x - ((m_objTexture->GetWidth()*m_scale.x) / 2), m_pos.y + ((m_objTexture->GetHeight()*m_scale.y) / 2)), Vector2(m_pos.x + ((m_objTexture->GetWidth()*m_scale.x) / 2), m_pos.y - ((m_objTexture->GetHeight()*m_scale.y) / 2)));
}

GameObj::~GameObj()
{
	if (m_objTexture != nullptr)
	{
		delete m_objTexture;
		m_objTexture = nullptr;
	}
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

void GameObj::ApplyForce(Vector2 &rhs)
{
	m_force += rhs;
}

Vector2 GameObj::GetPos() const
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

void GameObj::Update(float dt)
{
	m_vVelo *= m_friction;
	m_accel = m_force / m_mass;
	m_vVelo += m_accel * dt;
	m_pos += m_vVelo * dt;
	m_accel = Vector2(0.0f, 0.0f);
	m_force = Vector2(0.0f, 0.0f);
	UpdateMat();
	if (m_vVelo < Vector2(0.00001f, 0.00001f) && m_vVelo > Vector2(-0.00001f, -0.00001f))
	{
		m_vVelo = Vector2(0.0f, 0.0f);
		m_heading = Vector2(0.0f, 1.0f);
	}
	else
		m_heading = m_vVelo.Normalised();
	if (m_objTexture != nullptr)
		m_collider = Box(Vector2(m_pos.x - ((m_objTexture->GetWidth()*m_scale.x) / 2), m_pos.y + ((m_objTexture->GetHeight()*m_scale.y) / 2)), Vector2(m_pos.x + ((m_objTexture->GetWidth()*m_scale.x) / 2), m_pos.y - ((m_objTexture->GetHeight()*m_scale.y) / 2)));
	else
		m_collider = Box();
}

void GameObj::Draw(SpriteBatch* m_spritebatch)
{
	m_spritebatch->DrawSpriteTransformed3x3(m_objTexture, &m_localTrans.GetLocal()->m_mat[0][0], m_objTexture->GetWidth(), m_objTexture->GetHeight());
}