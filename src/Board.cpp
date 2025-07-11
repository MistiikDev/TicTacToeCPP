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

Board::~Board() {
    delete[] Board::map;
}

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
                std::cout << "Enter desired grid position: (0-" << (Board::boardArea - 1) << "):";
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

    UserType columnMajor = Board::checkColumn();
    UserType rowMajor = Board::checkRow();
    UserType diagMajor = Board::checkDiagonalFull();

    if (rowMajor != UserType::null) {
        return rowMajor;
    } else if (columnMajor != UserType::null) {
        return columnMajor;
    } else if (diagMajor != UserType::null) {
        return diagMajor;
    }

    if (remainingSlots == 0) {
        return UserType::both;
    }

    return UserType::null;
}

UserType Board::checkRow() {
    char currentUserTake = ' ';
    int occurences = 0;

    for (int i = 0; i < Board::boardArea; i += Board::boardLength) {
        currentUserTake = ' ';
        occurences = 0;

        for (int j = i; j < i + Board::boardLength; j++) {
            if (map[j] == map[i]) {
                occurences++;
            }
        } 

        if (occurences == Board::boardLength) {
            currentUserTake = map[i];

            break;
        }
    }

    return Board::getUserFromCharacter(currentUserTake);
}

UserType Board::checkColumn() {
    char currentUserTake = ' ';
    int occurences = 0;

    for (int i = 0; i < Board::boardLength; i++) {
        currentUserTake = ' ';
        occurences = 0;

        for (int j = i; j < i + (Board::boardLength * 2) + 1; j += Board::boardLength) {
            if (map[j] == map[i]) {
                occurences++;
            }
        }

        if (occurences == Board::boardLength) {
            currentUserTake = map[i];
            break;
        }
    }

    return Board::getUserFromCharacter(currentUserTake);
}

UserType Board::checkDiagonalFull() {
    char currentUserTake = ' ';
    int occurences = 0;

    // Left Diagonal
    for (int j = 0; j < Board::boardArea; j += Board::boardLength + 1) {
        if (map[j] == map[0]) {
            occurences++;
        }
    }

    
    if (occurences == Board::boardLength) {
        currentUserTake = map[0];
   
        return Board::getUserFromCharacter(currentUserTake);
    }

    currentUserTake = ' ';
    occurences = 0;

    // Right Diagonal
    for (int j = Board::boardLength - 1; j < (Board::boardArea - Board::boardLength) + 1; j += Board::boardLength - 1) {
        if (map[j] == map[Board::boardLength - 1]) {
            occurences++;
        }
    }

    
    if (occurences == Board::boardLength) {
        currentUserTake = map[Board::boardLength - 1];
                
        return Board::getUserFromCharacter(currentUserTake);
    }

    return UserType::null;
}