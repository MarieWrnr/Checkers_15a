#include "Figure.h"
#include "Board.h"

Figure::Figure() {}
Figure::Figure(int x, int y, char symb) {
	this->x = x;
	this->y = y;
	this->symb = symb;
}