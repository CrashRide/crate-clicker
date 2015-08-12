#include "IFeels.h"
#include "Smith.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "SpriteBatch.h"
IFeels::IFeels()
{
}


IFeels::~IFeels()
{
}

SeekFeels::SeekFeels(const GameObj * a_target, float a_weight)
{
	m_target = a_target;
	m_type = 'S';
	if (a_weight > 1.0f)
		m_weight = 1.0f;
	else if (a_weight < 0.0f)
		m_weight = 0.0f;
	else
		m_weight = a_weight;
}


SeekFeels::~SeekFeels()
{
}

void SeekFeels::Update(Smith * a_smith)
{
	Vector2 temp = (m_target->GetPos() - a_smith->GetPos()).Normalised() * a_smith->m_maxVelo;
	a_smith->ApplyForce((temp - a_smith->m_vVelo) * m_weight);
}

const GameObj* SeekFeels::GetTarget()const
{
	return m_target;
}

PursueFeels::PursueFeels(const GameObj * a_target, float a_weight)
{
	m_target = a_target;
	m_type = 'P';
	if (a_weight > 1.0f)
		m_weight = 1.0f;
	else if (a_weight < 0.0f)
		m_weight = 0.0f;
	else
		m_weight = a_weight;
}

PursueFeels::~PursueFeels()
{
}

void PursueFeels::Update(Smith * a_smith)
{
	Vector2 temp = ((m_target->GetPos() + m_target->m_vVelo) - a_smith->GetPos()).Normalised() * a_smith->m_maxVelo;
	a_smith->ApplyForce((temp - a_smith->m_vVelo) * m_weight);
}

const GameObj* PursueFeels::GetTarget()const
{
	return m_target;
}

ArrivalFeels::ArrivalFeels(const GameObj * a_target, float a_weight, float a_radius)
{
	m_target = a_target;
	m_type = '@';
	m_radius = a_radius;
	if (a_weight > 1.0f)
		m_weight = 1.0f;
	else if (a_weight < 0.0f)
		m_weight = 0.0f;
	else
		m_weight = a_weight;
}


ArrivalFeels::~ArrivalFeels()
{
}

void ArrivalFeels::Update(Smith * a_smith)
{
	Vector2 temp = (m_target->GetPos() - a_smith->GetPos()).Normalised() * a_smith->m_maxVelo;
	if ((m_target->GetPos() - a_smith->GetPos()).Magnatude() / m_radius < a_smith->m_maxVelo)
	{
		a_smith->m_vVelo.Normalise();
		a_smith->m_vVelo *= (m_target->GetPos() - a_smith->GetPos()).Magnatude() / m_radius;
	}
	else
	{
		a_smith->m_vVelo.Normalise();
		a_smith->m_vVelo *= a_smith->m_maxVelo;
	}
	a_smith->ApplyForce((temp - a_smith->m_vVelo) * m_weight);
}

const GameObj* ArrivalFeels::GetTarget()const
{
	return m_target;
}

FleeFeels::FleeFeels(const GameObj * a_target, float a_weight)
{
	m_target = a_target;
	m_type = 'F';
	if (a_weight > 1.0f)
		m_weight = 1.0f;
	else if (a_weight < 0.0f)
		m_weight = 0.0f;
	else
		m_weight = a_weight;
}


FleeFeels::~FleeFeels()
{
}

void FleeFeels::Update(Smith * a_smith)
{
	Vector2 temp = (a_smith->GetPos() - m_target->GetPos()).Normalised() * a_smith->m_maxVelo;
	a_smith->ApplyForce((temp - a_smith->m_vVelo) * m_weight);
}

const GameObj* FleeFeels::GetTarget()const
{
	return m_target;
}

EvadeFeels::EvadeFeels(GameObj * a_target, float a_weight)
{
	m_target = a_target;
	m_type = 'E';
	if (a_weight > 1.0f)
		m_weight = 1.0f;
	else if (a_weight < 0.0f)
		m_weight = 0.0f;
	else
		m_weight = a_weight;
}


EvadeFeels::~EvadeFeels()
{
}

void EvadeFeels::Update(Smith * a_smith)
{
	Vector2 temp = (a_smith->GetPos() - (m_target->GetPos() + m_target->m_vVelo)).Normalised() * a_smith->m_maxVelo;
	a_smith->ApplyForce((temp - a_smith->m_vVelo) * m_weight);
}

const GameObj* EvadeFeels::GetTarget()const
{
	return m_target;
}

WanderFeels::WanderFeels(float a_wanderRadius, float a_wanderDistance, float a_jitter, float a_weight)
{
	m_wanderRadius = a_wanderRadius;
	m_wanderDistance = a_wanderDistance;
	m_jitter = a_jitter;
	m_type = 'W';
	if (a_weight > 1.0f)
		m_weight = 1.0f;
	else if (a_weight < 0.0f)
		m_weight = 0.0f;
	else
		m_weight = a_weight;
}

WanderFeels::~WanderFeels()
{
}

void WanderFeels::Update(Smith * a_smith)
{

	if ((m_pastSeekPos - a_smith->GetPos()).Magnatude() < 5 || m_pastSeekPos == Vector2(0.0f, 0.0f))
	{
		//get random target on circle
		float randomRot = (rand() % 360) * (M_PI / 180.0f);
		//std::cout << randomRot << std::endl;
		Vector2 randVec(cos(randomRot), sin(randomRot));
		Vector2 randPos = (randVec * m_wanderRadius);

		//randomised jitter vector
		randomRot = (rand() % 360) * (M_PI / 180.0f);

		Vector2 randJitterVec(cos(randomRot), sin(randomRot));
		randJitterVec *= m_jitter;

		Vector2 circleTarget = (randPos + randJitterVec).Normalised() * m_wanderRadius;


		Vector2 finalSeekPosition = a_smith->GetPos() + circleTarget + (a_smith->m_heading * m_wanderDistance);


		//testPos2 = finalSeekPosition;
		//testPos = a_smith->GetPos();

		//seek to final seek position

		m_pastSeekPos = finalSeekPosition;
	}
	Vector2 temp = (m_pastSeekPos - a_smith->GetPos()).Normalised() * a_smith->m_maxVelo;
	a_smith->ApplyForce((temp - a_smith->m_vVelo) * m_weight);
	//std::cout << (m_pastSeekPos - a_smith->GetPos()).Magnatude() << std::endl;
}

void WanderFeels::DebugDraw(SpriteBatch * a_spriteBatch)
{
	a_spriteBatch->DrawLine(testPos.x, testPos.y, testPos2.x, testPos2.y, 2.0f);


}

const GameObj* WanderFeels::GetTarget()const
{
	return nullptr;
}