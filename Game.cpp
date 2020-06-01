#include <string>
#include "Game.h"
#include "Board.h"

std::string Game::CheckPlayer() { 
	this->move = move;
	this->player = player;
	if (move) {
		player = "Player 1";
	}
	else player = "Player 2";
	return player;
}