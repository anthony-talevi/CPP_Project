#include <iostream>

#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(std::string name): ScoreSheet(name, 0, 0) {}

void QwixxScoreSheet::calcTotal() {
	std::cout << test << std::endl;
}

bool QwixxScoreSheet::validate(RollOfDice rd, Colour c, int offset) {
	return 0;
}

void QwixxScoreSheet::printSheet(std::ostream& os) {
	
}
