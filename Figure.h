#pragma once
class Board;

class Figure
{
protected:
	bool inGame; //
	char symb = ' ';
	bool isQueen = false;
	int x;
	int y;
public:
	Figure(int x, int y, char symb);
	Figure();
	void setCoords(int x, int y);
	void setInGame(bool state);
	char GetSymb() {
		return symb;
	}
	virtual bool CanBeat(const Board& board, int& co_x, int& co_y)const = 0;
	virtual bool Move(int co_x1, int co_y1, Board* board) = 0; //bool ибо проверяет прошла ли операция успешно
	virtual bool Hit(int co_x1, int сo_y1, Board* board) = 0;
};

