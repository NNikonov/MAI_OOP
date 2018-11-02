#ifndef TBINTREE_H
#define TBINTREE_H

#include "Square.h"

typedef Quadratum TItem;

class TBinTree
{
private:
	class TNode
	{
	public:
		TNode();
		TNode(const TItem& data);
		TNode *left;
		TNode *right;
		TItem data;
	};

	TNode *root;
	void DeleteNode(TNode *node);
public:
	TBinTree();
	void Insert(const TItem& val);
	bool IsEmpty() const;
	TItem *Find(size_t side);
	bool Delete(size_t side);
	TNode *MinValueTNode(TNode *node);
	TNode *deleteTNode(TNode *_root, TItem& key);
	std::ostream& InOrderPrint(std::ostream& os, TNode *node, size_t level) const;

	friend std::ostream& operator<<(std::ostream& os, const TBinTree& bintree);

	virtual ~TBinTree();
};

#endif