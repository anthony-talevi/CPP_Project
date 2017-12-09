#include <string>

#include "Player.h"

Player::Player(): active(false), playerName("bot") {};
Player::Player(std::string name): active(false), playerName(name) {};

//returns whether the player is active or not
bool Player::isActive() {
	return active;
}

//sets the player active
void Player::activate() {
	active = true;
}

//deactivates the player
void Player::deactivate() {
	active = false;
}

//gets the name of the player
std::string Player::getName() {
	return playerName;
}
