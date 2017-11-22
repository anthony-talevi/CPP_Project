 #include "ScoreSheet.h"

#ifndef _QWIXX_SCORE_SHEET_H
#define _QWIXX_SCORE_SHEET_H

class QwixxScoreSheet:public ScoreSheet {
public:
	QwixxScoreSheet(std::string name);
protected:
	bool validate(RollOfDice rd, Colour c, int offset);
	void calcTotal();
private:
	const std::string test = "Qwixx";
};

#endif // _QWIXX_SCORE_SHEET_H
