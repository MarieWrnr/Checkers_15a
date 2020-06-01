#pragma once
#include "Figure.h"
class Checker :
	public Figure
{
public:
	int turnDistance;
	char symb;
	Checker();
	Checker(int x, int y, bool isWhite);
	void Move(int x, int y, int desk[8][8]) override;
	void Hit(int x, int y, int desk[8][8]) override;
};

