#include "IGladiboxer.h"
#include "Decision.h"

IGladiboxer::IGladiboxer()
{
}

IGladiboxer::~IGladiboxer()
{
}

Warrior::Warrior(Stats a_stats, IGladiboxer * a_opponent)
{
	m_stats = a_stats;
	m_hasShield = true;
	m_shieldDurability = 10;
	m_opponent = a_opponent;
	m_decisionTree.push_back(new IsOpponentAlive(this));

}

Warrior::~Warrior()
{

}

void Warrior::Update(float dt)
{
	this->Smith::Update(dt);
}

int Warrior::GetDurability()
{
	return m_shieldDurability;
}

Archer::Archer(Stats a_stats, IGladiboxer * a_opponent)
{

	m_stats = a_stats;
	m_arrows = 25;
	m_maxArrows = 25;
	m_opponent = a_opponent;

	m_arrowInFlight = false;

	m_quiver.resize(m_maxArrows);
	m_quiver.shrink_to_fit();

	m_decisionTree.push_back(new IsOpponentAlive(this));

}

Archer::~Archer()
{

}

void Archer::Update(float dt)
{
	m_arrows = m_quiver.size();
	this->Smith::Update(dt);
}

int Archer::GetAmmo()
{
	return m_arrows;
}