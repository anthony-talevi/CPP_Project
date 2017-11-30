<<<<<<< HEAD
 #include "ScoreSheet.h"

=======
>>>>>>> remotes/origin/connor
#ifndef _QWIXX_SCORE_SHEET_H
#define _QWIXX_SCORE_SHEET_H

#include "ScoreSheet.h"

class QwixxScoreSheet:public ScoreSheet {
public:
	QwixxScoreSheet(std::string name);
protected:
	bool validate(RollOfDice rd, Colour c, int offset);
	void calcTotal();
	void printSheet(std::ostream& os);
private:
	const std::string test = "Qwixx";
};

#endif // _QWIXX_SCORE_SHEET_H
