#include "RollOfDice.h"
#include "Dice.h"

#ifndef _SCORE_SHEET_H
#define _SCORE_SHEET_H

class ScoreSheet {
public:
	void score(RollOfDice rd, Colour c, int offset);
};

#endif //_SCORE_SHEET
