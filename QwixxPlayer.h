#include "Player.h"

#ifndef _QWIXX_PLAYER_H
#define _QWIXX_PLAYER_H

class QwixxPlayer: public Player {
public:
	QwixxPlayer(std::string name);
protected:
	void inputAfterRoll(RollOfDice& rd);
	void inputBeforeRoll(RollOfDice& rd);
};

#endif // _QWIXX_PLAYER_H
