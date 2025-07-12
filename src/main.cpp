#include <iostream>
#include <Game.h>

int main() {
    std::string gameTitle = "Tic Tac Toe!";
    Game TicTacToe(gameTitle);

    while (true) {
        TicTacToe.startGame();

        char answer = 'n';
        
        std::cout << "Do you want to play again ? (y/n): ";
        std::cin >> answer;
        
        if (answer != 'y') {
            break;
        }
    };

    return 0;
}