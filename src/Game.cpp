#include <iostream>
#include <Game.h>
#include <ctime>

Game::Game(std::string& GameTitle) {
    Game::gameTitle = GameTitle;
}

void Game::startGame() {
    Game::winner = UserType::null;
    Game::b_isGameOver = false;

    std::cout << "Welcome to " << Game::gameTitle << std::endl;

    Game::map = new Board(3); // hard coded for now.
    Game::map->displayBoard();
    
    while (!Game::b_isGameOver) {
        Game::userTurn(UserType::player);
        Game::userTurn(UserType::computer);

        Game::map->displayBoard();
        Game::map->checkWinner();
    }
}

void Game::userTurn(UserType user) {
    short int desiredPosition = Game::map->getUserPosition(user);
   
    if (desiredPosition == -1) { // No more slots left. Check win ?
        UserType winner = Game::map->checkWinner();
        Game::stopGame(winner);

        return;
    }

    Game::map->placeTurn(desiredPosition, user);
}

void Game::stopGame(const UserType& winner) {
    Game::winner = winner;
    Game::b_isGameOver = true;

    std::cout << "Winner is " << Game::map->getUsername(Game::winner) << std::endl;
    
    delete[] Game::map;
}