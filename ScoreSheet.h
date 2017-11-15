#include <string>

#include "RollOfDice.h"
#include "Dice.h"
#include "Player.h"

#ifndef _SCORE_SHEET_H
#define _SCORE_SHEET_H

class ScoreSheet {
public:
	ScoreSheet();
	ScoreSheet(std::string playerName, int failedAttempts=0, int score=0);
	bool score(RollOfDice rd, Colour c, int offset=-1);
	int setTotal();
protected:
	virtual bool validate(RollOfDice rd, Colour c, int offset) = 0;
	virtual void calcTotal() = 0;
	const std::string playerName;
	int failedAttempts;
	int gameScore;
};

#endif //_SCORE_SHEET
