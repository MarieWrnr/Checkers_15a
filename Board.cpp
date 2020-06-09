#include <vector>
#include "Board.h"
#include "Figure.h"
#include "Checker.h"

Board::Board() { //создаем двумерный массив указателей
    int pos_x;
    int pos_y;
    for (int i = 0; i < size; i++) { //заполняем доску объектами класса Checkers с параметрами
        board.push_back({});
        for (int j = 0; j < size; j++) {
            pos_x = j + 1;
            pos_y = i + 1;
            //board[i].push_back({}); // здесь создается экземпляр класса? или просто место для него?
            if ((pos_x % 2 != 0 && pos_y % 2 != 0) || (pos_x % 2 == 0 && pos_y % 2 == 0)) {
                if (pos_y < 4) {
                    board[i].push_back(Checker(pos_x, pos_y, 'w'));
                }
                else if (pos_y > 5) {
                    board[i].push_back(Checker(pos_x, pos_y, 'b'));
                }
                else {
                    board[i].push_back(Checker());
                }
            }
        }
    }
}
