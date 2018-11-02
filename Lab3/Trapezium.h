#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Trapezium : public Figure
{
public:
	Trapezium();
	Trapezium(std::istream &is);
	Trapezium(size_t i, size_t j, size_t k, size_t l);
	Trapezium(const Trapezium& orig);

	Trapezium& operator=(const Trapezium& right);
	double Square();

	friend bool operator>(const Trapezium& left, const Trapezium& right);
	friend bool operator<(const Trapezium& left, const Trapezium& right);
	friend bool operator==(const Trapezium& left, const Trapezium& right);

	friend std::ostream& operator<<(std::ostream& os, const Trapezium& obj);
	friend std::istream& operator>>(std::istream& is, Trapezium& obj);
	void print(std::ostream& os) const;

	virtual ~Trapezium();
private:
	size_t side_a;
	size_t side_b;
	size_t side_c;
	size_t side_d;
};

#endif