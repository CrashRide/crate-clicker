#ifndef _GAMEOBJ_H_
#define _GAMEOBJ_H_
#include "MathLib.h"
#include "Scene.h"
using namespace MathLib;

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

	Vector2 m_pos;
	Vector2 m_scale;
	float m_velo;
	float m_rot;
	SceneNode m_localTrans;
};


#endif