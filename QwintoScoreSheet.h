#include "ScoreSheet.h"

#ifndef _QWINTO_SCORE_SHEET_H
#define _QWINTO_SCORE_SHEET_H

class QwintoScoreSheet:public ScoreSheet {
public:
	QwintoScoreSheet(std::string name);
protected:
	bool validate(RollOfDice rd, Colour c, int offset);
	void calcTotal();
private:
	const std::string test = "Qwinto";
};

#endif // _QWINTO_SCORE_SHEET_H
