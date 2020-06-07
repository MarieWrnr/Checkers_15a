#include <vector>
#include "Board.h"
#include "Figure.h"
#include "Checker.h"

Board::Board() { //создаем двумерный массив указателей
    /*board = new Checker * [size];
    for (int i = 0; i < size; i++) {
        board[i] = new Checker[size];
    }*/
    int pos_x;
    int pos_y;
    for (int i = 0; i < size; i++) { //заполняем доску объектами класса Checkers с параметрами
        board.push_back({});
        for (int j = 0; j < size; j++) {
            pos_x = i + 1;
            pos_y = j + 1;
            board[i].push_back({});
            if ((pos_x % 2 != 0 && pos_y % 2 != 0) || (pos_x % 2 == 0 && pos_y % 2 == 0)) {
                if (pos_y < 4) {
                    board[i][j] = Checker(pos_x, pos_y, true);
                }
                else if (pos_y > 5) {
                    board[i][j] = Checker(pos_x, pos_y, false);
                }
            }
        }
    }
}
