#pragma once
#include <vector>

#include "Figure.h"
#include "Checker.h"
class Board {
public:
	const int size = 8;
	std::vector<std::vector<Checker>> board(); 
	Board(); //��������� ��������
	//CreateBoard(); � ����������� ��������� �������
};

