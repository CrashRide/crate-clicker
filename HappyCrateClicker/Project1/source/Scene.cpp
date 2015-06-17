#include "Scene.h"
#include "MathLib.h"
using namespace MathLib;

Scene::Scene(SceneNode*firstBorn)
{
	m_scene_root = firstBorn;
}

Scene::~Scene()
{
	delete m_scene_root;
}

SceneNode::SceneNode()
{
	m_parent = nullptr;
	m_local_transform = new Matrix3x3();
	m_global_transform = new Matrix3x3();
}

SceneNode::SceneNode(Matrix3x3*local, Matrix3x3*global)
{
	m_parent = nullptr;
	m_local_transform = local;
	m_global_transform = global;
}

SceneNode::~SceneNode()
{
	if (m_local_transform == m_global_transform)
	{
		delete m_local_transform;
	}
	else
	{
		delete m_local_transform;
		delete m_global_transform;
	}
}

void Scene::UpdateTransforms()
{
	m_scene_root->UpdateTransforms();
}

void SceneNode::SetParent(SceneNode*rhs)
{
	m_parent = rhs;
}

void SceneNode::AddChild(SceneNode*rhs)
{
	m_children.push_back(rhs);
	rhs->SetParent(this);
}

void SceneNode::RemoveChild(SceneNode*rhs)
{
	int found = -1;
	for (unsigned int i = 0; i < m_children.size(); ++i)
	{
		if (m_children[i] == rhs)
		{
			found = i;
			i = m_children.size();
		}
	}
	if (found >= 0)
	{
		m_children.erase(m_children.begin() + found);
		rhs->SetParent(nullptr);
	}	
}

void SceneNode::UpdateTransforms()
{
	if (m_parent != nullptr)
		*m_global_transform = *m_parent->m_global_transform * *m_local_transform;
	else
		m_global_transform = m_local_transform;
	for (unsigned int i = 0; i < m_children.size(); i++)
	{
		m_children[i]->UpdateTransforms();
	}
}

Matrix3x3* SceneNode::GetLocal()
{
	return m_local_transform;
}

Matrix3x3* SceneNode::GetGlobal()
{
	return m_global_transform;
}

void SceneNode::SetLocal(Matrix3x3 &rhs)
{
	*m_local_transform = rhs;
}
