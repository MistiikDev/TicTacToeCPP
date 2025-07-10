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

short int Board::getPlayerPosition() {
    short int desiredPosition = -1;

    do {
        std::cout << "Enter desired grid position: " << std::endl;
        std::cin >> desiredPosition;

    } while (b_canUserMove(desiredPosition));

    return desiredPosition;
}

short int Board::getComputerPosition() {
    short int desiredPosition = -1;
    do {
        desiredPosition = rand() % getSize(); // This will yield indefinitely once the grid is full. TODO. Check instead "free" slots inside the grid to choose from.

    } while (b_canUserMove(desiredPosition));

    return desiredPosition;
}

bool Board::b_canUserMove(short int desiredPosition) {
    if (desiredPosition != -1 && desiredPosition >= 0 && desiredPosition <= getSize()) {
        return map[desiredPosition] == ' '; 
    }

    return false;
}

char Board::getUserPawn(UserType user) {
    if (user == UserType::player) {
        return 'x';
    } else if (user == UserType::computer) {
        return 'o';
    }

    return '/';
}

void Board::placeTurn(short int turnPosition, UserType user) {
    map[turnPosition] = getUserPawn(user);
}

UserType Board::checkWinner() {
    return UserType::null;
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