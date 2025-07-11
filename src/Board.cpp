#include <iostream>
#include <Board.h>
#include <ctime>

// Constructor
Board::Board(unsigned int length)  
{
    srand(time(NULL));
    boardLength = length;
    boardArea = length * length ;

    map = new char[length * length];

    for (int i = 0; i < length * length; i++) {
        map[i] = ' ';
    }
};

// Implementations
void Board::displayBoard() {
    for (int i = 0; i < Board::boardArea; i++) {
        std::cout << "| " << Board::map[i] << " |";

        if (i != 0 && (i + 1) % Board::boardLength == 0) {
            std::cout << std::endl;
        }
    }
}

short int Board::getUserPosition(UserType user) {
    short int desiredPosition = -1;
    
    unsigned int remainingSlots = Board::getRemainingSlots();

    if (remainingSlots != 0) {
        do {
            if (user == UserType::player) {
                std::cout << "Enter desired grid position: " << std::endl;
                std::cin >> desiredPosition;

            } else if (user == UserType::computer) {
                desiredPosition = rand() % Board::boardArea;
            }

        } while (!Board::b_canUserMove(desiredPosition));
    }

    return desiredPosition;
}

bool Board::b_canUserMove(short int desiredPosition) {
    if (desiredPosition != -1 && desiredPosition >= 0 && desiredPosition <= Board::boardArea) {
        return Board::map[desiredPosition] == ' '; 
    }

    return false;
}

UserType Board::checkWinner() {
    unsigned int remainingSlots = Board::getRemainingSlots();

    if (remainingSlots == 0) {
        return UserType::tie;
    }

    UserType c_winner; 
    UserType r_winner;
    UserType d_winner; 
    
    c_winner = Board::checkColumn();
    r_winner = Board::checkRow();
    d_winner = Board::checkDiagonalFull();

    return r_winner;
}

UserType Board::checkRow() {
    char currentUserTake = ' ';
    int occurences = 0;

    for (int i = 0; i < Board::boardArea; i += Board::boardLength) {
        currentUserTake = map[i];
        
        for (int j = i; j < Board::boardLength; j++) {
            if (Board::map[j] != currentUserTake) {
                currentUserTake = ' ';
                break;
            }

            occurences += 1;
        }

        if (occurences == Board::boardLength) {
            break;
        }
    }

    return Board::getUserFromCharacter(currentUserTake);
}

UserType Board::checkColumn() {
    return UserType::null;
}

UserType Board::checkDiagonalFull() {
    return UserType::null;
}