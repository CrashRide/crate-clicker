#include "TreeNode.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree(BinaryTreeNode* a_rootNode)
{
	m_rootNode = a_rootNode;
}

BinaryTree::~BinaryTree()
{
	delete m_rootNode;
}