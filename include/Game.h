#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <Board.h>

class Game {
    public: 
        Game(std::string& GameTitle);
        
        std::string gameTitle;
        bool b_isGameOver;
        
        UserType winner;
        Board* map;

        virtual void startGame();
        virtual void userTurn(UserType user);
        virtual void stopGame(const UserType& winner);

        ~Game() {
            delete[] map;
        }
};

#endif 