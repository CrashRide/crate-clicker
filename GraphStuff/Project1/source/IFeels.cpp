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

SeekFeels::SeekFeels(const GameObj * a_target)
{
	m_target = a_target;
	m_type = 'S';
}


SeekFeels::~SeekFeels()
{
}

void SeekFeels::Update(Smith * a_smith)
{
	Vector2 temp = (m_target->GetPos() - a_smith->GetPos()).Normalised() * 250;
	a_smith->ApplyForce(temp - a_smith->m_vVelo);
}

const GameObj* SeekFeels::GetTarget()const
{
	return m_target;
}

FleeFeels::FleeFeels(const GameObj * a_target)
{
	m_target = a_target;
	m_type = 'F';
}


FleeFeels::~FleeFeels()
{
}

void FleeFeels::Update(Smith * a_smith)
{
	Vector2 temp = (a_smith->GetPos() - m_target->GetPos()).Normalised() * 250;
	a_smith->ApplyForce(temp - a_smith->m_vVelo);
}

const GameObj* FleeFeels::GetTarget()const
{
	return m_target;
}

WanderFeels::WanderFeels(float a_wanderRadius, float a_wanderDistance, float a_jitter)
{
	m_wanderRadius = a_wanderRadius;
	m_wanderDistance = a_wanderDistance;
	m_jitter = a_jitter;
	m_type = 'W';
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
	Vector2 temp = (m_pastSeekPos - a_smith->GetPos()).Normalised() * 250;
	a_smith->ApplyForce(temp - a_smith->m_vVelo);
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