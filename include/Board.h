#ifndef BOARD_H
#define BOARD_H

enum UserType {
    player,
    computer,
    null
};

class Board {
    public:
        Board(int length) {
            boardLength = length;
            map = new char[length * length];

            for (int i = 0; i < length * length; i++) {
                map[i] = ' ';
            }
        };

        unsigned int boardLength {};
        char* map {};
        
        virtual char getUserPawn(UserType user);
        virtual unsigned int getSize();

        
        virtual short int getPlayerPosition();
        virtual short int getComputerPosition();


        virtual bool b_canUserPlayerMove(short int desiredPosition);


        virtual void displayBoard();
        virtual void placeTurn(short int turnPosition, UserType user);

        virtual UserType checkWinner();

        ~Board() {
            delete[] map;
        }

    private:
        virtual UserType checkDiagonalFull();
        virtual UserType checkRow();
        virtual UserType checkColumn();
};

#endif