#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(size_t i, size_t j);
	Rectangle(const Rectangle &orig);

	Rectangle &operator=(const Rectangle &right);
	double Square();

	friend bool operator>(Rectangle& left, Rectangle &right);
	friend bool operator<(Rectangle& left, Rectangle &right);
	friend bool operator==(Rectangle& left, Rectangle &right);

	friend std::ostream &operator<<(std::ostream &os, const Rectangle &obj);
	friend std::istream &operator>>(std::istream &is, Rectangle &obj);
	void print(std::ostream &os) const;

	virtual ~Rectangle();
private:
	size_t side_a;
	size_t side_b;
};

#endif