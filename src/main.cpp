#include <iostream>
#include <Game.h>

int main() {
    char player = 'x';
    char computer = 'o';

    char* players = new char[2] {player, computer};

    std::string gameTitle = "Tic Tac Toe!";
    Game TicTacToe(gameTitle);

    TicTacToe.startGame(players);

    return 0;
}