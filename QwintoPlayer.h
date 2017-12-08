#ifndef _QWINTO_PLAYER_H
#define _QWINTO_PLAYER_H

#include "Player.h"

class QwintoPlayer: public Player {
	bool verifyChoice(Colour, RollOfDice&);
public:
	QwintoPlayer(std::string name);
	void inputAfterRoll(RollOfDice& rd);
	void inputBeforeRoll(RollOfDice& rd);
};

#endif // _QWINTO_PLAYER_H
