#include "Trapezium.h"
#include <iostream>
#include <cmath>

Trapezium::Trapezium() : Trapezium(0, 0, 0, 0) {}

Trapezium::Trapezium(size_t i, size_t j, size_t k, size_t l) : side_a(i), side_b(j), side_c(k), side_d(l)
{
	std::cout << "Trapezium created: " << side_a << ", " << side_b << ", " << side_c << ", " << side_d << std::endl;
}

Trapezium::Trapezium(std::istream &is)
{
	is >> side_a;
	is >> side_b;
	is >> side_c;
	is >> side_d;
}

Trapezium::Trapezium(const Trapezium& orig)
{
	std::cout << "Trapezium copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
	side_d = orig.side_d;
}

double Trapezium::Square()
{
	double p = fabs(double(side_b) - double(side_a));
	double s = (double(side_a) + double(side_b)) / 2 * 
		sqrt(pow(double(side_c), 2) - pow((p + (pow(double(side_c), 2) - pow(double(side_d), 2)) / p), 2) / 4);
	if (s > 0) return s;
	else
	{
		std::cout << "It's not a trapezium!" << std::endl;
		return 0;
	}
}

void Trapezium::Print()
{
	std::cout << "a = " << side_a << ", b = " << side_b << ", c = " << side_c << ", d = " << side_d << std::endl;
}

Trapezium::~Trapezium()
{
	std::cout << "Trapezium deleted" << std::endl;
}