#include "Figure.h"

void Figure::print(std::ostream & os) const
{
}

bool Figure::EqualFigures(std::shared_ptr<Figure> other)
{
	return (this->Square() == other->Square() && typeid(*this) == typeid(*other.get()));
}

bool Figure::SquareLess(std::shared_ptr<Figure> other)
{
	return (this->Square() < other->Square());
}

bool Figure::SquareGreater(std::shared_ptr<Figure> other)
{
	return this->Square() > other->Square();
}