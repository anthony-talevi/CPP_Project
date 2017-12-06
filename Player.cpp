#ifndef _PLAYER_CPP
#define _PLAYER_CPP
#include <string>

#include "Player.h"

Player::Player(): active(false), playerName("bot") {};
Player::Player(std::string name): active(false), playerName(name) {};

bool Player::isActive() {
	return active;
}

void Player::activate() {
	active = true;
}

void Player::deactivate() {
	active = false;
}

std::string Player::getName() {
	return playerName;
}
#endif
