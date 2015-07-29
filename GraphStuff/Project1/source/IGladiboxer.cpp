#include "IGladiboxer.h"

IGladiboxer::IGladiboxer()
{
}

IGladiboxer::~IGladiboxer()
{
}

Warrior::Warrior(Stats a_stats)
{
	m_stats = a_stats;
	m_hasShield = true;
	m_shieldDurability = 10;
}

void Warrior::Update(float dt)
{

}

Archer::Archer(Stats a_stats)
{
	m_stats = a_stats;
	m_arrows = 25;
}

Archer::~Archer()
{

}

void Archer::Update(float dt)
{

}