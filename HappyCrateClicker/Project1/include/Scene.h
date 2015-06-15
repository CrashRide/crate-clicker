#ifndef  _SCENE_H_
#define _SCENE_H_
#include <vector>

class Matrix3x3;

class SceneNode
{
public:
	SceneNode();
	SceneNode(Matrix3x3*, Matrix3x3*);
	~SceneNode();
	void SetParent(SceneNode*);
	void AddChild(SceneNode*);
	void RemoveChild(SceneNode*);
	void UpdateTransforms();
	Matrix3x3* GetLocal();
	Matrix3x3* GetGlobal();
	void SetLocal(Matrix3x3 &rhs);
protected:
	
	std::vector<SceneNode*> m_children;
	SceneNode* m_parent;
	
	Matrix3x3* m_local_transform;
	
	Matrix3x3* m_global_transform;
};

class Scene
{
public:
	Scene(SceneNode*);
	~Scene();
	void UpdateTransforms();
private:
	SceneNode* m_scene_root;
};


#endif