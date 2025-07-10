#include <iostream>
#include <Game.h>
#include <ctime>

void Game::startGame(char* players) {
    Game::winner = '/';
    Game::b_isGameOver = false;
    Game::players = players;

    std::cout << "Welcome to " << Game::gameTitle << std::endl;

    Game::map = new Board(3);

    while (!Game::b_isGameOver) {
        Game::playerTurn();
        Game::computerTurn();

        Game::map->displayBoard();
        Game::map->checkWinner();
    }
}

void Game::playerTurn() {
    short int desiredPosition = Game::map->getPlayerPosition();
   
    Game::map->placeTurn(desiredPosition, UserType::player);
}

void Game::computerTurn() {
    short int desiredPosition = Game::map->getComputerPosition();

    if (Game::map->b_canUserPlayerMove(desiredPosition)) {
        Game::map->placeTurn(desiredPosition, UserType::computer);
    }
}

void Game::stopGame(const char& winner) {
    Game::winner = winner;
    Game::b_isGameOver = true;

    delete[] Game::players;
    delete[] Game::map;

    std::cout << "Winner is " << Game::winner << std::endl;
}