#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <Board.h>
#include <Player.h>

struct User {
    std::string username;
    
    char character;
    int numberOfWins;
    bool b_isComputer;
};

class Game {
    public: 
        Game(std::string& GameTitle);
        
        std::string gameTitle;
        bool b_isGameOver;

        Player* players;
        UserType winner;
        Board* map;

        virtual void startGame();
        virtual void userTurn(UserType user);
        virtual void stopGame(const UserType& winner);

        ~Game();
};

#endif 