#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Square.h"
#include "TBinTree.h"


int main(int argc, char** argv)
{
	std::cout << " 'h' for help" << std::endl;
	const int size = 8;
	char s[size];

	Quadratum quadratum;
	TBinTree tree;
	int side;
	while (1)
	{
		std::cin.getline(s, size);
		std::cin.clear();
		std::cin.sync();
		if (strcmp(s, "q") == 0)
			break;
		else if (strcmp(s, "p") == 0)
			std::cout << tree << std::endl;
		else if (strcmp(s, "i") == 0)
		{
			std::cout << " Insertion: Enter square side: ";
			std::cin >> quadratum;
			tree.Insert(quadratum);
		}
		else if (strcmp(s, "d") == 0)
		{
			std::cout << " Deletion: Enter square side: ";
			std::cin >> side;
			tree.Delete(side);
		}
		else if (strcmp(s, "f") == 0)
		{
			std::cout << " Search: Enter square side: ";
			std::cin >> side;
			TItem *data = tree.Find(side);
			if (data == nullptr)
				std::cout << " Not found\n";
			else
				std::cout << " Found: " << *data << "\n";
		}
		else if (strcmp(s, "h") == 0)
		{
			std::cout << "\n i        insert a square in the tree";
			std::cout << "\n p        print binary tree";
			std::cout << "\n f        find a square in the tree";
			std::cout << "\n d        delete a square from the tree";
			std::cout << "\n q        exit the program\n\n";
		}
	}
	return 0;
}