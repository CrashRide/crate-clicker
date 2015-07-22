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
		this->GameObj::Update(dt);
		if (m_vVelo.SqrMagnatude() >= (m_maxVelo * m_maxVelo))
		{
			m_vVelo.Normalise();
			m_vVelo *= m_maxVelo;
			break;
		}
	}
	cout << GetPos().x << " , " << GetPos().y << endl;
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

void Smith::AddFeels(IFeels *a_feel)
{
	bool exists = false;
	for (auto iter = m_feels.begin(); iter != m_feels.end(); iter++)
	{
		if ((*iter)->GetTarget() == a_feel->GetTarget() && (*iter)->m_type == a_feel->m_type)
		{
			exists = true;
			m_feels.remove((*iter));
			break;
		}
	}
	if (!exists)
	{
		m_feels.push_back(a_feel);
	}
}