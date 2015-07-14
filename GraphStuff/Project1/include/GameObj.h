#ifndef _GAMEOBJ_H_
#define _GAMEOBJ_H_
#include "MathLib.h"
#include "Scene.h"
using namespace MathLib;
class SpriteBatch;
class GameObj
{
public:

	GameObj();
	~GameObj();

	void SetPos(Vector2 &rhs);
	void Translate(Vector2 &rhs);
	Vector2 GetPos();

	void SetRot(float a_rad);
	void Rot(float a_rad);
	float GetRot();

	void SetScale(Vector2 &rhs);
	void Scale(Vector2 &rhs);
	Vector2 GetScale();

	void UpdateMat();

	virtual void Draw(const SpriteBatch m_spritebatch);
	virtual void Update(const float dt);

	Vector2 m_disp;
	Vector2 m_vVelo;
	Vector2 m_uVelo;
	Vector2 m_accel;
	float m_mass;
	SceneNode m_localTrans;


private:


	Vector2 m_pos;
	Vector2 m_scale;
	float m_rot;

};


#endif