#include "Decision.h"
#include "Smith.h"
#include "IFeels.h"
#include "IGladiboxer.h"

Decision::Decision(Smith * a_owner)
{
	m_owner = a_owner;
	m_trueDecision = nullptr;
	m_falseDecision = nullptr;

}

Decision::~Decision()
{

}

BoolDecision::BoolDecision(Smith * a_owner) :Decision(a_owner)
{
	m_tof = false;
}

BoolDecision::~BoolDecision()
{

}

//void BoolDecision::MakeDecision(float dt)
//{
//	if (m_tof)
//		m_trueDecision->MakeDecision(dt);
//	else
//		m_falseDecision->MakeDecision(dt);
//}

IsOpponentAlive::IsOpponentAlive(IGladiboxer * a_owner) :BoolDecision(a_owner)
{
	m_owner = a_owner;

	m_tof = true;

	m_trueDecision = nullptr;
	m_falseDecision = nullptr;

}

IsOpponentAlive::~IsOpponentAlive()
{

}

void IsOpponentAlive::MakeDecision(float dt)
{

	switch (m_owner->m_stats.CLASS)
	{
	case 'W':
		m_tof = static_cast<Archer*>(m_owner->m_opponent)->m_alive;
		break;
	case 'A':
		m_tof = static_cast<Warrior*>(m_owner->m_opponent)->m_alive;
		break;
	default:
		break;
	}

	
	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);
}

IsAdrenalineActive::IsAdrenalineActive(IGladiboxer * a_owner) :BoolDecision(a_owner)
{

	m_owner = a_owner;

	m_trueDecision = nullptr;
	m_falseDecision = nullptr;

	m_tof = m_owner->m_adrenalineMode;

}

IsAdrenalineActive::~IsAdrenalineActive()
{
}

void IsAdrenalineActive::MakeDecision(float dt)
{

	m_tof = m_owner->m_adrenalineMode;

	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);

}

IsAttackUseful::IsAttackUseful(Warrior * a_owner) :BoolDecision(a_owner)
{

	m_owner = a_owner;

	m_trueDecision = nullptr;
	m_falseDecision = nullptr;
	
	m_enemyType = 'A';
}

IsAttackUseful::IsAttackUseful(Archer * a_owner) :BoolDecision(a_owner)
{

	m_owner = a_owner;

	m_trueDecision = nullptr;
	m_falseDecision = nullptr;

	m_enemyType = 'W';
}

IsAttackUseful::~IsAttackUseful()
{
}

void IsAttackUseful::MakeDecision(float dt)
{

	if (m_enemyType == 'W' && !static_cast<Archer*>(m_owner)->m_arrowInFlight && m_owner->GetAmmo() > 0 && ((m_owner->GetPos() - m_owner->m_opponent->GetPos()).SqrMagnatude() / m_owner->m_opponent->m_vVelo.SqrMagnatude()) > m_owner->m_stats.ATKSPD)
		m_tof = true;
	else if (m_enemyType == 'A' && (m_owner->GetPos() - m_owner->m_opponent->GetPos()).SqrMagnatude() < (m_owner->m_stats.ATKRNG * m_owner->m_stats.ATKRNG))
		m_tof = true;
	else
		m_tof = false;

	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);

}

IsProjectileInFlight::IsProjectileInFlight(Warrior * a_owner) :BoolDecision(a_owner)
{
	m_owner = a_owner;
}

IsProjectileInFlight::~IsProjectileInFlight()
{

}

void IsProjectileInFlight::MakeDecision(float dt)
{

	m_tof = static_cast<Archer*>(m_owner->m_opponent)->m_arrowInFlight;

	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);

}

IsNumberTooLow::IsNumberTooLow(Archer * a_owner) :BoolDecision(a_owner)
{
	m_owner = a_owner;
	m_ownerType = 'A';
}

IsNumberTooLow::IsNumberTooLow(Warrior * a_owner) :BoolDecision(a_owner)
{
	m_owner = a_owner;
	m_ownerType = 'W';

}

IsNumberTooLow::~IsNumberTooLow()
{

}

void IsNumberTooLow::MakeDecision(float dt)
{
	switch (m_ownerType)
	{
	case 'W':
		if (m_owner->GetDurability() > 0)
			m_tof = false;
		else
			m_tof = true;
		break;
	case'A':
		if (m_owner->GetAmmo() > 0)
			m_tof = false;
		else
			m_tof = true;
		break;
	}

	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);
}

IsObjectAvoidable::IsObjectAvoidable(IGladiboxer * a_owner) :BoolDecision(a_owner)
{
	m_owner = a_owner;
}

IsObjectAvoidable::~IsObjectAvoidable()
{
}

void IsObjectAvoidable::MakeDecision(float dt)
{
	Archer* acrher = static_cast<Archer*>(m_owner->m_opponent);
	float timeTillCollision = acrher->m_shot.m_vVelo.SqrMagnatude();
	Vector2 temp = (m_owner->GetPos() - acrher->m_shot.GetPos() + (acrher->m_shot.m_vVelo).Normalised() * m_owner->m_maxVelo);
	Vector2 futurePos = m_owner->GetPos() + (m_owner->m_vVelo * 0.95f) + ((m_owner->m_force + (temp - m_owner->m_vVelo)) * timeTillCollision);
	GameObj tempWarrior(m_owner->m_objTexture, m_owner->m_maxVelo);
	tempWarrior.SetPos(futurePos);
	tempWarrior.Update(dt);
	//box collision with line
	if (tempWarrior.m_collider.LineCollision(acrher->GetPos(), acrher->m_shot.m_vVelo))
		m_tof = false;
	else
		m_tof = true;

	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);

}

AttackAction::AttackAction(IGladiboxer * a_owner) :Decision(a_owner)
{
	m_owner = a_owner;
}

AttackAction::~AttackAction()
{

}

void AttackAction::MakeDecision(float dt)
{
	m_owner->Attack();
}

BlockAction::BlockAction(Warrior * a_owner) :Decision(a_owner)
{
	m_owner = a_owner;
}

BlockAction::~BlockAction()
{
}

void BlockAction::MakeDecision(float dt)
{
	m_owner->Block();
}

KnockBackAction::KnockBackAction(Warrior * a_owner) :Decision(a_owner)
{
	m_owner = a_owner;
}

KnockBackAction::~KnockBackAction()
{

}

void KnockBackAction::MakeDecision(float dt)
{
	if (m_owner->m_collider.BoxCollision(static_cast<Archer*>(m_owner->m_opponent)->m_shot.m_collider))
	{
		m_owner->ApplyForce(static_cast<Archer*>(m_owner->m_opponent)->m_shot.m_vVelo / 10);
		static_cast<Archer*>(m_owner->m_opponent)->m_arrowInFlight = false;
	}
}

Action::Action(Smith * a_owner, IFeels * a_action) :Decision(a_owner)
{
	m_action = a_action;
}

Action::~Action()
{

}

void Action::MakeDecision(float dt)
{
	m_owner->AddFeels(m_action);
}