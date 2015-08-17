#include "IGladiboxer.h"
#include "Decision.h"
#include "IFeels.h"
#include "Texture.h"
#include "SpriteBatch.h"

IGladiboxer::IGladiboxer()
{
	m_adrenalineMode = false;
	m_attacking = false;
	m_alive = true;
	m_opponent = nullptr;
}

IGladiboxer::~IGladiboxer()
{
}

Warrior::Warrior(Stats a_stats)
{
	wep = Sword();
	m_objTexture = new Texture("./Images/box0_256.png");
	SetPos(Vector2(100.0, 100.0));
	SetScale(Vector2(0.1f, 0.1f));
	m_stats = a_stats;
	m_maxVelo = m_stats.MVESPD;
	m_hasShield = true;
	m_shieldDurability = 10;
	m_opponent = nullptr;
	m_decisionTreeRoot = new IsOpponentAlive(this);
	m_decisionTreeRoot->m_trueDecision = new IsAttackUseful(this);
	m_decisionTreeRoot->m_trueDecision->m_trueDecision = new AttackAction(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision = new IsProjectileInFlight(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision = new IsObjectAvoidable(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision = new Action(this, new PursueFeels(this, 1.0f));
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision->m_trueDecision = new Action(this, new EvadeFeels(this, 1.0f));
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision->m_falseDecision = new IsNumberTooLow(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision->m_falseDecision->m_trueDecision = new KnockBackAction(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision->m_falseDecision->m_falseDecision = new BlockAction(this);
}

Warrior::~Warrior()
{

}

void Warrior::Update(float dt)
{
	m_decisionTreeRoot->MakeDecision(dt);
	if (m_attacking)
		wep.Swing(dt);
	else if (m_blocking)
		m_vVelo = Vector2(0.f, 0.f);
	else if ((m_opponent)->m_attacking)
	{
		if (m_collider.BoxCollision(static_cast<Archer*>(m_opponent)->m_shot.m_collider))
		{
			m_stats.HP -= (m_opponent)->m_stats.ATKDMG;
		}
	}
	else
	{
		delete  shieldTex;
		shieldTex = nullptr;
	}
	this->Smith::Update(dt);
}

void Warrior::Draw(SpriteBatch * a_spritebatch)
{

	this->Smith::Draw(a_spritebatch);
	if (m_blocking)
	{
		a_spritebatch->DrawSprite(shieldTex, (GetPos() + (m_heading * (float)m_objTexture->GetWidth())).x, (GetPos() + (m_heading * (float)m_objTexture->GetHeight())).y, (float)shieldTex->GetWidth(), (float)shieldTex->GetHeight(), m_heading.AngleOf());
	}

}

void Warrior::Attack()
{
	wep.Init(this);
	m_attacking = true;

}

void Warrior::Block()
{

	shieldTex = new Texture("./Images/warriorShield.png");
	m_blocking = true;

}

int Warrior::GetDurability()
{
	return m_shieldDurability;
}

Archer::Archer(Stats a_stats)
{

	m_stats = a_stats;
	m_maxVelo = m_stats.MVESPD;
	m_arrows = 25;
	m_maxArrows = 25;
	m_opponent = nullptr;

	SetPos(Vector2(500.0, 300.0));
	m_objTexture = new Texture("./Images/box0_256.png");
	SetScale(Vector2(0.1f, 0.1f));

	m_arrowInFlight = false;

	m_shot = Arrow();

	m_quiver.resize(m_maxArrows);
	m_quiver.shrink_to_fit();

	m_decisionTreeRoot = new IsOpponentAlive(this);
	m_decisionTreeRoot->m_trueDecision = new IsAdrenalineActive(this);
	m_decisionTreeRoot->m_trueDecision->m_trueDecision = new AttackAction(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision = new IsAttackUseful(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision = new AttackAction(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision = new IsNumberTooLow(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision->m_trueDecision = new Action(this, new SeekFeels(this, 1.0f));
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision->m_falseDecision = new Action(this, new EvadeFeels(this, 1.0f));

}

Archer::~Archer()
{

}

void Archer::Update(float dt)
{
	m_arrows = m_quiver.size();
	m_decisionTreeRoot->MakeDecision(dt);
	if (m_attacking)
		m_shot.Flight(dt);
	if ((m_opponent)->m_attacking)
	{
		if (m_collider.BoxCollision(static_cast<Warrior*>(m_opponent)->wep.m_collider))
		{
			m_stats.HP -= (m_opponent)->m_stats.ATKDMG;
			ApplyForce((GetPos() - (m_opponent)->GetPos()).Normalised() * (m_opponent)->m_stats.ATKRNG);
		}
	}
	this->Smith::Update(dt);
}

void Archer::Draw(SpriteBatch * a_spritebatch)
{
	this->Smith::Draw(a_spritebatch);
	if (m_arrowInFlight)
	{
		m_shot.Draw(a_spritebatch);
	}
}

void Archer::Attack()
{
	m_attacking = true;
	m_shot.Init(this, new Texture("./Images/Arrow.png"));

}

int Archer::GetAmmo()
{
	return m_arrows;
}