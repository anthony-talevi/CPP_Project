#include "Player.h"

#ifndef _QWINTO_PLAYER_H
#define _QWINTO_PLAYER_H

class QwintoPlayer: public Player {
public:
	QwintoPlayer(std::string name);
protected:
	void inputAfterRoll(RollOfDice& rd);
	void inputBeforeRoll(RollOfDice& rd);
};

#endif // _QWINTO_PLAYER_H
