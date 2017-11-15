#include <iostream>

#include "QwintoScoreSheet.h"

QwintoScoreSheet::QwintoScoreSheet(std::string name): ScoreSheet(name, 0, 0) {
}

void QwintoScoreSheet::calcTotal() {
	std::cout << test << std::endl;
}

bool QwintoScoreSheet::validate(RollOfDice rd, Colour c, int offset) {
	return 0;
}
