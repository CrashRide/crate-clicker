#ifndef _GAMEOBJ_H_
#define _GAMEOBJ_H_
#include "MathLib.h"
#include "Scene.h"
using namespace MathLib;
class SpriteBatch;
class Texture;

class GameObj
{
public:

	GameObj();
	virtual ~GameObj();

	void SetPos(Vector2 &rhs);
	void Translate(Vector2 &rhs);
	Vector2 GetPos()const;

	void ApplyForce(Vector2 &rhs);

	void SetRot(float a_rad);
	void Rot(float a_rad);
	float GetRot();

	void SetScale(Vector2 &rhs);
	void Scale(Vector2 &rhs);
	Vector2 GetScale();

	void UpdateMat();

	virtual void Draw(SpriteBatch* m_spritebatch);
	virtual void Update(float dt);

	Vector2 m_disp;
	Vector2 m_vVelo;
	Vector2 m_uVelo;
	Vector2 m_accel;
	float m_mass = 1.0f;
	Vector2 m_force;
	SceneNode m_localTrans;
	Texture* m_objTexture;
	float m_friction;
	Vector2 m_heading;

private:


	Vector2 m_pos;
	Vector2 m_scale;
	float m_rot;

};


#endif