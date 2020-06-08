#pragma once
#include "Figure.h"
class Queen :
	public Figure {
public:
	int turnDistance;
	void Move(int x, int y, int desk[8][8]) override;
	void Hit(int x, int y, int desk[8][8]) override;
};
