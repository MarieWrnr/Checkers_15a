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

bool Checker::CanBeat(const Board* board)const
{
	bool curbeaten = false;
    //char other_color = (symb == 'b') ? 'w' : 'b';
    //int delta_x = (symb == 'b') ? 1 : -1;

    if (y != board->GetSize() && y != 1 && y != 2 && y != 7) {

        // y != 8, y != 7 т.к это исключ. случай (есть возможность битья только с левой стороны)
        // y != 1, y != 2 т.к это исключ. случай (битье с правой стороны)

        if (board->HasChecker( x+1, y+1, 'b')){ //правая диагональ
            if (board->IsEmpty(x + 2, y + 2)) {
                curbeaten = true;
            }
        }
        else if (board->HasChecker(x + 1, y - 1, 'b')) { //левая диагональ
            if (board->IsEmpty(x + 2, y - 2)) {
                curbeaten = true;
            }
        }
        
    }
    else {
        if (y == 1 || y == 2) {
            if (board.board[x][y].symb == 'b') {
                if (board.board[x + 1][y + 1].symb == ' ') {
                    curbeaten = true;
                }
            }
        }
        else if (y == 7 || y == 8) {
            if (board.board[x][y - 2].symb == 'b') {
                if (board.board[x + 1][y - 3].symb == ' ') {
                    curbeaten = true;
                }
            }
        }
    }
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