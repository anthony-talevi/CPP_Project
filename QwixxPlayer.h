#ifndef _QWIXX_PLAYER_H
#define _QWIXX_PLAYER_H

#include "Player.h"

class QwixxPlayer: public Player {
public:
	QwixxPlayer(std::string name);
protected:
	void inputAfterRoll(RollOfDice& rd);
	void inputBeforeRoll(RollOfDice& rd);
private:
	Colour chooseColour();
	int choosePosition(RollOfDice, Colour);
};

#endif // _QWIXX_PLAYER_H
