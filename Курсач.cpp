#include <iostream>
#include <vector>
#include <string>
#include "Figure.h"
#include "Checker.h"
#include "Board.h"
#include "Game.h"
#include "Queen.h"
#include <map>



using namespace std;
bool CheckBeat(Board& board, int x, int y) { 

    //этот метод необходим для того, чтобы проверить, может ли текущая шашка бить что-либо
    //bool; если true - значит ей можно ходить без проверок; если false - программа запускает проверку на возможность битья других шашек

    bool curbeaten = false;
    if (board.board[x - 1][y - 1].symb == 'w' && !board.board[x][y].isQueen) { 

        //если текущая шашка белая - мы проверяем ее на возможность битья

            if (y != 8 && y != 1 && y != 2 && y != 7) { 

                // y != 8, y != 7 т.к это исключ. случай (есть возможность битья только с левой стороны)
                // y != 1, y != 2 т.к это исключ. случай (битье с правой стороны)

                if (board.board[x][y].symb == 'b') { //правая диагональ
                    if (board.board[x + 1][y + 1].symb == ' ') { 
                        curbeaten = true;
                    }
                }
                else if (board.board[x][y - 2].symb == 'b') { //левая диагональ
                    if (board.board[x + 1][y - 3].symb == ' ') {
                        curbeaten = true;
                    }
                }
            }
            else {
                if (y == 1 || y == 2) {
                    if (board.board[x][y].symb == 'b') {
                        if (board.board[x + 1][y + 1].symb == ' ') {
                            curbeaten = true;
                        }
                    }
               }
                else if (y == 7 || y == 8) {
                    if (board.board[x][y - 2].symb == 'b') {
                        if (board.board[x + 1][y - 3].symb == ' ') {
                            curbeaten = true;
                        }
                    }
                }
            }
    }
    else {
        if (!board.board[x][y].isQueen) {
            if (y != 8 && y != 7 && y != 1 && y != 2) {

            }
        }
    }
    return curbeaten;
}

void Display(Board& board1)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        cout << "  +---+---+---+---+---+---+---+---+ " << endl;
        cout << i + 1 << " | " << board1.board[i][0].symb << " | " << board1.board[i][1].symb << " | " << board1.board[i][2].symb << " | " << board1.board[i][3].symb << " | " << board1.board[i][4].symb << " | " << board1.board[i][5].symb << " | " << board1.board[i][6].symb << " | " << board1.board[i][7].symb << " |" << endl;
    }
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    cout << "    1   2   3   4   5   6   7   8  " << endl;
}
int CheckCoord() {
    int coord;
    cin >> coord;
    if (coord < 9 && coord > 0) {
        return coord;
    }
    else {
        cout << "Choose another one!" << endl;
        CheckCoord();
    }
}
int main()
{
    cout << "\t\t\tWelcome to the CHECKERS v 1.0!\n";
    cout << "Wanna play a new game?" << endl;
    string answer;
    cin >> answer;
    if (answer == "yes") {
        cout << "Let's go!" << endl;

        Game game;
        int x, y;

        Display(game.board); 
        cout << endl;

        while (true) {
            cout << "Now its turn of " << game.CheckPlayer() << endl;
        coords:
            cout << "Choose a checker (input coords): " << endl;
            x = CheckCoord();
            y = CheckCoord();
            if (game.board.board[x][y].symb == ' ') { 
                cout << "Choose another coords, these are empty" << endl;
                goto coords;
            }
            else if ((game.board.board[x][y].symb == 'b' && game.CheckPlayer() == "Player 1") || game.board.board[x][y].symb == 'w' && game.CheckPlayer() == "Player 2") {
                cout << "Choose another coords, this checker is not yours" << endl;
            }
            if (CheckBeat(game.board, x, y)) {

            }

        }
    }
}
