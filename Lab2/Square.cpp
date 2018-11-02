#include "Square.h"
#include <iostream>
//#define DEBUG 1

Quadratum::Quadratum()
{
	side = 0;
#ifdef DEBUG
	std::cout << "Square created (default)" << std::endl;
#endif
}

Quadratum::Quadratum(size_t side)
{
	this->side = side;
#ifdef DEBUG
	std::cout << "Square created (side)" << std::endl;
#endif
}

Quadratum::Quadratum(const Quadratum& orig)
{

#ifdef DEBUG
	std::cout << "Square created (copy)" << std::endl;
#endif
	side = orig.side;
}

Quadratum& Quadratum::operator++()
{
	side++;

	return *this;
}

Quadratum& Quadratum::operator=(const Quadratum& right)
{
	if (this == &right)
	{
#ifdef DEBUG
		std::cout << "Square: self-copy prevented" << std::endl;
#endif //DEBUG
		return *this;
	}
#ifdef DEBUG
	std::cout << "Square copied via =" << std::endl;
#endif // DEBUG
	side = right.side;
	return *this;
}

double Quadratum::Square()
{
	return double(side) * double(side);
}

Quadratum operator+(const Quadratum& left, const Quadratum& right)
{
	return Quadratum(left.side + right.side);
}

bool operator>(const Quadratum& left, const Quadratum& right)
{
	return left.side > right.side;
}

bool operator<(const Quadratum& left, const Quadratum& right)
{
	return !(left > right || left == right);
}

bool operator==(const Quadratum& left, const Quadratum& right)
{
	return left.side == right.side;
}

std::ostream& operator<<(std::ostream& os, const Quadratum& obj)
{
	os << "Square (side = " << obj.side << ")" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Quadratum& obj)
{
	is >> obj.side;

	return is;
}

Quadratum::~Quadratum()
{
#ifdef DEBUG
	std::cout << "Square deleted" << std::endl;
#endif // DEBUG
}