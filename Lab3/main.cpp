#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "TBinTree.h"


int main(int argc, char** argv)
{
	std::cout << " 'h' for help" << std::endl;
	const int size = 8;
	char s[size];

	TBinTree tree;
	std::shared_ptr<Figure> ptr_fig, ptr2;
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
			std::cout << " Which figure do you want to insert? (squ/rec/tra): ";
			std::cin.getline(s, size);
			std::cin.clear();
			std::cin.sync();

			if (strcmp(s, "squ") == 0)
			{
				ptr_fig = std::make_shared<Quadratum>(std::cin);
			}
			else if (strcmp(s, "rec") == 0)
			{
				ptr_fig = std::make_shared<Rectangle>(std::cin);
			}
			else if (strcmp(s, "tra") == 0)
			{
				ptr_fig = std::make_shared<Trapezium>(std::cin);
			}
			else
			{
				std::cout << " Invalid choice! " << std::endl;
				continue;
			}
			tree.Insert(ptr_fig);
		}
		else if (strcmp(s, "d") == 0)
		{
			std::cout << " Which figure do you want to delete? (squ/rec/tra): ";
			std::cin.getline(s, size);
			std::cin.clear();
			std::cin.sync();

			if (strcmp(s, "squ") == 0)
			{
				ptr_fig = std::make_shared<Quadratum>(std::cin);
			}
			else if (strcmp(s, "rec") == 0)
			{
				ptr_fig = std::make_shared<Rectangle>(std::cin);
			}
			else if (strcmp(s, "tra") == 0)
			{
				ptr_fig = std::make_shared<Trapezium>(std::cin);
			}
			else
			{
				std::cout << " Invalid choice! " << std::endl;
				continue;
			}
			tree.DeleteNode(ptr_fig);
		}
		else if (strcmp(s, "f") == 0)
		{
			std::cout << " Which figure do you want to find? (squ/rec/tra): ";
			std::cin.getline(s, size);
			std::cin.clear();
			std::cin.sync();

			if (strcmp(s, "squ") == 0)
			{
				ptr_fig = std::make_shared<Quadratum>(std::cin);
			}
			else if (strcmp(s, "rec") == 0)
			{
				ptr_fig = std::make_shared<Rectangle>(std::cin);
			}
			else if (strcmp(s, "tra") == 0)
			{
				ptr_fig = std::make_shared<Trapezium>(std::cin);
			}
			else
			{
				std::cout << " Invalid choice! " << std::endl;
				continue;
			}
			if (tree.Find(ptr_fig) != nullptr)
				std::cout << " The figure was FOUND\n";
			else
				std::cout << " The figure was NOT FOUND\n";
		}
		else if (strcmp(s, "h") == 0)
		{
			std::cout << "\n i        insert a figure in the tree";
			std::cout << "\n p        print binary tree";
			std::cout << "\n f        find a figure in the tree";
			std::cout << "\n d        delete a figure from the tree";
			std::cout << "\n q        exit the program\n\n";
		}
	}
	return 0;
}