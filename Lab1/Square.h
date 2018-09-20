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
	Quadratum(size_t i);
	Quadratum(const Quadratum& orig);

	double Square() override;
	void Print() override;

	virtual ~Quadratum();
private:
	size_t side_a;
};

#endif