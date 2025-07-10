#include <iostream>
#include <Board.h>

unsigned int Board::getSize()
{
    return boardLength * boardLength;
}

void Board::displayBoard()
{
    for (int i = 0; i < getSize(); i++)
    {
        std::cout << "| " << map[i] << " |";

        if (i != 0 && (i + 1) % boardLength == 0)
        {
            std::cout << std::endl;
        }
    }
}

short int Board::getUserPosition(UserType user) {
    short int desiredPosition = -1;
    
    int remainingSlots = 0;
    // Get remaining slots
    for (int i = 0; i < getSize(); i++) {
        if (map[i] == ' ') {
            remainingSlots += 1;
        } 
    }

    if (remainingSlots != 0) {
        do {
            if (user == UserType::player) {
                std::cout << "Enter desired grid position: " << std::endl;
                std::cin >> desiredPosition;

            } else if (user == UserType::computer) {
                desiredPosition = rand() % getSize();
            }

        } while (!b_canUserMove(desiredPosition));
    }

    return desiredPosition;
}

bool Board::b_canUserMove(short int desiredPosition) {
    if (desiredPosition != -1 && desiredPosition >= 0 && desiredPosition <= getSize()) {
        return map[desiredPosition] == ' '; 
    }

    return false;
}

char Board::getUserSkin(UserType user) {
    switch (user) {
        case UserType::player: return Board::playerSkin;
        case UserType::computer: return Board::computerSkin;
        case UserType::null: return '/';

        default: return '+';
    }
    
    return '/';
}
std::string Board::getUsername(UserType user) {
    switch (user) {
        case UserType::player: return "Player";
        case UserType::computer: return "Computer";
        case UserType::null: return "NULL";

        default: return "VOID";
    }
}


void Board::placeTurn(short int turnPosition, UserType user) {
    map[turnPosition] = getUserSkin(user);
}

UserType Board::checkWinner() {
    Board::checkColumn();
    Board::checkRow();
    Board::checkDiagonalFull();

    return UserType::player;
}

UserType Board::checkRow() {
    return UserType::null;
}

UserType Board::checkColumn() {
    return UserType::null;
}

UserType Board::checkDiagonalFull() {
    return UserType::null;
}