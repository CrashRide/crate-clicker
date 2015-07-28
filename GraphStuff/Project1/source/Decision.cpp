#include "Decision.h"]
#include "Smith.h"

Decision::Decision(Smith * a_owner)
{
	m_owner = a_owner;
}

Decision::~Decision()
{

}

BoolDecision::BoolDecision(Smith * a_owner) :Decision(a_owner)
{
	m_trueDecision = nullptr;
	m_falseDecision = nullptr;

	m_tof = false;
}

BoolDecision::~BoolDecision()
{

}

void BoolDecision::MakeDecision(float dt)
{
	if (m_tof)
		m_trueDecision->MakeDecision(dt);
	else
		m_falseDecision->MakeDecision(dt);
}