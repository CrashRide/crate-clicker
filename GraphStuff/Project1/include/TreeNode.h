#pragma once

class TreeNode 
{
public:
	TreeNode();
	virtual ~TreeNode();

	TreeNode* m_leftChild;
	TreeNode* m_rightChild;
	
private:

};

class BinaryTreeNode : public TreeNode
{
public:
	BinaryTreeNode(float);
	~BinaryTreeNode();

private:
	float m_data;
};