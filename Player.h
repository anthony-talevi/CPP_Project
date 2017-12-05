#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>

#include "RollOfDice.h"
#include "ScoreSheet.h"

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
	ScoreSheet* ss;
	std::vector<Dice> removed_for_roll;		//Used to store dice temporarily
											//for readdition to the
											//RollOfDice after player's turn
private:
	bool active;
	std::string playerName;
};

#endif // _PLAYER_H
