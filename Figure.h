#pragma once
class Board;

class Figure
{
protected:
	bool inGame; //?
	char symb = ' ';
	bool isQueen = false;
	int x;
	int y;
public:
	Figure(int x, int y, char symb);
	Figure();
	//void setCoords(int x, int y);
	void setInGame(bool state); //?
	char GetSymb() {
		return symb;
	}
	void SetSymbol(char symb) {
		this->symb = symb;
	}
	virtual bool Move(int co_x1, int co_y1, Board& board) = 0; //bool ��� ��������� ������ �� �������� �������
	virtual bool Hit(int co_x1, int �o_y1, Board& board) = 0;
};

