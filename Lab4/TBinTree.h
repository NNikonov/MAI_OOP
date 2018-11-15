#ifndef TBINTREE_H
#define TBINTREE_H

#include "Square.h"
#include "Rectangle.h"
#include "Trapezium.h"
#include <memory>
//#define DEBUG 1

template <class T>
class TNode;

template <class T>
using TNodePtr = std::shared_ptr<TNode<T> >;

template <class T>
class TNode
{
public:
	TNode();
	TNode(std::shared_ptr<T> data);
	TNodePtr<T> left;
	TNodePtr<T> right;
	std::shared_ptr<T> data;
};

template <class T>
class TBinTree
{
private:
	TNodePtr<T> root;
	TNodePtr<T> MinValueTreeNode(TNodePtr<T> node);
	TNodePtr<T> deleteTreeNode(TNodePtr<T> _root, std::shared_ptr<T> key);
	std::ostream &InOrderPrint(std::ostream &os, TNodePtr<T> node, size_t level) const;
public:
	TBinTree();
	void Insert(std::shared_ptr<T> val);
	bool IsEmpty() const;
	std::shared_ptr<T> Find(std::shared_ptr<T> key);
	void DeleteNode(std::shared_ptr<T> key);

	template <class A> friend std::ostream &operator<<(std::ostream &os, TBinTree<A> &bintree);

	virtual ~TBinTree();
};

template <class T>
TBinTree<T>::TBinTree()
{
	root = nullptr;
}

template <class T>
void TBinTree<T>::Insert(std::shared_ptr<T> val)
{
	if (root == nullptr)
	{
		root = TNodePtr<T>(new TNode<T>(val));
		return;
	}
	else
	{
		TNodePtr<T> currNode = root;
		TNodePtr<T> leafNode = nullptr;
		while (currNode != nullptr)
		{
			leafNode = currNode;
			if (val->SquareLess(currNode->data))
				currNode = currNode->left;
			else
				currNode = currNode->right;
		}
		if (val->SquareLess(leafNode->data))
			leafNode->left = TNodePtr<T>(new TNode<T>(val));
		else
			leafNode->right = TNodePtr<T>(new TNode<T>(val));
	}
}

template <class T>
std::shared_ptr<T> TBinTree<T>::Find(std::shared_ptr<T> key)
{
	if (root == nullptr) return nullptr;

	TNodePtr<T> currNode = root;
	TNodePtr<T> leafNode = nullptr;
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

template<class T>
TNodePtr<T> TBinTree<T>::MinValueTreeNode(TNodePtr<T> node)
{
	TNodePtr<T> current = node;

	while (current->left != nullptr)
		current = current->left;

	return current;
}

template<class T>
void TBinTree<T>::DeleteNode(std::shared_ptr<T> key)
{
	if (key == nullptr)
		return;

	root = deleteTreeNode(root, key);
}

template<class T>
TNodePtr<T> TBinTree<T>::deleteTreeNode(TNodePtr<T> _root, std::shared_ptr<T> key)
{
	if (_root == nullptr) return _root;

	if (key->EqualFigures(_root->data))
	{
		if (_root->left == nullptr)
		{
			TNodePtr<T> temp = _root->right;
			std::cout << " Figure deleted " << std::endl;
			return temp;
		}
		else if (_root->right == nullptr)
		{
			TNodePtr<T> temp = _root->left;
			std::cout << " Figure deleted " << std::endl;
			return temp;
		}

		TNodePtr<T> temp = MinValueTreeNode(_root->right);
		_root->data = temp->data;
		_root->right = deleteTreeNode(_root->right, temp->data);
	}
	else if (key->SquareLess(_root->data))
		_root->left = deleteTreeNode(_root->left, key);
	else
		_root->right = deleteTreeNode(_root->right, key);

	return _root;
}

template<class T>
std::ostream &TBinTree<T>::InOrderPrint(std::ostream &os, TNodePtr<T> node, size_t level) const
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

template <class A>
std::ostream &operator<<(std::ostream &os, TBinTree<A> &bintree)
{
	if (bintree.IsEmpty())
		os << "Empty tree\n";
	else
		os << "===============================================\n";
	bintree.InOrderPrint(os, bintree.root, 0);
	os << "===============================================\n\n";
	return os;
}

template <class T>
bool TBinTree<T>::IsEmpty() const
{
	return (root == nullptr);
}

template <class T>
TBinTree<T>::~TBinTree()
{
	root = nullptr;
#ifdef DEBUG
	std::cout << "Tree deleted\n";
#endif // DEBUG 
}

template <class T>
TNode<T>::TNode()
{
#ifdef DEBUG
	std::cout << "TNode constructor (default)\n";
#endif // DEBUG

	left = nullptr;
	right = nullptr;
}

template <class T>
TNode<T>::TNode(std::shared_ptr<T> data)
{
#ifdef DEBUG
	std::cout << "TNode constructor (data)\n";
#endif // DEBUG

	left = nullptr;
	right = nullptr;
	this->data = data;
}

#endif