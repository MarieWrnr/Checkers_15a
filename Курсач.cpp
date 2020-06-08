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
void CheckBeat(Board& board, int x, int y) {
    bool curbeaten;
    if (board.board[x - 1][y - 1].symb == 'W') {
        if (!board.board[x][y].isQueen) {
            if (x != 8 && y != 8 && x != 1 && y != 1 && y-1 != 1 && y+1 != 8) {
                if (board.board[x][y].symb == 'B') {
                    if (board.board[x + 1][y + 1].symb == ' ') {
                        curbeaten = true;
                    }
                }
                else if (board.board[x][y - 2].symb == 'B') {
                    if (board.board[x + 1][y - 3].symb == ' ') {
                        curbeaten = true;
                    }
                }
            }
            else {
                if (y == 1) {
                    if (board.board[x][1].symb == 'B') {
                        if (board.board[x + 1][2].symb == ' ') {
                            curbeaten = true;
                        }
                    }
               }
                else if (y == 2) {

                }

            }
        }
    }
    for (int i = 0; i < 8; i++) {
        if (i < 4) {

        }
    }
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
            else if ((game.board.board[x][y].symb == 'B' && game.CheckPlayer() == "Player 1") || game.board.board[x][y].symb == 'W' && game.CheckPlayer() == "Player 2") {
                cout << "Choose another coords, this checker is not yours" << endl;
            }
            CheckBeat(game.board, x, y);
        }
    }
}
