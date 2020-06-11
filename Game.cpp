#include <string>
#include "Game.h"
#include "Board.h"
#include <iostream>

std::string Game::CheckPlayer() { 
	this->move = move;
	this->player = player;
	if (move) {
		player = "Player 1";
	}
	else player = "Player 2";
	return player;
}

void Game::Display() {
	int i;
	int j;
	for (i = 7; i >= 0; i--)
	{ 
		std::cout << "  +---+---+---+---+---+---+---+---+ " << std::endl;
		std::cout << i + 1 << " | ";
		for (j = 0; j < 8; j++) {

			if (board.GetBoardVector()[i][j] != nullptr) {
				if (j != 7) {
					std::cout << board.GetBoardVector()[i][j]->GetSymb() << " | ";
				}
				else std::cout << board.GetBoardVector()[i][j]->GetSymb() << std::endl;
			}
			else {
				if (j != 7) {
					std::cout << " " << " | ";
				}
				else std::cout << " " << std::endl;
			}
		}
	}
	std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
	std::cout << "    1   2   3   4   5   6   7   8  " << std::endl;
}