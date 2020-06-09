#pragma once
#include <vector>
#include "Figure.h" //определять так нельзя (фигуру в доске, а доску в фигуре)
#include "Checker.h"

class Board {
public:
	const int size;
	std::vector<std::vector<Figure*>> board;
	Board(int size = 8); 
	bool IsEmpty(int x, int y) const
	{
		return board[x-1][y-1] == nullptr;
	}
};

