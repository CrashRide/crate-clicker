#pragma once

#include <list>
#include "Smith.h"

class Decision;

struct Stats
{
	float HP = 0.f;
	float ATKDMG = 0.f;
	float ATKSPD = 0.f;
	float MVESPD = 0.f;
	float ATKRNG = 0.f;
};

class IGladiboxer : public Smith
{
public:
	IGladiboxer();
	virtual ~IGladiboxer();

	virtual void Update(float dt) = 0;
	virtual void ActivateAdrenaline() = 0;
	virtual void Attack() = 0;

	virtual int GetAmmo() = 0;
	virtual int GetDurability() = 0;

	std::list<Decision*> m_decisionTree;

	Stats m_stats;
	IGladiboxer * m_opponent;
	bool m_adrenalineMode = false;
	bool m_alive = true;

};

class Warrior : public IGladiboxer
{
public:

	Warrior(Stats a_stats, IGladiboxer * a_opponent);
	~Warrior();

	void Update(float dt);
	void Attack();
	void Block();
	void ActivateAdrenaline();

	int GetDurability();

private:

	int m_shieldDurability;
	bool m_hasShield;

};

class Archer : public IGladiboxer
{
public:

	Archer(Stats a_stats, IGladiboxer * a_opponent);
	~Archer();

	void Update(float dt);
	void Attack();
	void ActivateAdrenaline();

	int GetAmmo();

	GameObj * m_shot = nullptr;
	bool m_arrowInFlight;

private:

	int m_arrows;
	int m_maxArrows;
	vector<GameObj*> m_quiver;

};

