#include <iostream>
#include <Board.h>
#include <Game.h>
#include <ctime>

// Constructor
Board::Board(Game* game, unsigned int length)
{
    srand(time(NULL));

    this->boardLength = length;
    this->boardArea = length * length ;
    this->map = new char[length * length];

    for (int i = 0; i < length * length; i++) {
        this->map[i] = ' ';
    }

    this->currentGameInstance = game;
    this->dominantPlayer = Player::NullPlayer;
};

Board::~Board() {
    delete[] this->map;
    delete this->currentGameInstance;
}

// Implementations

short int Board::getPlayerPosition(Player& player) {
    short int desiredPosition = -1;
    unsigned int remainingSlots = Board::getRemainingSlots(this->map, this->boardArea);

    if (remainingSlots != 0) {
        do {
            if (!player.b_isComputer) {
                std::cout << "Enter desired grid position: (0-" << (this->boardArea - 1) << "):";
                std::cin >> desiredPosition;

            } else {
                desiredPosition = rand() % this->boardArea;
            }

        } while (!Board::b_canPlayerMove(this->map, this->boardArea, desiredPosition));
    }

    return desiredPosition;
}

Outcome Board::checkWinner() {
    unsigned int remainingSlots = Board::getRemainingSlots(this->map, this->boardArea);

    Player columnMajor = Board::getDominantColumnPlayer(this->map, this->boardLength);
    
    if (!(columnMajor == Player::NullPlayer)) {
        dominantPlayer = columnMajor;
        
        return columnMajor.b_isComputer ? Outcome::ComputerWin : Outcome::PlayerWin;
    }

    Player rowMajor = Board::getDominantRowPlayer(this->map, this->boardLength, this->boardArea);
    
    if (!(rowMajor == Player::NullPlayer)) {
        dominantPlayer = rowMajor;
        
        return rowMajor.b_isComputer ? Outcome::ComputerWin : Outcome::PlayerWin;
    }

    Player diagMajor = Board::getDominantDiagonalPlayer(this->map, this->boardLength, this->boardArea);
    
    if (!(diagMajor == Player::NullPlayer)) {
        dominantPlayer = diagMajor;
        
        return diagMajor.b_isComputer ? Outcome::ComputerWin : Outcome::PlayerWin;
    }

    if (remainingSlots == 0) {
        return Outcome::Tie;
    }

    return Outcome::Null;
}