#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <memory>
//#define DEBUG 0

class Figure
{
public:
	virtual double Square() = 0;
	virtual void print(std::ostream& os) const;
	bool EqualFigures(std::shared_ptr<Figure> other);
	bool SquareLess(std::shared_ptr<Figure> other);
	bool SquareGreater(std::shared_ptr<Figure> other);

	virtual ~Figure() {};
};


#endif  /*  FIGURE_H  */