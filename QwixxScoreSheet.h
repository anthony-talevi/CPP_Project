#ifndef _QWIXX_SCORE_SHEET_H
#define _QWIXX_SCORE_SHEET_H

#include <vector>
#include <list>

#include "ScoreSheet.h"
#include "Dice.h"
#include "QwixxRow.cpp"

class QwixxScoreSheet:public ScoreSheet {
public:
	QwixxScoreSheet(std::string name);
	bool operator!() const;
protected:
	bool validate(RollOfDice rd, Colour c, int offset);
	void calcTotal();
	std::ostream& printSheet(std::ostream& os) const;
private:
	QwixxRow<std::vector<int>, Colour::RED> redRow;
	QwixxRow<std::vector<int>, Colour::YELLOW> yellowRow;
	QwixxRow<std::list<int>, Colour::GREEN> greenRow;
	QwixxRow<std::list<int>, Colour::BLUE> blueRow;
};

#endif // _QWIXX_SCORE_SHEET_H
