#pragma once

#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#define new DBG_NEW
#endif

#include "GameObj.h"
#include <list>
class SpriteBatch;
class IFeels;

class Smith : public GameObj
{
public:
	Smith();
	Smith(Vector2& a_startPos);
	~Smith();
	
	virtual void Update(float dt);
	virtual void Draw(SpriteBatch * a_spriteBatch);
	void AddFeels(IFeels *a_feel);
	void RemoveFeels(IFeels * a_feel);
	

protected:

	std::list<IFeels*> m_feels;
};

