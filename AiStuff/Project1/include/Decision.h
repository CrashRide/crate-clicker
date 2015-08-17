#pragma once

#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#define new DBG_NEW
#endif

class Smith;
class IFeels;
class IGladiboxer;
class Warrior;
class Archer;

class Decision
{
public:

	Decision();
	Decision(Smith * a_owner);
	virtual ~Decision();

	virtual void MakeDecision(float dt) = 0;

	Decision * m_trueDecision = nullptr;
	Decision * m_falseDecision = nullptr;

protected: 

	Smith * m_owner;

};

class BoolDecision : public Decision
{
public:

	BoolDecision(){}
	BoolDecision(Smith * a_owner);
	virtual ~BoolDecision();

	virtual void MakeDecision(float dt) = 0;

	bool m_tof;

};

class IsOpponentAlive : public BoolDecision
{
public:

	IsOpponentAlive(IGladiboxer * a_owner);
	~IsOpponentAlive();

	void MakeDecision(float dt);

	IGladiboxer * m_owner;

};

class IsAdrenalineActive : public BoolDecision
{
public:

	IsAdrenalineActive(IGladiboxer * a_owner);
	~IsAdrenalineActive();

	void MakeDecision(float dt);

	IGladiboxer * m_owner;

};

class IsAttackUseful : public BoolDecision
{
public:

	IsAttackUseful(Warrior * a_owner);
	IsAttackUseful(Archer * a_owner);

	~IsAttackUseful();

	void MakeDecision(float dt);

	IGladiboxer * m_owner;
	char m_enemyType;

};

class IsProjectileInFlight : public BoolDecision
{
public:

	IsProjectileInFlight(Warrior * a_owner);
	~IsProjectileInFlight();

	void MakeDecision(float dt);

	Warrior * m_owner;

};

class IsNumberTooLow : public BoolDecision
{
public:

	IsNumberTooLow(Archer * a_owner);
	IsNumberTooLow(Warrior * a_owner);
	~IsNumberTooLow();

	void MakeDecision(float dt);

	IGladiboxer * m_owner;
	char m_ownerType;

};

class IsObjectAvoidable : public BoolDecision
{
public:

	IsObjectAvoidable(IGladiboxer * a_owner);
	~IsObjectAvoidable();

	void MakeDecision(float dt);

	IGladiboxer * m_owner;

};

class AttackAction : public Decision
{
public:

	AttackAction(IGladiboxer * a_owner);
	~AttackAction();

	void MakeDecision(float dt);

	IGladiboxer * m_owner;

};

class BlockAction : public Decision
{
public:

	BlockAction(Warrior * a_owner);
	~BlockAction();

	void MakeDecision(float dt);

	Warrior * m_owner;

};

class KnockBackAction : public Decision
{
public:

	KnockBackAction(Warrior * a_owner);
	~KnockBackAction();

	void MakeDecision(float dt);

	Warrior * m_owner;

};

class Action : public Decision
{
public:

	Action(Smith * a_owner, IFeels * a_action);
	~Action();

	void MakeDecision(float dt);

private:

	IFeels * m_action;

};