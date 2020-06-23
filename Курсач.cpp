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
    //заменить обращения на переменные для удобства чтения
    cout << "\t\t\tWelcome to the CHECKERS v 1.0!\n";
    cout << "Wanna play a new game?" << endl;
    string answer;
    cin >> answer;
    if (answer == "yes") {
        cout << "Let's go!" << endl;

        Game game;
        int x, y;


        while (true) { //process of game
            game.Display(); //отображение текущей доски

            cout << endl;
            cout << "Now its turn of " << game.CheckPlayer() << endl; //проверка игрока

        coords: //отправная точка для ввода координат шашки

            cout << "Choose a checker (input coords): " << endl;
            x = CheckCoord(); //проверка координат (выход за пределы массива)
            y = CheckCoord();

            if (game.GetGameBoard().IsEmpty(x, y)) { 
                /*блок кода проверяет, является ли выбранная шашка пустой*/

                cout << "Choose another coords, these are empty" << endl;
                goto coords;
            }

            else if ((game.GetGameBoard().HasCheckerB(x, y) && game.CheckPlayer() == "Player 1") || !game.GetGameBoard().HasCheckerB(x, y) && game.CheckPlayer() == "Player 2") {
                /*блок кода, который провряет, соответствует ли выбранная шашка цвету игрока*/

                cout << "Choose another coords, this checker is not yours" << endl;
                goto coords;
            }
            
            int x1, y1; //убрать проверки на пустоту из CanBeat и добавить одну сюда
            if(!game.GetGameBoard().GetBoardVector()[x - 1][y - 1]->CanBeat(game.GetGameBoard(), x, y)) { 
               //может ли бить текущая шашка 
               bool curr = false; //определяет в цикле, может ли бить хотя бы какая-то шашка
               //game.GetGameBoard().GetBoardVector()[6][2]->CanBeat(game.GetGameBoard(), c1, c2); //не работает только в конкретном случае
               for (int i = 1; i < 9; i++) {//могут ли бить остальные шашки
                   for (int j = 1; j < 9; j++) {
                       if (!game.GetGameBoard().IsEmpty(i, j)) { 
                           curr = game.GetGameBoard().GetBoardVector()[i - 1][j - 1]->CanBeat(game.GetGameBoard(), i, j);
                           if (!game.GetGameBoard().HasCheckerB(i, j) && game.CheckPlayer() == "Player 1" || game.GetGameBoard().HasCheckerB(i, j) && game.CheckPlayer() == "Player 2") {
                               if (curr) {
                                   cout << "Please, find a checker to beat your opponent" << endl;
                                   goto coords;
                               }
                           }
                       }
                   }
               }

               if (!game.GetGameBoard().GetBoardVector()[x - 1][y - 1]->CanMove(game.GetGameBoard(), x, y)) {
                   cout << "Please, find a checker has an opportunity to move" << endl;
                   goto coords;
               }

               cout << "Choose coords to make a move: " << endl;
               coords1: //отправная точка для ввода координат хода
               x1 = CheckCoord();
               y1 = CheckCoord();
               if (game.GetGameBoard().IsEmpty(x1, y1)) {
                   /*блок кода, проверяющий клетку на свободность и успешное выполнение хода; 
                   иначе отправляет снова вводить координаты*/
                   if (!game.GetGameBoard().GetBoardVector()[x - 1][y - 1]->Move(x1, y1, game.GetGameBoard())) {
                       cout << "Wrong coords, choose another:" << endl;
                       goto coords1;
                   }
               }
               else {
                   cout << "This cell is busy!" << endl;
                   goto coords1;
               }
            }
            else {
                cout << "congrats! You've achieved the hit" << endl;
                coords2:
                x1 = CheckCoord();
                y1 = CheckCoord();
                if (game.GetGameBoard().IsEmpty(x1, y1)) {
                    if (!game.GetGameBoard().GetBoardVector()[x - 1][y - 1]->Hit(x1, y1, game.GetGameBoard())) {
                        cout << "You can not beat, choose another coords:" << endl;
                        goto coords2;
                    }
                }
                else {
                    cout << "This cell is busy!" << endl;
                    goto coords2;
                }
            }
            if (game.GetGameBoard().GetBlacks() == 0) {
                game.GetWinner("Player 1");
                exit(0);
            }
            else if (game.GetGameBoard().GetWhites() == 0) {
                game.GetWinner("Player 2");
                exit(0);
            }
           game.SetMove();
        } 
    }
}
