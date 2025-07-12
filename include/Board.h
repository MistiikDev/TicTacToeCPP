#ifndef BOARD_H
#define BOARD_H

#include <Player.h>

class Board {
    public:
        static bool b_canPlayerMove(char* map, short int mapArea, short int desiredPosition) {
            if (desiredPosition != -1 && desiredPosition >= 0 && desiredPosition <= mapArea) {
                return map[desiredPosition] == ' '; 
            }

            return false;
        }

        static unsigned int getRemainingSlots(char* map, int mapArea) {
            unsigned int remainingSlots = 0;

            for (int i = 0; i < mapArea; i++) {
                if (map[i] == ' ') {
                    remainingSlots += 1;
                } 
            }

            return remainingSlots;
        }

        static void displayBoard(char* map, int boardLength, int boardArea) {
            for (int i = 0; i < boardArea; i++) {
                std::cout << "| " << map[i] << " |";

                if (i != 0 && (i + 1) % boardLength == 0) {
                    std::cout << std::endl;
                }
            }
        }

        Game* currentGameInstance;
        Player dominantPlayer;

        char* map {};
        const char playerSkin = 'x';
        const char computerSkin = 'o';

        unsigned int boardLength {};
        unsigned int boardArea {};

        virtual short int getPlayerPosition(Player& player);
        virtual void displayBoard();

        virtual Outcome checkWinner();

        void placeTurn(short int turnPosition, Player& player) {
            Board::map[turnPosition] = player.userCharacter;
        }

        Player getDominantRowPlayer(char* map, int mapLength, int mapArea) {
            char currentUserTake = ' ';
            int occurences = 0;

            for (int i = 0; i < mapArea; i += mapArea) {
                currentUserTake = ' ';
                occurences = 0;

                for (int j = i; j < i + mapLength; j++) {
                    if (map[j] == map[i]) {
                        occurences++;
                    }
                } 

                if (occurences == mapLength) {
                    currentUserTake = map[i];

                    break;
                }
            }

            return Player::getPlayerFromCharacter(currentGameInstance->players, currentUserTake, currentGameInstance->playerCount);
        }

        Player getDominantColumnPlayer(char* map, int mapLength) {
            char currentUserTake = ' ';
            int occurences = 0;

            for (int i = 0; i < mapLength; i++) {
                currentUserTake = ' ';
                occurences = 0;

                for (int j = i; j < i + (mapLength * 2) + 1; j += mapLength) {
                    if (map[j] == map[i]) {
                        occurences++;
                    }
                }

                if (occurences == mapLength) {
                    currentUserTake = map[i];
                    break;
                }
            }

            return Player::getPlayerFromCharacter(currentGameInstance->players, currentUserTake, currentGameInstance->playerCount);
        }

        Player getDominantDiagonalPlayer(char* map, int mapLength, int mapArea) {
            char currentUserTake = ' ';
            int occurences = 0;

            // Left Diagonal
            for (int j = 0; j < mapArea; j += mapLength + 1) {
                if (map[j] == map[0]) {
                    occurences++;
                }
            }

            
            if (occurences == mapLength) {
                currentUserTake = map[0];
        
                return Player::getPlayerFromCharacter(currentGameInstance->players, currentUserTake, currentGameInstance->playerCount);
            }

            currentUserTake = ' ';
            occurences = 0;

            // Right Diagonal
            for (int j = mapLength - 1; j < (mapArea - mapLength) + 1; j += mapLength - 1) {
                if (map[j] == map[mapLength - 1]) {
                    occurences++;
                }
            }

            if (occurences == mapLength) {
                currentUserTake = map[mapLength - 1];
                        
                return Player::getPlayerFromCharacter(currentGameInstance->players, currentUserTake, currentGameInstance->playerCount);
            }

            return Player::NullPlayer;
        }

        Board(Game* game, unsigned int length);
        ~Board();
};



#endif