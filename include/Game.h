#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <Board.h>

class Game {
    public: 
        std::string gameTitle;

        Game(std::string& GameTitle) {
            gameTitle = GameTitle;
        }

        bool b_isGameOver;
        
        Board* map;
        char winner;
        char* players;

        virtual void startGame(char* players);
        
        virtual void playerTurn();
        virtual void computerTurn();

        virtual void stopGame(const char& winner);

        ~Game() {
            delete[] map;
            delete[] players;
        }
};

#endif 