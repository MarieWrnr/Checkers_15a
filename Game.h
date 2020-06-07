#pragma once
#include <string>
#include <vector>
#include "Board.h"

class Game {
private:
	bool move = true;
public:
	Board board;
	std::string player;
	std::string CheckPlayer(); //вывод действующего игрока
};
