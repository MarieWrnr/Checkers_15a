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
	void ChangePlayer(std::string player) {
		if (player == "Player 1") {
			player = "Player 2";
		}
		else {
			player = "Player 1";
		}
	}
	Board GetGameBoard() {
		return board;
	}
private:
	Board board;
	std::string player;
};
