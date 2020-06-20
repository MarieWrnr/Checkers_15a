#include "Queen.h"
#include "Figure.h"
#include "Board.h"
#include "Checker.h"
#include <iostream>

Queen::Queen() {
	isQueen = true;
}
bool Queen::UpDown(const Board& board, int& co_x, int& co_y, char key)const {
	bool black = board.HasCheckerB(co_x, co_y);
	if (key == 'd') {
		for (int i = co_x - 1; i >= 2; i--) {
			if (!black) {
				if (!board.IsEmpty(i, co_y)) {
					if (!board.HasCheckerB(i, co_y)) return false;
					else {
						if (!board.IsEmpty(i - 1, co_y)) return false;
						else return true;
					}
				}
			}
			else {
				if (!board.IsEmpty(i, co_y)) {
					if (board.HasCheckerB(i, co_y)) return false;
					else {
						if (!board.IsEmpty(i - 1, co_y)) return false;
						else return true;
					}
				}
			}
		}
		return false;
	}
	else {
		for (int i = co_x; i < board.GetSize(); i++) {
			if (!black) {
				if (!board.IsEmpty(i, co_y)) {
					if (!board.HasCheckerB(i, co_y)) return false;
					else {
						if (!board.IsEmpty(i + 1, co_y)) return false;
						else return true;
					}
				}
			}
			else {
				if (!board.IsEmpty(i, co_y)) {
					if (board.HasCheckerB(i, co_y)) return false;
					else {
						if (!board.IsEmpty(i + 1, co_y)) return false;
						else return true;
					}
				}
			}
		}
		return false;
	}
}
bool Queen::LeftRight(const Board& board, int& co_x, int& co_y, char key)const {
	bool black = board.HasCheckerB(co_x, co_y);
	if (key == 'l') {
		for (int i = co_y - 1; i >= 2; i--) {
			if (!black) {
				if (!board.IsEmpty(co_x, i)) {
					if (!board.HasCheckerB(co_x, i)) return false;
					else {
						if (!board.IsEmpty(co_x, i - 1)) return false;
						else return true;
					}
				}
			}
			else {
				if (!board.IsEmpty(co_x, i)) {
					if (board.HasCheckerB(co_x, i)) return false;
					else {
						if (!board.IsEmpty(co_x, i - 1)) return false;
						else return true;
					}
				}
			}
		}
		return false;
	}
	else {
		for (int i = co_y + 1; i < board.GetSize(); i++) {
			if (!black) {
				if (!board.IsEmpty(co_x, i)) {
					if (!board.HasCheckerB(co_x, i)) return false;
					else {
						if (!board.IsEmpty(co_x, i + 1)) return false;
						else return true;
					}
				}
			}
			else {
				if (!board.IsEmpty(co_x, i)) {
					if (board.HasCheckerB(co_x, i)) return false;
					else {
						if (!board.IsEmpty(co_x, i + 1)) return false;
						else return true;
					}
				}
			}
		}
		return false;
	}
}
bool Queen::Diagonale(const Board& board, int& co_x, int& co_y, int key)const {
	bool black = board.HasCheckerB(co_x, co_y);
	int j;
	switch (key) {
	case 1:
		j = co_y + 1;
		for (int i = co_x + 1; i < board.GetSize(); i++) {
			if (!black) {
				if (!board.IsEmpty(i, j)) {
					if (!board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i + 1, j + 1)) return false;
						else return false;
					}
				}
			}
			else {
				if (!board.IsEmpty(i, j)) {
					if (board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i + 1, j + 1)) return false;
						else return false;
					}
				}
			}
			j++;
		}
		return false;
	case 2:
		j = co_y - 1;
		for (int i = co_x + 1; i < board.GetSize(); i++) {
			if (!black) {
				if (!board.IsEmpty(i, j)) {
					if (!board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i + 1, j - 1)) return false;
						else return false;
					}
				}
			}
			else {
				if (!board.IsEmpty(i, j)) {
					if (board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i + 1, j - 1)) return false;
						else return false;
					}
				}
			}
			j--;
		}
		return false;
	case 3:
		j = co_y - 1;
		for (int i = co_x - 1; i >= 2; i--) {
			if (!black) {
				if (!board.IsEmpty(i, j)) {
					if (!board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i - 1, j - 1)) return false;
						else return false;
					}
				}
			}
			else {
				if (!board.IsEmpty(i, j)) {
					if (board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i - 1, j - 1)) return false;
						else return false;
					}
				}
			}
			j--;
		}
		return false;
	case 4:
		j = co_y + 1;
		for (int i = co_x - 1; i >= 2; i--) {
			if (!black) {
				if (!board.IsEmpty(i, j)) {
					if (!board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i - 1, j + 1)) return false;
						else return false;
					}
				}
			}
			else {
				if (!board.IsEmpty(i, j)) {
					if (board.HasCheckerB(i, j)) return false;
					else {
						if (!board.IsEmpty(i - 1, j + 1)) return false;
						else return false;
					}
				}
			}
			j--;
		}
		return false;
	}
}
bool Queen::CanBeat(const Board& board, int& co_x, int& co_y)const {
	//тут повеселее
	//вверх-вниз, стараемся использовать функции
	if (UpDown(board, co_x, co_y, 'd')) return true;
	else if (UpDown(board, co_x, co_y, 'u')) return true;
	//влево-вправо
	else if (LeftRight(board, co_x, co_y, 'l')) return true;
	else if (LeftRight(board, co_x, co_y, 'r')) return true;

	//диагональ
	else if (Diagonale(board, co_x, co_y, 1)) return true;
	else if (Diagonale(board, co_x, co_y, 2)) return true;
	else if (Diagonale(board, co_x, co_y, 3)) return true;
	else if (Diagonale(board, co_x, co_y, 4)) return true;
	else return false;
}
bool Queen::CanMove(const Board& board, int& co_x, int& co_y)const {
	return true; //т.к такая вероятность крайне мала
}
bool Queen::Move(int co_x1, int co_y1, Board& board) { 
	bool black = board.HasCheckerB(this->y, this->x);
	if (this->x == co_y1) {
		if (this->y > co_x1) { //down
			for (int i = this->y - 1; i >= co_x1; i--) {
				if (!board.IsEmpty(i, co_y1)) return false;
			}
		}
		else { //up
			for (int i = this->y + 1; i < co_x1; i++) {
				if (!board.IsEmpty(i, co_y1)) return false;
			}
		}
	}
	else if (this->y == co_x1) {
		if (this->x > co_y1) { //left
			for (int i = this->x - 1; i >= co_y1; i--) {
				if (!board.IsEmpty(co_x1, i)) return false;
			}
		}
		else { //right
			for (int i = this->x + 1; i < co_y1; i++) {
				if (!board.IsEmpty(co_x1, i)) return false;
			}
		}
	}
	else {
		int j;
		if (co_x1 > this->y && co_y1 > this->x) { //1
			j = this->x + 1;
			for (int i = this->y + 1; i < co_x1; i++) {
				if (!board.IsEmpty(i, j)) return false;
				j++;
			}
		}
		else if (co_x1 > this->x && co_y1 < this->x) { //2
			j = co_y1 - 1;
			for (int i = this->y + 1; i < co_x1; i++) {
				if (!board.IsEmpty(i, j)) return false;
				j--;
			}
		}
		else if (co_x1 < this->y && co_y1 < this->x) { //3
			j = co_y1 - 1;
			for (int i = this->y - 1; i > co_x1; i--) {
				if (!board.IsEmpty(i, j)) return false;
				j--;
			}
		}
		else { //4
			j = this->x + 1;
			for (int i = this->y - 1; i > co_x1; i--) {
				if (!board.IsEmpty(i, j)) return false;
				j++;
			}
		}
	}
	board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = board.GetBoardVector()[this->y - 1][this->x - 1];
	board.GetBoardVector()[this->y - 1][this->x - 1] = nullptr;
	this->x = co_x1;
	this->y = co_y1;
	return true;
}

 bool Queen::Hit(int co_x1, int co_y1, Board& board) {
	 board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = board.GetBoardVector()[this->y - 1][this->x - 1];
	 board.GetBoardVector()[this->y-3][this->x-3] = nullptr;
	 board.GetBoardVector()[this->y - 1][this->x - 1] = nullptr;
	 this->x = co_x1;
	 this->y = co_y1;
	 if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w') board.SetBlacks(1);
	 else board.SetWhites(1);
	return true;
}