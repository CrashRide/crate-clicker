#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

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

	Decision* m_decisionTreeRoot;

	Stats m_stats;

	IGladiboxer * m_opponent;

	bool m_adrenalineMode = false;
	bool m_attacking = false;
	bool m_alive = true;

};

class Warrior : public IGladiboxer
{
public:

	Warrior(Stats a_stats, Archer * a_opponent);
	~Warrior();

	void Update(float dt);
	void Attack();
	void Block();
	void ActivateAdrenaline();

	int GetDurability();

	bool m_blocking = false;

	Archer * m_opponent;

	class Sword : public GameObj
	{
	public:
		Sword()
		{
			m_owner = nullptr;
		}
		~Sword();

		void Init(Warrior * a_owner, Texture* a_tex)
		{
			m_owner = a_owner;
			SetPos(m_owner->GetPos());
			SetRot(m_owner->m_heading.AngleOf() - (M_PI / 2));
			m_objTexture = a_tex;
		}

		void End()
		{
			delete this;
			*this = Sword();
		}

		void Swing(float dt)
		{
			Rot(dt * m_owner->m_stats.ATKSPD * M_PI);
			if (GetRot() > (M_PI / 2))
			{
				m_owner->m_attacking = false;
				End();
			}
		}

		Warrior * m_owner;
	};

	Sword wep;
	Texture * shieldTex = nullptr;

private:

	int m_shieldDurability;
	bool m_hasShield;

};

class Archer : public IGladiboxer
{
public:

	Archer(Stats a_stats, Warrior * a_opponent);
	~Archer();

	void Update(float dt);
	void Attack();
	void ActivateAdrenaline();

	int GetAmmo();

	class Arrow : public GameObj
	{
	public:
		Arrow()
		{
			m_owner = nullptr;
		}
		~Arrow();

		void Init(Archer * a_owner, Texture* a_tex)
		{
			m_owner = a_owner;
			m_maxVelo = 500.f;
			m_friction = 1.f;
			SetPos(m_owner->GetPos());
			SetRot((m_owner->m_opponent->GetPos() - GetPos()).AngleOf());
			ApplyForce((m_owner->m_opponent->GetPos() - GetPos()).Normalised() * m_owner->m_stats.ATKRNG);
			m_objTexture = a_tex;
		}

		void End()
		{
			delete this;
			*this = Arrow();
		}

		void Flight(float dt)
		{
			flightTime += dt;
			Update(dt);
			if (m_collider.BoxCollision(m_owner->m_opponent->m_collider))
				End();
			else if ((flightTime * m_maxVelo) >= m_owner->m_stats.ATKRNG)
				End();
		}

		Archer * m_owner;
		float flightTime = 0.f;
	};

	Arrow m_shot;
	GameObj * m_strayArrowTarget;
	bool m_arrowInFlight;

	Warrior * m_opponent;

private:

	int m_arrows;
	int m_maxArrows;
	vector<GameObj*> m_quiver;

};

