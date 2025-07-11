#ifndef BOARD_H
#define BOARD_H

enum UserType {
    player,
    computer,
    null,
    tie
};

class Board {
    public:
        Board(unsigned int length);

        char* map {};
        const char playerSkin = 'x';
        const char computerSkin = 'o';

        unsigned int boardLength {};
        unsigned int boardArea {};
        virtual short int getUserPosition(UserType user);

        virtual bool b_canUserMove(short int desiredPosition);

        virtual void displayBoard();
        virtual UserType checkWinner();
        
        unsigned int getRemainingSlots() {
            unsigned int remainingSlots = 0;
            for (int i = 0; i < Board::boardArea; i++) {
                if (Board::map[i] == ' ') {
                    remainingSlots += 1;
                } 
            }

            return remainingSlots;
        }

        char getUserCharacter(UserType user) {
            switch (user) {
                case UserType::player: return Board::playerSkin;
                case UserType::computer: return Board::computerSkin;
                case UserType::null: return '/';

                default: return '+';
            }

            return '/';
        }


        UserType getUserFromCharacter(char& character) {
            if (character == Board::playerSkin) {
                return UserType::player;
            } else if (character == Board::computerSkin) {
                return UserType::computer;
            }

            return UserType::null;
        }

        std::string getUsername(UserType user) {
            switch (user) {
                case UserType::player: return "Player";
                case UserType::computer: return "Computer";
                case UserType::null: return "NULL";

                default: return "VOID";
            }
        }

        void placeTurn(short int turnPosition, UserType user) {
            Board::map[turnPosition] = Board::getUserCharacter(user);
        }

        ~Board() {
            delete[] map;
        }

    private:
        virtual UserType checkDiagonalFull();
        virtual UserType checkRow();
        virtual UserType checkColumn();
};



#endif