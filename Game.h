#pragma once
#include <string>
#include <vector>
#include "Board.h"

class Game {
private:
	bool move = true;
public:
	void Display();
	std::string CheckPlayer(); //вывод действующего игрока
	void SetMove() {
		move = !move;
	}
	Board GetGameBoard() {
		return this->board;
	}
private:
	Board board;
	std::string player;
};
