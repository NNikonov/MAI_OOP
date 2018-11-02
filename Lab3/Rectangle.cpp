#include "Rectangle.h"
#include <iostream>
//#define DEBUG 1

Rectangle::Rectangle()
{
	side_a = 0;
	side_b = 0;
#ifdef DEBUG
	std::cout << "Rectangle created (default)" << std::endl;
#endif
}

Rectangle::Rectangle(std::istream &is)
{
	long long tmp_side_a, tmp_side_b;
	std::cout << "Enter rectangle sides: ";
	while (true)
	{
		is >> tmp_side_a;
		is >> tmp_side_b;
		is.clear();
		is.sync();
		if (tmp_side_a <= 0 || tmp_side_b <= 0)
		{
			std::cerr << "Error: All sides must be > 0. Try again: ";
		}
		else
		{
			side_a = tmp_side_a;
			side_b = tmp_side_b;
			break;
		}
	}
#ifdef DEBUG
	std::cout << "Rectangle created\n";
#endif // DEBUG
}

Rectangle::Rectangle(size_t i, size_t j)
{
	this->side_a = i;
	this->side_b = j;
#ifdef DEBUG
	std::cout << "Rectangle created (side)" << std::endl;
#endif
}

Rectangle::Rectangle(const Rectangle& orig)
{

#ifdef DEBUG
	std::cout << "Rectangle created (copy)" << std::endl;
#endif
	side_a = orig.side_a;
	side_b = orig.side_b;
}

Rectangle& Rectangle::operator=(const Rectangle& right)
{
	if (this == &right)
	{
#ifdef DEBUG
		std::cout << "Rectangle: self-copy prevented" << std::endl;
#endif //DEBUG
		return *this;
	}
#ifdef DEBUG
	std::cout << "Rectangle copied via =" << std::endl;
#endif // DEBUG
	side_a = right.side_a;
	side_b = right.side_b;
	return *this;
}

double Rectangle::Square()
{
	return double(side_a) * double(side_b);
}

bool operator>(const Rectangle& left, const Rectangle& right)
{
	return left.side_a * left.side_b > right.side_a * right.side_b;
}

bool operator<(const Rectangle& left, const Rectangle& right)
{
	return !(left > right || left == right);
}

bool operator==(const Rectangle& left, const Rectangle& right)
{
	return left.side_a == right.side_a && left.side_b == right.side_b;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj)
{
	os << "Rectangle (sides = " << obj.side_a << ", " << obj.side_b << ")" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj)
{
	is >> obj.side_a;
	is >> obj.side_b;

	return is;
}

void Rectangle::print(std::ostream& os) const
{
	os << *this;
}

Rectangle::~Rectangle()
{
#ifdef DEBUG
	std::cout << "Rectangle deleted" << std::endl;
#endif // DEBUG
}