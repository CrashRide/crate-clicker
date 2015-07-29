#pragma once

#include "Smith.h"

struct Stats
{
	float HP = 0.f;
	float ATKDMG = 0.f;
	float ATKSPD = 0.f;
	float MVESPD = 0.f;
};

class IGladiboxer : Smith
{
public:
	IGladiboxer();
	virtual ~IGladiboxer();

	virtual void Update(float dt) = 0;

protected:

	Stats m_stats;
	bool m_adrenalineMode = false;
	bool m_alive = true;

};

class Warrior : IGladiboxer
{
public:

	Warrior(Stats a_stats);
	~Warrior();

	void Update(float dt);

private:

	int m_shieldDurability;
	bool m_hasShield;

};

class Archer : IGladiboxer
{
public:

	Archer(Stats a_stats);
	~Archer();

	void Update(float dt);

private:

	int m_arrows;

};

