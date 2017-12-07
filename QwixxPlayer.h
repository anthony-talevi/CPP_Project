#ifndef _QWIXX_PLAYER_H
#define _QWIXX_PLAYER_H

#include "Player.h"

class QwixxPlayer: public Player {
public:
	QwixxPlayer(std::string name);
	void inputAfterRoll(RollOfDice& rd);
	void inputBeforeRoll(RollOfDice& rd);
private:
	Colour chooseColour();
};

#endif // _QWIXX_PLAYER_H
