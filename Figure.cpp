#include "Figure.h"
#include "Board.h"
Figure::Figure() {}
Figure::Figure(int x, int y, char symb) {
	this->x = x;
	this->y = y;
	this->symb = symb;
	if (!isQueen) {
		this->inGame = true;
	}
}

void Figure::setCoords(int x, int y) {
	this->x = x;
	this->y = y;
}

void Figure::setInGame(bool state) {
	this->inGame = state;
}