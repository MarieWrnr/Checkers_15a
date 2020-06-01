#include "Figure.h"

Figure::Figure() {}
Figure::Figure(int x, int y, bool isWhite) {
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
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