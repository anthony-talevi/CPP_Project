#include <iostream>
#include <stdexcept>

#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(std::string name): ScoreSheet(name, 0, 0) {}

void QwixxScoreSheet::calcTotal() {
}

bool QwixxScoreSheet::validate(RollOfDice rd, Colour c, int offset) {
	bool ok;
	
	//switch the colour
	switch (c) {
		//same logic for each colour
		case Colour::RED:
			try {
				//add the RollOfDice to the row
				redRow += rd;
				//set ok to true
				ok = true;
			} catch (std::exception& e) { ok = false; } //if we can't insert an error is thrown
			break;
		case Colour::YELLOW:
			try {
				yellowRow += rd;
				ok = true;
			} catch (std::exception& e) { ok = false; }
			break;
		case Colour::GREEN:
			try {
				greenRow += rd;
				ok = true;
			} catch (std::exception& e) { ok = false; }
			break;
		case Colour::BLUE:
			try {
				blueRow += rd;
				ok = true;
			} catch (std::exception& e) { ok = false; }
			break;
		//default return false means we were passed a bad colour
		default:
			return false;
	}
	if (ok) return true;
	else return false;
}

//TODO: replace with overloaded << operator
void QwixxScoreSheet::printSheet(std::ostream& os) {
	os << "Player name: " << playerName << std::endl;
	os << "         ------------------------------------" << std::endl;
	os << redRow;
	os << "         ------------------------------------" << std::endl;
	os << yellowRow;
	os << "         ------------------------------------" << std::endl;
	os << greenRow;
	os << "         ------------------------------------" << std::endl;
	os << blueRow;
	os << "         ------------------------------------" << std::endl;
	
	os << "Failed throws: ";
	for (auto i = 0; i < failedAttempts; i++)
		os << (i+1) << " ";
	
	os << std::endl;
}
