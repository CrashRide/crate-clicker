#pragma once
#include "GameObj.h"
#include <list>
#include "SpriteBatch.h"
class IFeels;

class Smith : public GameObj
{
public:
	Smith();
	Smith(Vector2& a_startPos);
	~Smith();
	
	virtual void Update(float dt);
	//void Draw(SpriteBatch*a_spriteBatch);
	void AddFeels(IFeels *a_feel);
	void RemoveFeels(IFeels * a_feel);

protected:

	std::list<IFeels*> m_feels;

};

