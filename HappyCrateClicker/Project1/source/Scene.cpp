#include "Scene.h"
#include "Matrix3x3.h"

SceneNode::SceneNode()
{
	m_local_transform = new Matrix3x3();
	m_global_transform = new Matrix3x3();
}

Scene::Scene(SceneNode*firstBorn)
{
	m_scene_root->AddChild(firstBorn);
}

Scene::~Scene()
{
	delete m_scene_root;
}

SceneNode::SceneNode(Matrix3x3*local, Matrix3x3*global)
{
	m_local_transform = local;
	m_global_transform = global;
}

SceneNode::~SceneNode()
{
	delete m_local_transform;
	delete m_global_transform;
	delete m_children.data();
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
	m_parent->m_children.push_back(rhs);
	rhs->SetParent(m_parent);
}

void SceneNode::RemoveChild(SceneNode*rhs)
{
	int found = -1;
	for (int i = 0; i < m_children.size(); ++i)
	{
		if (m_children[i] == rhs)
		{
			found = i;
			break;
		}
	}
	if (found >= 0)
	{
		m_children.erase(m_children.begin() + found);
	}
}

void SceneNode::UpdateTransforms()
{
	if (m_parent != nullptr)
		*m_global_transform = *m_local_transform * *m_parent->m_global_transform;
	else
		m_global_transform = m_local_transform;
	for (int i = 0; i < m_children.size(); ++i)
	{
		m_children[i]->UpdateTransforms();
	}
}


