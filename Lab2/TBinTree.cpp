#include <iostream>
#include <cstdlib>
//#define DEBUG 1
#include "TBinTree.h"

TBinTree::TBinTree()
{
	root = nullptr;
}

void TBinTree::Insert(const TItem& val)
{
	if (root == nullptr)
		root = new TNode(val);
	else
	{
		TNode *currNode = root;
		TNode *leafNode = nullptr;
		while (currNode != nullptr)
		{
			leafNode = currNode;
			if (val < currNode->data)
				currNode = currNode->left;
			else
				currNode = currNode->right;
		}
		if (val < leafNode->data)
			leafNode->left = new TNode(val);
		else
			leafNode->right = new TNode(val);
	}
}

TItem *TBinTree::Find(size_t side)
{
	if (root == nullptr)
		return nullptr;
	else
	{
		Quadratum quad_search(side);
		TNode *currNode = root;
		while (currNode != nullptr)
		{
			if (quad_search < currNode->data)
				currNode = currNode->left;
			else if (quad_search > currNode->data)
				currNode = currNode->right;
			else
				return &(currNode->data);
		}
	}
	return nullptr;
}

TBinTree::TNode *TBinTree::MinValueTNode(TNode *node)
{
	TNode *current = node;

	while (current->left != nullptr)
		current = current->left;

	return current;
}

void TBinTree::DeleteNode(TNode *node)
{
	if (node == nullptr)
		return;

	DeleteNode(node->left);
	DeleteNode(node->right);
	delete node;
}

TBinTree::TNode *TBinTree::deleteTNode(TNode *_root, TItem& key)
{
	if (_root == nullptr) return _root;

	if (key < _root->data)
		_root->left = deleteTNode(_root->left, key);
	else if (key > _root->data)
		_root->right = deleteTNode(_root->right, key);
	else {
		if (_root->left == nullptr)
		{
			TNode *temp = _root->right;
			delete _root;
			return temp;
		}
		else if (_root->right == nullptr)
		{
			TNode *temp = _root->left;
			delete _root;
			return temp;
		}

		TNode *temp = MinValueTNode(_root->right);
		_root->data = temp->data;
		_root->right = deleteTNode(_root->right, temp->data);
	}
	return _root;
}

bool TBinTree::Delete(size_t side)
{
	Quadratum quad_search(side);
	root = deleteTNode(root, quad_search);
	return false;
}

std::ostream& TBinTree::InOrderPrint(std::ostream& os, TNode *node, size_t level) const
{
	if (node != nullptr)
	{
		InOrderPrint(os, node->left, level + 1);
		for (size_t i = 0; i < level; i++)
			os << '\t';
		os << node->data;
		InOrderPrint(os, node->right, level + 1);
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const TBinTree& bintree)
{
	if (bintree.IsEmpty())
		os << "Empty tree\n";
	else
		os << "===============================================\n";
	bintree.InOrderPrint(os, bintree.root, 0);
	os << "===============================================\n\n";
	return os;
}

bool TBinTree::IsEmpty() const
{
	return (root == nullptr);
}

TBinTree::~TBinTree()
{
	DeleteNode(root);
	root = nullptr;
#ifdef DEBUG
	std::cout << "Tree deleted\n";
#endif // DEBUG 
}

TBinTree::TNode::TNode()
{
#ifdef DEBUG
	std::cout << "TNode constructor (default)\n";
#endif // DEBUG

	left = nullptr;
	right = nullptr;
}

TBinTree::TNode::TNode(const TItem& data)
{
#ifdef DEBUG
	std::cout << "TNode constructor (data)\n";
#endif // DEBUG

	left = nullptr;
	right = nullptr;
	this->data = data;
}