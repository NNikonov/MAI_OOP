#ifndef SQUARE_H
#define SQUARE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Quadratum : public Figure
{
public:
	Quadratum();
	Quadratum(std::istream &is);
	Quadratum(size_t side);
	Quadratum(const Quadratum &orig);

	Quadratum& operator=(const Quadratum& right);
	double Square();

	friend bool operator>(Quadratum &left, Quadratum &right);
	friend bool operator<(Quadratum &left, Quadratum &right);
	friend bool operator==(Quadratum &left, Quadratum &right);

	friend std::ostream &operator<<(std::ostream &os, const Quadratum &obj);
	friend std::istream &operator>>(std::istream &is, Quadratum &obj);
	void print(std::ostream &os) const;

	virtual ~Quadratum();
private:
	int side;
};

#endif
