#include <iostream>
#include <Game.h>

int main() {
    std::string gameTitle = "Tic Tac Toe!";

    while (true){
        Game TicTacToe(gameTitle);
        TicTacToe.startGame();

        char answer = 'n';
        
        std::cout << "Do you want to play again ? (y/n): ";
        std::cin >> answer;

        if (answer != 'y') {
            exit(EXIT_SUCCESS);
        }
    };

    return 0;
}