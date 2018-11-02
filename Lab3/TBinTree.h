#ifndef TBINTREE_H
#define TBINTREE_H

#include "Square.h"
#include "Rectangle.h"
#include "Trapezium.h"

typedef Quadratum TItem;

class TBinTree
{
private:
	class TNode
	{
	public:
		TNode();
		TNode(std::shared_ptr<Figure> data);
		std::shared_ptr<TNode> left;
		std::shared_ptr<TNode> right;
		std::shared_ptr<Figure> data;
	};

	std::shared_ptr<TNode> root;
	void DeleteNode(std::shared_ptr<TNode> node);
public:
	TBinTree();
	void Insert(std::shared_ptr<Figure> val);
	bool IsEmpty() const;
	std::shared_ptr<Figure> Find(std::shared_ptr<Figure> key);
	void DeleteNode(std::shared_ptr<Figure> key);
	std::shared_ptr<TNode> MinValueTreeNode(std::shared_ptr<TNode> node);
	std::shared_ptr<TNode> deleteTreeNode(std::shared_ptr<TNode> _root, std::shared_ptr<Figure> key);
	std::ostream& InOrderPrint(std::ostream& os, std::shared_ptr<TNode> node, size_t level) const;

	friend std::ostream& operator<<(std::ostream& os, const TBinTree& bintree);

	virtual ~TBinTree();
};

#endif