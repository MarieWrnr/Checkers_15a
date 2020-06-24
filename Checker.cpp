#include <vector>
#include "Checker.h"
#include "Queen.h"
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

}

bool Checker::CanBeat(const Board& board, int& co_x, int& co_y)const
{
	bool curbeaten = false;
    bool black = board.HasCheckerB(co_x, co_y);
    if (!black) {
        if (co_y != board.GetSize() && co_y != 1 && co_y != 2 && co_y != board.GetSize() - 1 && 
            co_x != board.GetSize() && co_x != board.GetSize() - 1) {

            // y != 8, y != 7 т.к это исключ. случай (есть возможность битья только с левой стороны)
            // y != 1, y != 2 т.к это исключ. случай (битье с правой стороны)

            if (!board.IsEmpty(co_x+1, co_y+1) && board.HasCheckerB(co_x + 1, co_y + 1)) { //правая диагональ
                if (board.IsEmpty(co_x + 2, co_y + 2)) {
                    curbeaten = true;
                }
            }
            if (!board.IsEmpty(co_x + 1, co_y - 1) && board.HasCheckerB(co_x + 1, co_y - 1)) { //левая диагональ
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
    else { //для черных
        if (co_y != board.GetSize() && co_y != 1 && co_y != 2 && co_y != board.GetSize() - 1 && co_x != 1 && co_x != 2) {

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

bool Checker::CanMove(const Board& board, int& co_x, int& co_y)const {
    bool black = board.HasCheckerB(co_x, co_y);
    if (!black) {
        if (co_y != board.GetSize() && co_y != 1) {//fix
            if (!board.IsEmpty(co_x + 1, co_y + 1) && !board.IsEmpty(co_x + 1, co_y - 1) &&
                !board.IsEmpty(co_x + 2, co_y + 2) && !board.IsEmpty(co_x + 1, co_y - 2)) return false;
            else return true;
        }
        else if (co_y == board.GetSize()) {
            if (!board.IsEmpty(co_x + 1, co_y - 1) && !board.IsEmpty(co_x + 2, co_y - 2)) return false;
            else return true;
        }
        else if (co_y == 1) {
            if (!board.IsEmpty(co_x + 1, co_y + 1) && !board.IsEmpty(co_x + 2, co_y + 2)) return false;
            else return true;
        }
    }
    else {
        if (co_y != board.GetSize() && co_y != 1) {
            if (!board.IsEmpty(co_x - 1, co_y + 1) && !board.IsEmpty(co_x - 1, co_y - 1) &&
                !board.IsEmpty(co_x - 2, co_y + 2) && !board.IsEmpty(co_x - 2, co_y - 2)) return false;
            else return true;
        }
        else if (co_y == board.GetSize()) {
            if (!board.IsEmpty(co_x - 1, co_y - 1) && !board.IsEmpty(co_x - 2, co_y - 2)) return false;
            else return true;
        }
        else if (co_y == 1) {
            if (!board.IsEmpty(co_x - 1, co_y + 1) && !board.IsEmpty(co_x - 2, co_y + 2)) return false;
            else return true;
        }
    }
}

bool Checker::Move(int co_x, int co_y, Board& board) { 
    char checker = board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb();
    if ((checker == 'w' && co_x - this->y == 1  && abs(co_y - this->x) == 1) ||
        (checker == 'b' && this->y - co_x == 1 && abs(co_y - this->x) == 1)) {

            board.GetBoardVector()[co_x - 1][co_y - 1] = board.GetBoardVector()[this->y - 1][this->x - 1];
            if (co_x == 8 && checker == 'w') { 
                board.GetBoardVector()[co_x - 1][co_y - 1] = new Queen(co_x, co_y);
                board.GetBoardVector()[co_x - 1][co_y - 1]->SetSymbol('W');
            }
            else if (co_x == 1 && checker == 'b') { 
                board.GetBoardVector()[co_x - 1][co_y - 1] = new Queen(co_x, co_y);
                board.GetBoardVector()[co_x - 1][co_y - 1]->SetSymbol('B');
            }

            board.GetBoardVector()[this->y - 1][this->x - 1] = nullptr;
            this->x = co_y; 
            this->y = co_x;
            return true;
    }
    else return false;
}

bool Checker::Hit(int co_x1, int co_y1, Board& board) { 
    if ((board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w' && co_x1 - this->y == 2 && abs(co_y1 - this->x) == 2) ||
        (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b' && this->y - co_x1 == 2 && abs(co_y1 - this->x) == 2)) {

            board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = board.GetBoardVector()[this->y - 1][this->x - 1];

            if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w') {
                if (co_y1 - this->x == 2) board.GetBoardVector()[this->y][this->x] = nullptr;
                else board.GetBoardVector()[this->y][this->x - 2] = nullptr;
            }

            else if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b') {
                if (this->x - co_y1 == -2)  board.GetBoardVector()[this->y - 2][this->x] = nullptr;
                else board.GetBoardVector()[this->y - 2][this->x - 2] = nullptr;
            }
            if (co_x1 == 8 && board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w') {
                board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = new Queen(co_x1, co_y1);
                board.GetBoardVector()[co_x1 - 1][co_y1 - 1]->SetSymbol('W');
            }
            else if (co_x1 == 1 && board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b') {
                board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = new Queen(co_x1, co_y1);
                board.GetBoardVector()[co_x1 - 1][co_y1 - 1]->SetSymbol('B');
            }
             
            board.GetBoardVector()[this->y - 1][this->x - 1] = nullptr;
            this->x = co_y1;
            this->y = co_x1;
            if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w') board.SetBlacks(1);
            else board.SetWhites(1);
            return true;
    }
    else return false;
}