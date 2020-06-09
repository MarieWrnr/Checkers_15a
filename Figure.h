#pragma once
class Board;

class Figure
{
private:
	bool inGame; //
public:
	char symb = ' ';
	bool isQueen = false;
	int x;
	int y;
	Figure(int x, int y, char symb);
	Figure();
	void setCoords(int x, int y);
	void setInGame(bool state);
	virtual bool CanBeat(const Board* board)const = 0;
	virtual void Move(int x, int y, Board* board) = 0;
	virtual void Hit(int x, int y, Board* board) = 0;
};

