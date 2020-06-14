#include "Queen.h"
#include "Figure.h"
#include "Board.h"
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
bool Queen::Move(int co_x1, int co_y1, Board& board) { //????
	if (abs(co_x1 - this->x) == 1 && abs(co_y1 - this->y) == 1) { //
		if (board.IsEmpty(co_x1, co_y1)) {
			board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = board.GetBoardVector()[this->x - 1][this->y - 1];
			board.GetBoardVector()[this->x - 1][this->y - 1] = nullptr;
			this->x = co_x1;
			this->y = co_y1;
			return true;
		}
	}
}

 bool Queen::Hit(int co_x1, int co_y1, Board& board) {
	return true;
}