#include "Square.h"
#include <iostream>
#include <cmath>

Quadratum::Quadratum() : Quadratum(0) {}

Quadratum::Quadratum(size_t i) : side_a(i)
{
	std::cout << "Square created: " << side_a << ", " << side_a << std::endl;
}

Quadratum::Quadratum(std::istream &is)
{
	is >> side_a;
}

Quadratum::Quadratum(const Quadratum& orig)
{
	std::cout << "Square copy created" << std::endl;
	side_a = orig.side_a;
}

double Quadratum::Square()
{
	return double(side_a) * double(side_a);
}

void Quadratum::Print()
{
	std::cout << "a = " << side_a << std::endl;
}

Quadratum::~Quadratum()
{
	std::cout << "Square deleted" << std::endl;
}