#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <Board.h>
#include <Player.h>

enum Outcome {
    PlayerWin,
    ComputerWin, 
    Tie,
    Null,
};

class Game {
    public: 
        Game(std::string& GameTitle);
        
        std::string gameTitle;
        bool b_isGameOver;
        int playerCount; 

        Player winner;
        Player* players;
        Board* map;

        virtual void startGame(Player* players, int playerCount);
        virtual void userTurn(Player& player);
        virtual void stopGame(Outcome outcome, Player& winner);

        ~Game();
};

#endif 