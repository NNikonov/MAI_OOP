#include <iostream>
#include <cstdlib>
#include <memory>
//#define DEBUG 1
#include "TBinTree.h"

TBinTree::TBinTree()
{
	root = nullptr;
}

void TBinTree::Insert(std::shared_ptr<Figure> val)
{
	if (root == nullptr)
	{
		root = std::make_shared<TBinTree::TNode>(val);
		return;
	}
	else
	{
		std::shared_ptr<TBinTree::TNode> currNode = root;
		std::shared_ptr<TBinTree::TNode> leafNode = nullptr;
		while (currNode != nullptr)
		{
			leafNode = currNode;
			if (val->SquareLess(currNode->data))
				currNode = currNode->left;
			else
				currNode = currNode->right;
		}
		if (val->SquareLess(leafNode->data))
			leafNode->left = std::make_shared<TBinTree::TNode>(val);
		else
			leafNode->right = std::make_shared<TBinTree::TNode>(val);
	}
}

std::shared_ptr<Figure> TBinTree::Find(std::shared_ptr<Figure> key)
{
	if (root == nullptr) return nullptr;

	std::shared_ptr<TBinTree::TNode> currNode = root;
	std::shared_ptr<TBinTree::TNode> leafNode = nullptr;
	while (currNode != nullptr)
	{
		leafNode = currNode;
		if (key->EqualFigures(currNode->data))
			return currNode->data;
		if (key->SquareLess(currNode->data))
			currNode = currNode->left;
		else
			currNode = currNode->right;
	}

	return nullptr;
}

std::shared_ptr<TBinTree::TNode> TBinTree::MinValueTreeNode(std::shared_ptr<TBinTree::TNode> node)
{
	std::shared_ptr<TBinTree::TNode> current = node;

	while (current->left != nullptr)
		current = current->left;

	return current;
}

void TBinTree::DeleteNode(std::shared_ptr<Figure> key)
{
	if (key == nullptr)
		return;

	root = deleteTreeNode(root, key);

}

std::shared_ptr<TBinTree::TNode>  TBinTree::deleteTreeNode(std::shared_ptr<TBinTree::TNode> _root, std::shared_ptr<Figure> key)
{
	if (_root == nullptr) return _root;

	if (key->EqualFigures(_root->data))
	{
		if (_root->left == nullptr)
		{
			std::shared_ptr<TBinTree::TNode> temp = _root->right;
			std::cout << " Figure deleted " << std::endl;
			return temp;
		}
		else if (_root->right == nullptr)
		{
			std::shared_ptr<TBinTree::TNode> temp = _root->left;
			std::cout << " Figure deleted " << std::endl;
			return temp;
		}

		std::shared_ptr<TBinTree::TNode> temp = MinValueTreeNode(_root->right);
		_root->data = temp->data;
		_root->right = deleteTreeNode(_root->right, temp->data);
	}
	else if (key->SquareLess(_root->data))
		_root->left = deleteTreeNode(_root->left, key);
	else
		_root->right = deleteTreeNode(_root->right, key);

	return _root;
}

std::ostream& TBinTree::InOrderPrint(std::ostream& os, std::shared_ptr<TBinTree::TNode> node, size_t level) const
{
	if (node != nullptr)
	{
		InOrderPrint(os, node->left, level + 1);
		for (size_t i = 0; i < level; i++)
			os << '\t';
		(node->data)->print(os);
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

TBinTree::TNode::TNode(std::shared_ptr<Figure> data)
{
#ifdef DEBUG
	std::cout << "TNode constructor (data)\n";
#endif // DEBUG

	left = nullptr;
	right = nullptr;
	this->data = data;
}