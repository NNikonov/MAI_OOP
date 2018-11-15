#include "Trapezium.h"
#include <iostream>
#include <cmath>
//#define DEBUG 1

Trapezium::Trapezium()
{
	side_a = 0;
	side_b = 0;
	side_c = 0;
	side_d = 0;
#ifdef DEBUG
	std::cout << "Trapezium created (default)" << std::endl;
#endif
}

Trapezium::Trapezium(std::istream &is)
{
	long long tmp_side_a, tmp_side_b, tmp_side_c, tmp_side_d;
	std::cout << "Enter trapezium sides: ";
	while (true)
	{
		is >> tmp_side_a;
		is >> tmp_side_b;
		is >> tmp_side_c;
		is >> tmp_side_d;
		is.clear();
		is.sync();
		if (tmp_side_a <= 0 || tmp_side_b <= 0 || tmp_side_c <= 0 || tmp_side_d <= 0)
		{
			std::cerr << "Error: All sides must be > 0. Try again: ";
		}
		else
		{
			side_a = tmp_side_a;
			side_b = tmp_side_b;
			side_c = tmp_side_c;
			side_d = tmp_side_d;
			break;
		}
	}
#ifdef DEBUG
	std::cout << "Trapezium created\n";
#endif // DEBUG
}

Trapezium::Trapezium(size_t i, size_t j, size_t k, size_t l)
{
	this->side_a = i;
	this->side_b = j;
	this->side_c = k;
	this->side_d = l;
#ifdef DEBUG
	std::cout << "Trapezium created (side)" << std::endl;
#endif
}

Trapezium::Trapezium(const Trapezium &orig)
{

#ifdef DEBUG
	std::cout << "Trapezium created (copy)" << std::endl;
#endif
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
	side_d = orig.side_d;
}

Trapezium &Trapezium::operator=(const Trapezium &right)
{
	if (this == &right)
	{
#ifdef DEBUG
		std::cout << "Trapezium: self-copy prevented" << std::endl;
#endif //DEBUG
		return *this;
	}
#ifdef DEBUG
	std::cout << "Trapezium copied via =" << std::endl;
#endif // DEBUG
	side_a = right.side_a;
	side_b = right.side_b;
	side_c = right.side_c;
	side_d = right.side_d;
	return *this;
}

double Trapezium::Square()
{
	/*double p = fabs(double(side_b) - double(side_a));
	double s = (double(side_a) + double(side_b)) / 2 *
		sqrt(pow(double(side_c), 2) - pow(((pow(double(side_c), 2) - pow(double(side_d), 2)) / p + p), 2) / 4);
	double ss = (double(side_a) + double(side_b)) / (4 * p) * sqrt((-p + double(side_c) + double(side_d)) *
		(-p + double(side_d) - double(side_c)) * (-p + double(side_c) - double(side_d)) * (p + double(side_c) + double(side_d)));
	/*if (s > 0) return s;
	else
	{
#ifdef DEBUG
		std::cout << "It's not a trapezium!" << std::endl;
#endif // DEBUG
		return 0;
	}*/
	return (double(side_a) + double(side_b)) / (4 * fabs(double(side_b) - double(side_a))) *
		sqrt((-fabs(double(side_b) - double(side_a)) + double(side_c) + double(side_d)) *
		(-fabs(double(side_b) - double(side_a)) + double(side_d) - double(side_c)) *
		(-fabs(double(side_b) - double(side_a)) + double(side_c) - double(side_d)) *
		(fabs(double(side_b) - double(side_a)) + double(side_c) + double(side_d)));
}

bool operator>(Trapezium &left, Trapezium &right)
{
	return (left.Square() > right.Square());
}

bool operator<(Trapezium &left, Trapezium &right)
{
	return !(left > right || left == right);
}

bool operator==(Trapezium &left, Trapezium &right)
{
	return left.side_a == right.side_a && left.side_b == right.side_b && left.side_c == right.side_c && left.side_d == right.side_d;
}

std::ostream &operator<<(std::ostream &os, const Trapezium &obj)
{
	os << "Trapezium (sides = " << obj.side_a << ", " << obj.side_b << ", " << obj.side_c << ", " << obj.side_d << ")" << std::endl;
	return os;
}

std::istream &operator>>(std::istream &is, Trapezium &obj)
{
	is >> obj.side_a;
	is >> obj.side_b;
	is >> obj.side_c;
	is >> obj.side_d;

	return is;
}

void Trapezium::print(std::ostream &os) const
{
	os << *this;
}

Trapezium::~Trapezium()
{
#ifdef DEBUG
	std::cout << "Trapezium deleted" << std::endl;
#endif // DEBUG
}