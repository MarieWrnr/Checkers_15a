#pragma once
#include "Figure.h"
#include "Board.h"
class Checker :
	public Figure
{
public:
	int turnDistance;
	Checker();
	Checker(int x, int y, char symb);
	void Move(int x, int y, Board board) override;
	void Hit(int x, int y, Board board) override;
};

