#include <vector>
#include "Checker.h"
#include "Figure.h"
#include <cmath>
#include <iostream>

int turnDisance = 1;

Checker::Checker() {}
Checker::Checker(int x, int y, char symb) {
	this->x = x;
	this->y = y;
	this->symb = symb;
	setInGame(true);

}

void Checker::Move(int x, int y, Board board) { //заменить на board
	if (abs(x - this->x) == turnDisance && abs(y - this->y) == turnDisance) {
		if (board.board[x][y].symb == ' ') {
			this->x = x;
			this->y = y;
		}
		else if (board.board[x][y].symb != ' ' && symb != board.board[x][y].symb) { //board
			turnDisance = 2;
			Hit(x, y, board);

		}

	}

}

void Checker::Hit(int x, int y, Board board) {
	std::cout << "meow";
}