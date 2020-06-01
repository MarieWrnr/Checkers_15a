#include "Board.h"
#include "Figure.h"
#include "Checker.h"

Board::Board() { //создаем двумерный массив указателей
    board = new Checker * [size];
    for (int i = 0; i < size; i++) {
        board[i] = new Checker[size];
    }

}

void Board::CreateBoard() {
    int pos_x;
    int pos_y;
    for (int i = 0; i < size; i++) { //заполняем доску объектами класса Checkers с параметрами
        for (int j = 0; j < size; j++) {
            pos_x = i + 1;
            pos_y = j + 1;
            if ((pos_x % 2 != 0 && pos_y % 2 != 0) || (pos_x % 2 == 0 && pos_y % 2 == 0)) {
                if (pos_y < 4) {
                    board[j][i] = Checker(pos_x, pos_y, true);
                }
                else if (pos_y > 5) {
                    board[j][i] = Checker(pos_x, pos_y, false);
                }
            }
        }
    }
}