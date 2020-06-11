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

bool Checker::CanBeat(const Board& board)const
{
	bool curbeaten = false;
    //char other_color = (symb == 'b') ? 'w' : 'b';
    //int delta_x = (symb == 'b') ? 1 : -1;
    if (!board.HasCheckerB(x, y)) {
        if (y != board.GetSize() && y != 1 && y != 2 && y != board.GetSize() - 1) {

            // y != 8, y != 7 т.к это исключ. случай (есть возможность битья только с левой стороны)
            // y != 1, y != 2 т.к это исключ. случай (битье с правой стороны)

            if (!board.IsEmpty(x+1, y+1) && board.HasCheckerB(x + 1, y + 1)) { //правая диагональ
                if (board.IsEmpty(x + 2, y + 2)) {
                    curbeaten = true;
                }
            }
            else if (!board.IsEmpty(x+1, y+1) && board.HasCheckerB(x + 1, y - 1)) { //левая диагональ
                if (board.IsEmpty(x + 2, y - 2)) {
                    curbeaten = true;
                }
            }

        }
        else {
            if (y == 1 || y == 2) {
                if (!board.IsEmpty(x + 1, y + 1) && board.HasCheckerB(x + 1, y + 1)) {
                    if (board.IsEmpty(x + 2, y + 2)) {
                        curbeaten = true;
                    }
                }
            }
            else if (y == board.GetSize() - 1 || y == board.GetSize()) {
                if (!board.IsEmpty(x + 1, y - 1) && board.HasCheckerB(x + 1, y - 1)) {
                    if (board.IsEmpty(x + 2, y - 2)) {
                        curbeaten = true;
                    }
                }
            }
        }
    }
    else {
        if (y != board.GetSize() && y != 1 && y != 2 && y != board.GetSize() - 1) {

            if (!board.HasCheckerB(x - 1, y - 1)) { //правая диагональ
                if (board.IsEmpty(x - 2, y - 2)) {
                    curbeaten = true;
                }
            }
            else if (!board.HasCheckerB(x - 1, y + 1)) { //левая диагональ
                if (board.IsEmpty(x - 2, y + 2)) {
                    curbeaten = true;
                }
            }

        }
        else {
            if (y == 1 || y == 2) {
                if (board.HasCheckerB(x - 1, y + 1)) {
                    if (board.IsEmpty(x - 2, y + 2)) {
                        curbeaten = true;
                    }
                }
            }
            else if (y == board.GetSize() - 1 || y == board.GetSize()) {
                if (board.HasCheckerB(x - 1, y - 1)) {
                    if (board.IsEmpty(x - 2, y - 2)) {
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