#include <iostream>
#include <Game.h>

Game::Game(std::string& GameTitle) {
    Game::gameTitle = GameTitle;
}

Game::~Game() {
    delete Game::map;
}

void Game::startGame() {
    Game::winner = UserType::null;
    Game::b_isGameOver = false;

    std::cout << "Welcome to " << Game::gameTitle << std::endl;

    Game::map = new Board(3); // hard coded for now.
    
    while (!Game::b_isGameOver) {
        Game::map->displayBoard();

        Game::userTurn(UserType::player);
        Game::userTurn(UserType::computer);
    }
}

void Game::userTurn(UserType user) {
    if (b_isGameOver) {return;}

    UserType currentWinner = Game::map->checkWinner();

    if (currentWinner != UserType::null) {
        Game::stopGame(currentWinner);
        
        return;
    };

    short int desiredPosition = Game::map->getUserPosition(user);

    Game::map->placeTurn(desiredPosition, user);
}

void Game::stopGame(const UserType& winner) {
    Game::winner = winner;
    Game::b_isGameOver = true;

    std::cout << std::endl;
    std::cout << "************** GAME OVER **************" << std::endl;
    std::cout << std::endl;
    
    Game::map->displayBoard();

    std::cout << std::endl;

    if (winner == UserType::both) {
        std::cout << "Tie! No one wins." << std::endl;
    } else {
        std::cout <<  Game::map->getUsername(Game::winner) << " wins the game!" << std::endl;
    }

    delete Game::map;
}