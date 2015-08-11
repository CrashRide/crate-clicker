#include "IGladiboxer.h"
#include "Decision.h"
#include "IFeels.h"
#include "Texture.h"

IGladiboxer::IGladiboxer()
{
}

IGladiboxer::~IGladiboxer()
{
}

Warrior::Warrior(Stats a_stats, Archer * a_opponent)
{
	wep = Sword();
	m_objTexture = new Texture("./Images/box0_256.png");
	m_stats = a_stats;
	m_hasShield = true;
	m_shieldDurability = 10;
	m_opponent = a_opponent;
	m_decisionTreeRoot = new IsOpponentAlive(this);
	m_decisionTreeRoot->m_trueDecision = new IsAttackUseful(this);
	m_decisionTreeRoot->m_trueDecision->m_trueDecision = new AttackAction(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision = new IsProjectileInFlight(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision = new IsObjectAvoidable(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision = new Action(this, new PursueFeels(m_opponent, 1.0f));
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision->m_trueDecision = new Action(this, new EvadeFeels(m_opponent->m_shot, 1.0f));
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
	else
	{
		delete  shieldTex;
		shieldTex = nullptr;
	}
	this->Smith::Update(dt);
}

void Warrior::Attack()
{
	wep.Init(this, new Texture("./Images/warriorSword.png"));
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

Archer::Archer(Stats a_stats, Warrior * a_opponent)
{

	m_stats = a_stats;
	m_arrows = 25;
	m_maxArrows = 25;
	m_opponent = a_opponent;

	m_objTexture = new Texture("./Images/box0_256.png");

	m_arrowInFlight = false;

	m_shot = Arrow();

	m_quiver.resize(m_maxArrows);
	m_quiver.shrink_to_fit();

	m_decisionTreeRoot = new IsOpponentAlive(this);
	m_decisionTreeRoot->m_trueDecision = new IsAdrenalineActive(this);
	m_decisionTreeRoot->m_trueDecision->m_trueDecision = new AttackAction(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision = new IsAttackUseful(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_trueDecision = m_decisionTreeRoot->m_trueDecision->m_trueDecision;
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision = new IsNumberTooLow(this);
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision->m_trueDecision = new Action(this, new SeekFeels(m_strayArrowTarget, 1.0f));
	m_decisionTreeRoot->m_trueDecision->m_falseDecision->m_falseDecision->m_falseDecision = new Action(this, new EvadeFeels(m_opponent, 1.0f));

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
	this->Smith::Update(dt);
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