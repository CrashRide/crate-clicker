#pragma once

#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#define new DBG_NEW
#endif

#define _USE_MATH_DEFINES
#include <math.h>

#include <list>
#include "Smith.h"
#include "Texture.h"

class Decision;
class SpriteBatch;
class Archer;
class IsOpponentAlive;


struct Stats
{
	Stats()
	{
		HP = 0.f;
		ATKDMG = 0.f;
		ATKSPD = 0.f;
		MVESPD = 0.f;
		ATKRNG = 0.f;
	}
	Stats(float hp, float ad, float as, float ms, float ar, char cls)
	{
		HP = hp;
		ATKDMG = ad;
		ATKSPD = as;
		MVESPD = ms;
		ATKRNG = ar;
		CLASS = cls;
	}
	float HP;
	float ATKDMG;
	float ATKSPD;
	float MVESPD;
	float ATKRNG;
	char CLASS;
};

class IGladiboxer : public Smith
{
public:
	IGladiboxer();
	virtual ~IGladiboxer();

	virtual void Update(float dt) = 0;
	virtual void ActivateAdrenaline() = 0;
	virtual void Attack() = 0;
	virtual void Draw(SpriteBatch * a_spritebatch) = 0;

	virtual void PlantTree() = 0;

	virtual int GetAmmo() = 0;
	virtual int GetDurability() = 0;

	IsOpponentAlive * m_decisionTreeRoot;

	Stats m_stats;

	IGladiboxer * m_opponent;

	bool m_adrenalineMode;
	bool m_attacking;
	bool m_alive;

};

class Warrior : public IGladiboxer
{
public:

	Warrior(Stats a_stats);
	~Warrior();

	void Update(float dt);
	void Draw(SpriteBatch * a_spritebatch);
	void Attack();
	void Block();
	void ActivateAdrenaline(){}

	void PlantTree();

	int GetDurability();
	int GetAmmo(){ return NULL; }

	bool m_blocking = false;

	//Archer * m_opponent;

	class Sword : public GameObj
	{
	public:
		Sword(){ m_owner = nullptr; };
		Sword(Warrior * a_owner)
		{
			m_owner = a_owner;
			m_objTexture = new Texture("./Images/warriorSword.png");
		}
		~Sword(){}

		void Init()
		{

			SetPos(m_owner->GetPos());
			SetRot(m_owner->m_heading.AngleOf() - ((float)M_PI / 2));
			
		}

		void End()
		{
			//delete this;
			m_owner->m_attacking = false;
		}

		void Swing(float dt)
		{
			Rot(dt * m_owner->m_stats.ATKSPD * (float)M_PI);
			if (GetRot() > ((float)M_PI / 2))
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

	Archer(Stats a_stats);
	~Archer();

	void Update(float dt);
	void Draw(SpriteBatch * a_spritebatch);
	void Attack();
	void ActivateAdrenaline(){}

	void PlantTree();

	int GetAmmo();
	int GetDurability(){ return NULL; }

	class Arrow : public GameObj
	{
	public:
		Arrow(){ m_owner = nullptr; };
		Arrow(Archer * a_owner)
		{
			m_owner = a_owner;
			m_objTexture = new Texture("./Images/Arrow.png");
		}
		~Arrow(){}

		void Init()
		{
			m_maxVelo = 500.f;
			m_friction = 1.f;
			SetPos(m_owner->GetPos());
			SetRot(((m_owner->m_opponent)->GetPos() - GetPos()).AngleOf());
			ApplyForce(((m_owner->m_opponent)->GetPos() - GetPos()).Normalised() * m_owner->m_stats.ATKRNG);
		}

		void End()
		{
			//delete this;
			m_owner->m_attacking = false;
		}

		void Flight(float dt)
		{
			flightTime += dt;
			Update(dt);
			if (m_collider.BoxCollision((m_owner->m_opponent)->m_collider))
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

	//Warrior * m_opponent;

private:

	int m_arrows;
	int m_maxArrows;
	vector<GameObj*> m_quiver;

};

