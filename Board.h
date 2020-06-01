#pragma once
#include "Figure.h"
#include "Checker.h"

class Board {
public:
	const int size = 8;
	Checker** board; //Checker* board[size][size] or vector
	Board();
	void CreateBoard();
};

