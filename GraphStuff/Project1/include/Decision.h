#pragma once

class Smith;

class Decision
{
public:
	Decision(Smith * a_owner);
	virtual ~Decision();

	virtual void MakeDecision(float dt) = 0;

protected: 

	Smith * m_owner;

};

class BoolDecision : public Decision
{
public:

	BoolDecision(Smith * a_owner);
	~BoolDecision();

	void MakeDecision(float dt);

	Decision * m_trueDecision;
	Decision * m_falseDecision;

	bool m_tof;

};

