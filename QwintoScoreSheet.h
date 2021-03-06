#ifndef _QWINTO_SCORE_SHEET_H
#define _QWINTO_SCORE_SHEET_H

#include "ScoreSheet.h"
#include "Dice.h"
#include "QwintoRow.cpp"

class QwintoScoreSheet:public ScoreSheet {
public:
	QwintoScoreSheet(std::string name);
	bool operator!() const;
protected:
	bool validate(RollOfDice rd, Colour c, int offset);
	void calcTotal();
	std::ostream& printSheet(std::ostream& os) const;
private:
	QwintoRow<Colour::RED> redRow;
	QwintoRow<Colour::YELLOW> yellowRow;
	QwintoRow<Colour::BLUE> blueRow;
	std::vector<Dice> removed_for_roll;		//Used to store dice temporarily for readdition to the RollOfDice after player's turn
	bool validateColumn(int r, int y, int b, int roll);
};

#endif // _QWINTO_SCORE_SHEET_H
