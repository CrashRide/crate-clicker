#pragma once

class BinaryTreeNode;

class BinaryTree
{
public:
	BinaryTree(BinaryTreeNode* a_rootNode);
	~BinaryTree();

private:

	BinaryTreeNode* m_rootNode;

};