#ifndef SQUARE_H
#define SQUARE_H
#include <cstdlib>
#include <iostream>

class Quadratum
{
public:
	Quadratum();
	Quadratum(size_t side);
	Quadratum(const Quadratum& orig);

	Quadratum& operator++();
	Quadratum& operator=(const Quadratum& right);
	double Square();
	friend Quadratum operator+(const Quadratum& left, const Quadratum& right);
	friend bool operator>(const Quadratum& left, const Quadratum& right);
	friend bool operator<(const Quadratum& left, const Quadratum& right);
	friend bool operator==(const Quadratum& left, const Quadratum& right);

	friend std::ostream& operator<<(std::ostream& os, const Quadratum& obj);
	friend std::istream& operator>>(std::istream& is, Quadratum& obj);

	virtual ~Quadratum();
private:
	int side;
};

#endif
