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
	setInGame(true);

}

bool Checker::CanBeat(const Board& board, int& co_x, int& co_y)const
{
	bool curbeaten = false;
    //char other_color = (symb == 'b') ? 'w' : 'b';
    //int delta_x = (symb == 'b') ? 1 : -1;

    if (!board.HasCheckerB(co_x, co_y)) {
        if (co_y != board.GetSize() && co_y != 1 && co_y != 2 && co_y != board.GetSize() - 1 && 
            co_x != board.GetSize() && co_x != board.GetSize() - 1) {

            // y != 8, y != 7 т.к это исключ. случай (есть возможность бить€ только с левой стороны)
            // y != 1, y != 2 т.к это исключ. случай (битье с правой стороны)

            if (!board.IsEmpty(co_x+1, co_y+1) && board.HasCheckerB(co_x + 1, co_y + 1)) { //права€ диагональ
                if (board.IsEmpty(co_x + 2, co_y + 2)) {
                    curbeaten = true;
                }
            }
            if (!board.IsEmpty(co_x + 1, co_y - 1) && board.HasCheckerB(co_x + 1, co_y - 1)) { //лева€ диагональ
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
        if (co_y != board.GetSize() && co_y != 1 && co_y != 2 && co_y != board.GetSize() - 1 && co_x != 1 && co_x != 2) {

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

bool Checker::CanMove(const Board& board, int& co_x, int& co_y)const {
    if (!board.HasCheckerB(co_x, co_y)) {
        if (co_y != board.GetSize() && co_y != 1) {
            if (!board.IsEmpty(co_x + 1, co_y + 1) && !board.IsEmpty(co_x + 1, co_y - 1)) return false;
            else return true;
        }
        else if (co_y == board.GetSize()) {
            if (!board.IsEmpty(co_x + 1, co_y - 1)) return false;
            else return true;
        }
        else if (co_y == 1) {
            if (!board.IsEmpty(co_x + 1, co_y + 1)) return false;
            else return true;
        }
    }
    else {
        if (co_y != board.GetSize() && co_y != 1) {
            if (!board.IsEmpty(co_x - 1, co_y + 1) && !board.IsEmpty(co_x - 1, co_y - 1)) return false;
            else return true;
        }
        else if (co_y == board.GetSize()) {
            if (!board.IsEmpty(co_x - 1, co_y - 1)) return false;
            else return true;
        }
        else if (co_y == 1) {
            if (!board.IsEmpty(co_x - 1, co_y + 1)) return false;
            else return true;
        }
    }
}

bool Checker::Move(int co_x, int co_y, Board& board) { //она не должна ходить назад!!!! и надо добавить достижение до королевы

    if ((board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w' && co_x - this->y == 1  && abs(co_y - this->x) == 1) ||
        (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b' && this->y - co_x == 1 && abs(co_y - this->x) == 1)) {

        if (board.IsEmpty(co_x, co_y)) {
            board.GetBoardVector()[co_x - 1][co_y - 1] = board.GetBoardVector()[this->y - 1][this->x - 1];
            if (co_x == 8 && board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w') { 
                board.GetBoardVector()[co_x - 1][co_y - 1] = new Queen();
                board.GetBoardVector()[co_x - 1][co_y - 1]->SetSymbol('W');
            }
            else if (co_x == 1 && board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b') { 
                board.GetBoardVector()[co_x - 1][co_y - 1] = new Queen();
                board.GetBoardVector()[co_x - 1][co_y - 1]->SetSymbol('W');
            }

            board.GetBoardVector()[this->y - 1][this->x - 1] = nullptr;
            this->x = co_y; //почему-то указатели на координаты помен€лись местами в шашке и теперь х - столбец, a y - строка :\/
            this->y = co_x;
            return true;
            /*else if (!board.IsEmpty(x, y) && symb != board.GetBoardVector()[x - 1][y - 1]->GetSymb()) { //board
                turnDistance = 2; ƒќЅј¬»“№ Ё“ќ ¬ ћЁ…Ќ ¬ ѕ–»ƒј„”   ѕ–ќ¬≈– ≈, ƒќЅј¬»“№ ѕќЋ≈ »«ћ≈Ќ≈Ќ»я –ј——“ќяЌ»я (а надо ли?)
                Hit(x, y, board);
            }*/
        }
        else return false;
    }
    else return false;
}

bool Checker::Hit(int co_x1, int co_y1, Board& board) { 
    if ((board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w' && co_x1 - this->y == 2 && abs(co_y1 - this->x) == 2) ||
        (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b' && this->y - co_x1 == 2 && abs(co_y1 - this->x) == 2)) {

        if (board.IsEmpty(co_x1, co_y1)) { 

            board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = board.GetBoardVector()[this->y - 1][this->x - 1];
            //почему-то указатели на координаты помен€лись местами в шашке и теперь х - столбец, a y - строка :\/

            if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w') {
                if (co_y1 - this->x == 2) board.GetBoardVector()[this->y][this->x] = nullptr;
                else board.GetBoardVector()[this->y][this->x - 2] = nullptr;
            }

            else if (board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b') {
                if (this->x - co_y1 == -2)  board.GetBoardVector()[this->y - 2][this->x] = nullptr;
                else board.GetBoardVector()[this->y - 2][this->x - 2] = nullptr;
            }
            if (co_x1 == 8 && board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'w') {
                board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = new Queen();
                board.GetBoardVector()[co_x1 - 1][co_y1 - 1]->SetSymbol('W');
            }
            else if (co_x1 == 1 && board.GetBoardVector()[this->y - 1][this->x - 1]->GetSymb() == 'b') {
                board.GetBoardVector()[co_x1 - 1][co_y1 - 1] = new Queen();
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
    else return false;
}