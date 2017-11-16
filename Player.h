#include <string>

#include "RollOfDice.h"

#ifndef _PLAYER_H
#define _PLAYER_H

class Player {
public:
	Player();
	Player(std::string name);
	bool isActive();
	void activate();
	void deactivate();
	std::string getName();
protected:
	virtual void inputBeforeRoll(RollOfDice& rd) =0;
	virtual void inputAfterRoll(RollOfDice& rd) =0;
private:
	bool active;
	std::string playerName;
};

#endif // _PLAYER_H
