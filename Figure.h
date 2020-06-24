#pragma once
class Board;

class Figure
{
public:
	Figure(int x, int y, char symb);
	Figure();
	char GetSymb() {
		return symb;
	}
	void SetSymbol(char symb) {
		this->symb = symb;
	}
	virtual bool CanBeat(const Board& board, int& co_x, int& co_y)const = 0;
	virtual bool CanMove(const Board& board, int& co_x, int& co_y)const = 0;
	virtual bool Move(int co_x1, int co_y1, Board& board) = 0; //bool ��� ��������� ������ �� �������� �������
	virtual bool Hit(int co_x1, int �o_y1, Board& board) = 0;

protected:
	char symb = ' ';
	bool isQueen = false;
	int x;
	int y;
};

