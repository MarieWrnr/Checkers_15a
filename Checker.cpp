#include <vector>
#include "Checker.h"
#include "Figure.h"
#include "Board.h"
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

bool Checker::CanBeat(const Board& board, int& co_x, int& co_y)const
{
	bool curbeaten = false;
    //char other_color = (symb == 'b') ? 'w' : 'b';
    //int delta_x = (symb == 'b') ? 1 : -1;
    if (!board.HasCheckerB(co_x, co_y)) {
        if (co_y != board.GetSize() && co_y != 1 && co_y != 2 && co_y != board.GetSize() - 1) {

            // y != 8, y != 7 т.к это исключ. случай (есть возможность битья только с левой стороны)
            // y != 1, y != 2 т.к это исключ. случай (битье с правой стороны)

            if (!board.IsEmpty(co_x+1, co_y+1) && board.HasCheckerB(x + 1, y + 1)) { //правая диагональ
                if (board.IsEmpty(co_x + 2, co_y + 2)) {
                    curbeaten = true;
                }
            }
            else if (!board.IsEmpty(co_x+1, co_y+1) && board.HasCheckerB(co_x + 1, co_y - 1)) { //левая диагональ
                if (board.IsEmpty(co_x + 2, co_y - 2)) {
                    curbeaten = true;
                }
            }

        }
        else { //для черных
            if (co_y == 1 || co_y == 2) {
                if (!board.IsEmpty(co_x + 1, co_y + 1) && board.HasCheckerB(co_x + 1, co_y + 1)) {
                    if (board.IsEmpty(co_x + 2, co_y + 2)) {
                        curbeaten = true;
                    }
                }
            }
            else if (co_y == board.GetSize() - 1 || co_y == board.GetSize()) {
                if (!board.IsEmpty(co_x + 1, co_y - 1) && board.HasCheckerB(co_x + 1, co_y - 1)) {
                    if (board.IsEmpty(co_x + 2, co_y - 2)) {
                        curbeaten = true;
                    }
                }
            }
        }
    }
    else {
        if (co_y != board.GetSize() && co_y != 1 && co_y != 2 && co_y != board.GetSize() - 1) {

            if (!board.IsEmpty(co_x - 1, co_y - 1) && !board.HasCheckerB(co_x - 1, co_y - 1)) { //правая диагональ
                if (board.IsEmpty(co_x - 2, co_y - 2)) {
                    curbeaten = true;
                }
            }
            else if (!board.IsEmpty(co_x - 1, co_y + 1) && !board.HasCheckerB(co_x - 1, co_y + 1)) { //левая диагональ
                if (board.IsEmpty(co_x - 2, co_y + 2)) {
                    curbeaten = true;
                }
            }

        }
        else {
            if (co_y == 1 || co_y == 2) {
                if (!board.IsEmpty(co_x - 1, co_y + 1) && board.HasCheckerB(co_x - 1, co_y + 1)) {
                    if (board.IsEmpty(co_x - 2, co_y + 2)) {
                        curbeaten = true;
                    }
                }
            }
            else if (co_y == board.GetSize() - 1 || co_y == board.GetSize()) {
                if (!board.IsEmpty(co_x - 1, co_y + 1) && board.HasCheckerB(co_x - 1, co_y - 1)) {
                    if (board.IsEmpty(co_x - 2, co_y - 2)) {
                        curbeaten = true;
                    }
                }
            }
        }
    }
    return curbeaten;
}

void Checker::Move(int x, int y, Board& board) { //заменить на board
	if (abs(x - this->x) == turnDisance && abs(y - this->y) == turnDisance) {
		if (board.IsEmpty(x, y)) {
			this->x = x;
			this->y = y;
		}
		else if (board.IsEmpty(x, y) && symb != board.GetBoardVector()[x - 1][y - 1]->GetSymb()) { //board
			turnDisance = 2;
			Hit(x, y, board);

		}

	}

}

void Checker::Hit(int x, int y, Board& board) {
	std::cout << "meow";
}