#pragma once
#include "Figure.h"

class Queen :
	public Figure {
public:
	Queen();
	Queen(int x, int y, char symb);
	bool Move(int co_x1, int co_y1, Board& board) override;
	bool Hit(int co_x1, int co_y1, Board& board) override;
};
