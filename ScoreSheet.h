#ifndef _SCORE_SHEET_H
#define _SCORE_SHEET_H

#include <string>
#include <iostream>

#include "RollOfDice.h"
#include "Dice.h"

class ScoreSheet {
public:
	ScoreSheet();
	ScoreSheet(std::string playerName, int failedAttempts=0, int score=0);
	bool score(RollOfDice rd, Colour c, int offset=-1);
	bool fail();
	int setTotal();
	virtual bool operator!() const = 0;
	friend std::ostream& operator<< (std::ostream& os, const ScoreSheet& ss);
protected:
	virtual bool validate(RollOfDice rd, Colour c, int offset) = 0;
	virtual void calcTotal() = 0;
	virtual std::ostream& printSheet(std::ostream& os) const = 0;
	const std::string playerName;
	int failedAttempts;
	int gameScore;
};

#endif //_SCORE_SHEET
