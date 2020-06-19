#pragma once
#include "Figure.h"

class Queen :
	public Figure {
public:
	Queen();
	bool CanBeat(const Board& board, int& co_x, int& co_y)const override;
	bool CanMove(const Board& board, int& co_x, int& co_y)const override;
	bool Move(int co_x1, int co_y1, Board& board) override;
	bool Hit(int co_x1, int co_y1, Board& board) override;
};
