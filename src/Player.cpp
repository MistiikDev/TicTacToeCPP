#include <iostream>
#include <Player.h>

Player::Player() {
    Player::b_isComputer = false;
    Player::userCharacter = ' ';
    Player::username = "";

    Player::b_isNone = true;
}

Player::Player(std::string& username, char userCharacter, bool b_isComputer = false) {
    Player::b_isComputer = b_isComputer;
    Player::userCharacter = userCharacter;
    Player::username = username;
}

Player::~Player() {
    
}