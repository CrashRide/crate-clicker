#include "Smith.h"
#include "IFeels.h"

Smith::Smith(Vector2& a_startPos)
{
	SetPos(a_startPos);
}

Smith::~Smith()
{
	for (auto iter = m_feels.begin(); iter != m_feels.end() ; iter++)
	{
		delete (*iter);
	}

	m_feels.clear();
}

void Smith::Update(float dt)
{
	for (auto iter = m_feels.begin(); iter != m_feels.end(); iter++)
	{
		(*iter)->Update(this);
		
	}
	this->GameObj::Update(dt);
}

//void Smith::Draw(SpriteBatch*a_spriteBatch)
//{
//
//	for (auto iter = m_feels.begin(); iter != m_feels.end(); iter++)
//	{
//		(*iter)->DebugDraw(a_spriteBatch);
//
//	}
//
//}

void Smith::AddFeels(IFeels * a_feel)
{
	m_feels.push_back(a_feel);
}