#include "Queen.h"
#include "Figure.h"
#include <iostream>

Queen::Queen() {
}
Queen::Queen(int x, int y, char symb) {
	this->x = x;
	this->y = y;
	if (symb == 'w') {
		this->symb = 'W';
	}
	else if (symb == 'b') {
		this->symb = 'B';
	}
}
bool Queen::Move(int x, int y, Board* board) { //заменить на board
	/*if (abs(x - this->x) == turnDisance && abs(y - this->y) == turnDisance) {
		if (desk[x][y] == '-') {
			this->x = x;
			this->y = y;
		}
		else if (desk[x][y] != '-' && symb != desk[x][y]) { //board
			turnDisance = 2;
			Hit(x, y, desk);

		}

	}*/
	std::cout << "meow";
	return true;
}

 bool Queen::Hit(int co_x1, int co_y1, Board* board) {
	std::cout << "meow";
	return true;
}