#include <cstdlib>
#include "Square.h"
#include "Rectangle.h"
#include "Trapezium.h"

int main(int argc, char** argv)
{
	int k;
	std::cout << "Choose a figure:\n 1 - Square\n 2 - Rectangle\n 3 - Trapezium" << std::endl;
	std::cin >> k;
	if (k == 1) // Square
	{
		std::cout << "Enter square side: " << std::endl;
		Figure *S = new Quadratum(std::cin);
		S->Print();
		std::cout << "Square = " << S->Square() << std::endl;
		delete S;
	}
	if (k == 2) // Rectangle
	{
		std::cout << "Enter rectangle sides: " << std::endl;
		Figure *R = new Rectangle(std::cin);
		R->Print();
		std::cout << "Square = " << R->Square() << std::endl;
		delete R;
	}
	if (k == 3) // Trapezium
	{
		std::cout << "Enter trapezium sides (2 bases, then 2 legs): " << std::endl;
		Figure *T = new Trapezium(std::cin);
		T->Print();
		std::cout << "Square = " << T->Square() << std::endl;
		delete T;
	}
	system("PAUSE");
	return 0;
}