#include <iostream>
#include <Player.h>

Player::Player() {
    Player::b_isComputer = true;
    Player::userCharacter = 'o';
    Player::username = "Computer";
}


Player::Player(std::string& username, char& userCharacter) {
    Player::userCharacter = userCharacter;
    Player::username = username;
}

Player::~Player() {
    
}