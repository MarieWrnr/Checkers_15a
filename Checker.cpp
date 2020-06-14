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

            // y != 8, y != 7 т.к это исключ. случай (есть возможность бить€ только с левой стороны)
            // y != 1, y != 2 т.к это исключ. случай (битье с правой стороны)

            if (!board.IsEmpty(co_x+1, co_y+1) && board.HasCheckerB(co_x + 1, co_y + 1)) { //права€ диагональ
                if (board.IsEmpty(co_x + 2, co_y + 2)) {
                    curbeaten = true;
                }
            }
            else if (!board.IsEmpty(co_x + 1, co_y - 1) && board.HasCheckerB(co_x + 1, co_y - 1)) { //лева€ диагональ
                if (board.IsEmpty(co_x + 2, co_y - 2)) {
                    curbeaten = true;
                }
            }

        }
        else { 
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
    else { //дл€ черных
        if (co_y != board.GetSize() && co_y != 1 && co_y != 2 && co_y != board.GetSize() - 1) {

            if (!board.IsEmpty(co_x - 1, co_y - 1) && !board.HasCheckerB(co_x - 1, co_y - 1)) { //права€ диагональ
                if (board.IsEmpty(co_x - 2, co_y - 2)) {
                    curbeaten = true;
                }
            }
            else if (!board.IsEmpty(co_x - 1, co_y + 1) && !board.HasCheckerB(co_x - 1, co_y + 1)) { //лева€ диагональ
                if (board.IsEmpty(co_x - 2, co_y + 2)) {
                    curbeaten = true;
                }
            }

        }
        else {
            if (co_y == 1 || co_y == 2) {
                if (!board.IsEmpty(co_x - 1, co_y + 1) && !board.HasCheckerB(co_x - 1, co_y + 1)) {
                    if (board.IsEmpty(co_x - 2, co_y + 2)) {
                        curbeaten = true;
                    }
                }
            }
            else if (co_y == board.GetSize() - 1 || co_y == board.GetSize()) {
                if (!board.IsEmpty(co_x - 1, co_y - 1) && !board.HasCheckerB(co_x - 1, co_y - 1)) {
                    if (board.IsEmpty(co_x - 2, co_y - 2)) {
                        curbeaten = true;
                    }
                }
            }
        }
    }
    return curbeaten;
}

bool Checker::Move(int co_x, int co_y, Board* board) { //заменить на board
	if (abs(co_x - this->x) == 1 && abs(co_y - this->y) == 1) {
		if (board->IsEmpty(co_x, co_y)) {
            board->GetBoardVector()[co_x - 1][co_y - 1] = board->GetBoardVector()[this->x - 1][this->y - 1];
            board->GetBoardVector()[this->x - 1][this->y - 1] = nullptr;
			this->x = co_x;
			this->y = co_y;
            return true;
		}
		/*else if (!board.IsEmpty(x, y) && symb != board.GetBoardVector()[x - 1][y - 1]->GetSymb()) { //board
			turnDistance = 2; ƒќЅј¬»“№ Ё“ќ ¬ ћЁ…Ќ ¬ ѕ–»ƒј„”   ѕ–ќ¬≈– ≈, ƒќЅј¬»“№ ѕќЋ≈ »«ћ≈Ќ≈Ќ»я –ј——“ќяЌ»я
			Hit(x, y, board);
		}*/

	}

}

bool Checker::Hit(int co_x1, int co_y1, Board* board) {
    if (board->IsEmpty(co_x1, co_y1)) {
        board->GetBoardVector()[co_x1 - 1][co_y1 - 1] = board->GetBoardVector()[this->x - 1][this->y - 1];
        board->GetBoardVector()[this->x - 1][this->y - 1] = nullptr;
        board->GetBoardVector()[this->x][this->y] = nullptr;
        this->x = co_x1;
        this->y = co_y1;
        return true;
    }
}