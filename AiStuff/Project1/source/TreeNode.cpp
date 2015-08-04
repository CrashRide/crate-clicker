#include "TreeNode.h"

TreeNode::TreeNode()
{
	m_leftChild = nullptr;
	m_rightChild = nullptr;
}

TreeNode::~TreeNode()
{
	if (m_leftChild != nullptr)
	{
		delete m_leftChild;
	}
	if (m_rightChild != nullptr)
	{
		delete m_rightChild;
	}
}

BinaryTreeNode::BinaryTreeNode(float a_data)
{
	m_leftChild = nullptr;
	m_rightChild = nullptr;
}

BinaryTreeNode::~BinaryTreeNode()
{
	if (m_leftChild != nullptr)
	{
		delete m_leftChild;
	}
	if (m_rightChild != nullptr)
	{
		delete m_rightChild;
	}
}