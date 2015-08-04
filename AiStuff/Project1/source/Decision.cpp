#include "Decision.h"
#include "Smith.h"
#include "IFeels.h"
#include "IGladiboxer.h"

Decision::Decision(Smith * a_owner)
{
	m_owner = a_owner;
}

Decision::~Decision()
{

}

BoolDecision::BoolDecision(Smith * a_owner) :Decision(a_owner)
{
	m_trueDecision = nullptr;
	m_falseDecision = nullptr;

	m_tof = false;
}

BoolDecision::~BoolDecision()
{

}

void BoolDecision::MakeDecision(float dt)
{
	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);
}

IsOpponentAlive::IsOpponentAlive(IGladiboxer * a_owner) :BoolDecision(a_owner)
{
	m_owner = a_owner;

	m_tof = m_owner->m_alive;

	m_trueDecision = nullptr;
	m_falseDecision = nullptr;

}

IsOpponentAlive::~IsOpponentAlive()
{

}

void IsOpponentAlive::MakeDecision(float dt)
{
	m_tof = m_owner->m_opponent->m_alive;
	BoolDecision::MakeDecision(dt);
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

	if (m_enemyType == 'W' && m_owner->GetAmmo() > 0 && ((m_owner->GetPos() - m_owner->m_opponent->GetPos()).SqrMagnatude() / m_owner->m_opponent->m_vVelo.SqrMagnatude()) > m_owner->m_stats.ATKSPD)
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

IsNumberTooLow::IsNumberTooLow(Archer * a_owner) :BoolDecision(a_owner)
{
	m_owner = a_owner;
	m_ownerType = 'A';
}

IsNumberTooLow::IsNumberTooLow(Warrior * a_owner) : BoolDecision(a_owner)
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
	
	//farts

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