#include <iostream>
#include <Game.h>

Game::Game(std::string& GameTitle) {
    this->gameTitle = GameTitle;
}

Game::~Game() {
    delete this->map;
    delete[] this->players;
    
    delete this;
}

void Game::startGame(Player* players, int playerCount) {
    this->winner = Player::NullPlayer;
    this->b_isGameOver = false;

    std::cout << "Welcome to " << Game::gameTitle << std::endl;

    this->map = new Board(this, 3);
    this->players = players;
    this->playerCount = playerCount;

    while (!Game::b_isGameOver) {
        this->map->displayBoard();

        for (int i = 0; i < playerCount; i++) {
            this->userTurn(this->players[i]);
        }
    }
}

void Game::userTurn(Player& player) {
    if (b_isGameOver) {return;}

    Outcome currentOutcome = this->map->checkWinner();

    if (currentOutcome != Outcome::Null) {
        this->stopGame(currentOutcome, this->map->dominantPlayer);
        
        return;
    };

    short int desiredPosition = this->map->getPlayerPosition(player);

    this->map->placeTurn(desiredPosition, player);
}

void Game::stopGame(Outcome outcome, Player& winner) {
    this->winner = winner;
    this->b_isGameOver = true;

    std::cout << std::endl;
    std::cout << "************** GAME OVER **************" << std::endl;
    std::cout << std::endl;
    
    this->map->displayBoard();

    std::cout << std::endl;

    if (outcome== Outcome::Tie) {
        std::cout << "Tie! No one wins." << std::endl;
    } else {
        std::cout << winner.username << " wins the game!" << std::endl;
    }

    delete this->map;
}