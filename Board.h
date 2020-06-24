#pragma once
#include <vector>
#include "Figure.h" //определять так нельзя (фигуру в доске, а доску в фигуре)
#include "Checker.h"

class Board {
public:
	Board(int size = 8);

	bool IsEmpty(int x, int y) const
	{
		return board[x-1][y-1] == nullptr;
	}

	size_t GetSize() const {
		return board.size();
	}

	bool HasCheckerB(int x, int y) const {
		if (board[x - 1][y - 1]->GetSymb() == 'b' || board[x - 1][y - 1]->GetSymb() == 'B') return true;
		else return false;
	}

	std::vector<std::vector<Figure*>>& GetBoardVector() {
		return board;
	}

	int GetBlacks() const {
		return blacks;
	}
	int GetWhites() const {
		return whites;
	}

	void SetBlacks(int count) {
		blacks -= count;
	}
	void SetWhites(int count) {
		whites -= count;
	}

private:
	const int size;
	int blacks = 12;
	int whites = 12;
	std::vector<std::vector<Figure*>> board;
};

