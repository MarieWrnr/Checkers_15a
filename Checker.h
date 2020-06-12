#pragma once
#include "Figure.h"
class Board;

class Checker :
	public Figure
{
public:
	Checker();
	Checker(int x, int y, char symb);
	bool CanBeat(const Board& board, int& co_x, int& co_y)const override;
	void Move(int x, int y, Board& board) override;
	void Hit(int x, int y, Board& board) override;
private:
	int turnDistance;
};

