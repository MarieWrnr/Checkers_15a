#include "Queen.h"
#include "Figure.h"
#include "Board.h"
#include "Checker.h"
#include <iostream>

Queen::Queen() {
	isQueen = true;
}
bool Queen::CanBeat(const Board& board, int& co_x, int& co_y)const {
	return true;
}
bool Queen::Move(int co_x1, int co_y1, Board& board) { 
	/*Если вверх-вниз - х меняется, а у нет
	  Если вправо-влево - у меняется, а х нет
	  Если по диагонали - у и х меняются с одинаковым интервалом (но разными знаками)
	  -- - левая диагональ вниз
	  -+ - правая диагональ вниз
	  +- - левая диагональ вверх
	  ++ - правая диагональ вверх
	  Если нет на пути фишечек - все прекрасненько
	  Если одна черная - бей, бей, беееееееей
	  есть и занятая - бить низя
	  проработать сначала мув, потом CanBeat, 
	  */
	//сначала по сторонам
	if (board.IsEmpty(co_x1, co_y1)) {
		if (co_x1 == this->y && board.IsEmpty(co_x1, co_y1)) { //влево-вправо
			if (co_y1 < this->x) { //новая координата меньше -> движемся вниз
					for (int i = this->x - 1; i > co_y1; i--) {
						if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'W') {
							if (!board.IsEmpty(co_x1, i) && board.HasCheckerB(this->y, i)) { //вызывать удар отсюда, убрать CanBeat
								return false;
							}
						}
						else {
							if (!board.IsEmpty(co_x1, i) && !board.HasCheckerB(this->y, i)) {
								return false;
							}
						}
					}
					return true;
			}
			else {
				for (int i = this->x - 1; i > co_y1; i--) {
					if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'W') {
						if (!board.IsEmpty(co_x1, i) && board.HasCheckerB(this->y, i)) { //вызывать удар отсюда, убрать CanBeat
							return false;
						}
					}
					else {
						if (!board.IsEmpty(co_x1, i) && !board.HasCheckerB(this->y, i)) {
							return false;
						}
					}
				}
				return true;
			}
		}
	}
	/*if (abs(co_x1 - this->x) == 1 && abs(co_y1 - this->y) == 1) { //
		if (board.IsEmpty(co_x1, co_y1)) {
			board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = board.GetBoardVector()[this->x - 1][this->y - 1];
			board.GetBoardVector()[this->x - 1][this->y - 1] = nullptr;
			this->x = co_x1;
			this->y = co_y1;
			return true;
		}
	}*/
	else return false;
}

 bool Queen::Hit(int co_x1, int co_y1, Board& board) {
	return true;
}