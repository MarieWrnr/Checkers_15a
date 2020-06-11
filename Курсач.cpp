#include <iostream>
#include <vector>
#include <string>
#include "Figure.h"
#include "Checker.h"
#include "Board.h"
#include "Game.h"
#include "Queen.h"



using namespace std;

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

        game.Display();
         
        cout << endl;

        while (true) {
            cout << "Now its turn of " << game.CheckPlayer() << endl;
        coords:
            cout << "Choose a checker (input coords): " << endl;
            x = CheckCoord();
            y = CheckCoord();
            if (game.GetGameBoard().IsEmpty(x, y)) { 
                cout << "Choose another coords, these are empty" << endl;
                goto coords;
            }
            else if ((game.GetGameBoard().HasCheckerB(x, y) && game.CheckPlayer() == "Player 1") || !game.GetGameBoard().HasCheckerB(x, y) == 'w' && game.CheckPlayer() == "Player 2") {
                cout << "Choose another coords, this checker is not yours" << endl;
            }
           cout << game.GetGameBoard().GetBoardVector()[x - 1][y - 1]->CanBeat(game.GetGameBoard()) << endl;
           game.ChangePlayer(game.CheckPlayer());
        } //дохрена всего короче менять надо, я спать
    }
}
