#include <iostream>
#include <Game.h>

int main() {
    std::string gameTitle = "Tic Tac Toe!";
    Game TicTacToe(gameTitle);

    TicTacToe.startGame();

    return 0;
}