#pragma once
class Figure
{
private:
	bool inGame; //
public:
	bool isWhite; //public
	bool isQueen = false;
	int x;
	int y;
	Figure(int x, int y, bool isWhite);
	Figure();
	void setCoords(int x, int y);
	void setInGame(bool state);
	virtual void Move(int x, int y, int desk[8][8]) = 0;
	virtual void Hit(int x, int y, int desk[8][8]) = 0;
};

