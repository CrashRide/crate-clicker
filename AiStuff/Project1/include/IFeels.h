#pragma once
#include "MathLib.h"
using namespace MathLib;

class Smith;
class IGladiboxer;
class SpriteBatch;
class IGladiboxer;
class IFeels
{
public:
	IFeels();
	virtual ~IFeels();

	virtual void Update(Smith* a_smith) = 0;
	virtual void DebugDraw(SpriteBatch * a_spriteBatch) {};

	virtual  IGladiboxer* GetTarget() = 0;

	//weight is a percentage of priority, a number between 0 and 1 incluisive.
	float m_weight;
	char m_type;
};

class SeekFeels : public IFeels
{
public:
	SeekFeels( IGladiboxer * a_target, float);
	~SeekFeels();

	 IGladiboxer* GetTarget();
	void Update(Smith * a_smith);

private:
	 IGladiboxer * m_target;
};

class PursueFeels : public IFeels
{
public:
	PursueFeels( IGladiboxer*, float);
	~PursueFeels();

	 IGladiboxer* GetTarget();
	void Update(Smith * a_smith);

private:
	 IGladiboxer * m_owner;
};

class ArrivalFeels : public IFeels
{
public:
	ArrivalFeels( IGladiboxer * a_target, float, float);
	~ArrivalFeels();

	 IGladiboxer* GetTarget();
	void Update(Smith * a_smith);

private:
	 IGladiboxer * m_target;
	float m_radius;
};

class FleeFeels : public IFeels
{
public:
	FleeFeels( IGladiboxer * a_target, float);
	~FleeFeels();

	 IGladiboxer* GetTarget();
	void Update(Smith * a_smith);

private:
	 IGladiboxer * m_target;
};

class EvadeFeels : public IFeels
{
public:
	EvadeFeels(IGladiboxer * a_owner, float);
	~EvadeFeels();

	 IGladiboxer* GetTarget();
	void Update(Smith * a_smith);

private:
	IGladiboxer * m_owner;
};

class WanderFeels : public IFeels
{
public:
	WanderFeels(float a_wanderRadius, float a_wanderDistance, float a_jitter, float);
	~WanderFeels();
	
	void Update(Smith * a_smith);
	void DebugDraw(SpriteBatch * a_spriteBatch);

	 IGladiboxer* GetTarget();
private:
	float m_wanderRadius;
	float m_wanderDistance;
	float m_jitter;

	Vector2 m_pastSeekPos;
	
	Vector2 testPos;
	Vector2 testPos2;
};
