#ifndef _QWINTO_SCORE_SHEET_H
#define _QWINTO_SCORE_SHEET_H

#include "ScoreSheet.h"
#include "Dice.h"
#include "QwintoRow.cpp"

class QwintoScoreSheet:public ScoreSheet {
public:
	QwintoScoreSheet(std::string name);
protected:
	bool validate(RollOfDice rd, Colour c, int offset);
	void calcTotal();
	void printSheet(std::ostream& os);
private:
	const std::string test = "Qwinto";
	QwintoRow<Colour::RED> redRow;
	QwintoRow<Colour::YELLOW> yellowRow;
	QwintoRow<Colour::BLUE> blueRow;
	int failedThrows[3] = {0};
	std::vector<Dice> removed_for_roll;		//Used to store dice temporarily
											//for readdition to the
											//RollOfDice after player's turn
};

#endif // _QWINTO_SCORE_SHEET_H
