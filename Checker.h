#pragma once
#include "Figure.h"
class Board;

class Checker :
	public Figure
{
public:
	int turnDistance;
	Checker();
	Checker(int x, int y, char symb);
	bool CanBeat(const Board* board)const override;
	void Move(int x, int y, Board* board) override;
	void Hit(int x, int y, Board* board) override;
};

