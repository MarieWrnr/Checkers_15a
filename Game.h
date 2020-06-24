#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Board.h"

class Game {
public:
	void Display();
	std::string CheckPlayer(); //вывод действующего игрока
	void SetMove() {
		move = !move;
	}
	Board& GetGameBoard() {
		return this->board;
	}
	void GetWinner(std::string symb) {
		std::cout << "Oh yeeeeeeeeeeeeeeaaaaaah, " << symb << " WON!" << std::endl;
	}
private:
	Board board;
	bool move = true;
	std::string player;
};
