#ifndef _QWIXX_PLAYER_H
#define _QWIXX_PLAYER_H

#include "Player.h"

class QwixxPlayer: public Player {
public:
	QwixxPlayer(std::string name);
	void inputAfterRoll(RollOfDice& rd);
	void inputBeforeRoll(RollOfDice& rd);
protected:
	std::string outputFromScoreSheet();
private:
	Colour chooseColour(std::string msg, RollOfDice&);
	bool twoWhites(RollOfDice& whites);
	bool combine(RollOfDice& rd);
};

#endif // _QWIXX_PLAYER_H
