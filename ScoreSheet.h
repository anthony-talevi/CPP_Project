#ifndef _SCORE_SHEET_H
#define _SCORE_SHEET_H

#include <string>

#include "RollOfDice.h"
#include "Dice.h"

class ScoreSheet {
public:
	ScoreSheet();
	ScoreSheet(std::string playerName, int failedAttempts=0, int score=0);
	bool score(RollOfDice rd, Colour c, int offset=-1);
	int setTotal();
	void print(std::ostream& os);
protected:
	virtual bool validate(RollOfDice rd, Colour c, int offset) = 0;
	virtual void calcTotal() = 0;
	virtual void printSheet(std::ostream& os) = 0;
	void printZero(std::ostream& s, int n); 
	const std::string playerName;
	int failedAttempts;
	int gameScore;
};

#endif //_SCORE_SHEET
