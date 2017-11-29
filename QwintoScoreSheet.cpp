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

void QwintoScoreSheet::printSheet(std::ostream& os) {
	redRow.printRow(os);
	yellowRow.printRow(os);
	blueRow.printRow(os);
	
	os << "Failed throws: ";
	printZero(os, failedThrows[0]);
	printZero(os, failedThrows[1]);
	printZero(os, failedThrows[2]);
	os << std::endl;
}
