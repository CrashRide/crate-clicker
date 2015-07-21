#pragma once
#include "MathLib.h"
using namespace MathLib;

class Smith;
class GameObj;
class SpriteBatch;
class IFeels
{
public:
	IFeels();
	virtual ~IFeels();

	virtual void Update(Smith* a_smith) = 0;
	virtual void DebugDraw(SpriteBatch * a_spriteBatch) {};

	virtual const GameObj* GetTarget()const = 0;

	char m_type;
};

class SeekFeels : public IFeels
{
public:
	SeekFeels(const GameObj * a_target);
	~SeekFeels();

	const GameObj* GetTarget()const;
	void Update(Smith * a_smith);

private:
	const GameObj * m_target;
};

class FleeFeels : public IFeels
{
public:
	FleeFeels(const GameObj * a_target);
	~FleeFeels();

	const GameObj* GetTarget()const;
	void Update(Smith * a_smith);

private:
	const GameObj * m_target;
};

class WanderFeels : public IFeels
{
public:
	WanderFeels(float a_wanderRadius, float a_wanderDistance, float a_jitter);
	~WanderFeels();
	
	void Update(Smith * a_smith);
	void DebugDraw(SpriteBatch * a_spriteBatch);

	const GameObj* GetTarget()const;
private:
	float m_wanderRadius;
	float m_wanderDistance;
	float m_jitter;

	Vector2 m_pastSeekPos;
	
	Vector2 testPos;
	Vector2 testPos2;
};
