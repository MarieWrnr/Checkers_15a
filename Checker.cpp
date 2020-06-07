#include <vector>
#include "Checker.h"
#include "Figure.h"
#include <cmath>

int turnDisance = 1;

Checker::Checker() {}
Checker::Checker(int x, int y, bool isWhite) {
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
	if (isWhite) {
		this->symb = 'W';
	}
	else {
		this->symb = 'B';
	}
	setInGame(true);

}

void Checker::Move(int x, int y, int desk[8][8]) { //заменить на board
	if (abs(x - this->x) == turnDisance && abs(y - this->y) == turnDisance) {
		if (desk[x][y] == '-') {
			this->x = x;
			this->y = y;
		}
		else if (desk[x][y] != '-' && symb != desk[x][y]) { //board
			turnDisance = 2;
			Hit(x, y, desk);

		}

	}

}

void Checker::Hit(int x, int y, int desk[8][8]) {

}