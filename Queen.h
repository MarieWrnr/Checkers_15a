#pragma once
#include "Figure.h"

class Queen :
	public Figure {
public:
	Queen();
	Queen(int x, int y, char symb);
	void Move(int x, int y, Board& board) override;
	void Hit(int x, int y, Board& board) override;
};
