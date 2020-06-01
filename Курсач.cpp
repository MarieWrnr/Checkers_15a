#include <iostream>
#include <string>
#include "Figure.h"
#include "Checker.h"
#include "Board.h"
#include "Game.h"



using namespace std;


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
int main()
{
    cout << "\t\t\tWelcome to the CHECKERS v 1.0!\n";
    cout << "Wanna play a new game?" << endl;
    string answer;
    cin >> answer;
    if (answer == "yes") {
        cout << "Let's go!" << endl;

        Board board;
        Game game;
        int x, y;

        game.board.CreateBoard();
        Display(game.board);
        cout << endl;

        while (true) {
            cout << "Now its turn of " << game.CheckPlayer() << endl;
            cout << "Choose a checker (input coords): " << endl;
        condition:
            cin >> x >> y;
            if (x < 9 && y < 9 && x > 0 && y > 0) {

            }
            else {
                cout << "Wrong parameters, choose another one!" << endl;
                goto condition;
            }
        }
    }
}
