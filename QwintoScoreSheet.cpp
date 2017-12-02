#include <iostream>

#include "QwintoScoreSheet.h"

QwintoScoreSheet::QwintoScoreSheet(std::string name): ScoreSheet(name, 0, 0) {
}

void QwintoScoreSheet::calcTotal() {	
}

bool QwintoScoreSheet::validate(RollOfDice rd, Colour c, int offset) {
	bool ok;
	
	//switch the colour
	switch (c) {
		//same logic for each colour
		case Colour::RED:
			//call the validate function to see if we can insert
			ok = redRow.validate(offset, rd);
			//if we can insert the piece
			if (ok) redRow[offset] = rd;
			break;
		case Colour::YELLOW:
			ok = yellowRow.validate(offset, rd);
			if (ok) yellowRow[offset] = rd;
			break;
		case Colour::BLUE:
			ok = blueRow.validate(offset, rd);
			if (ok) blueRow[offset] = rd;
			break;
		//default return false means we were passed a bad colour
		default:
			return false;
	}
	
	//return true if we inserted, else false
	if (ok) return true;
	else return false;
}

//TODO: replace with overloaded << operator
void QwintoScoreSheet::printSheet(std::ostream& os) {
	os << "Player name: " << playerName << std::endl;
	os << redRow;
	os << yellowRow;
	os << blueRow;

	os << "Failed throws: ";
	for (auto i = 0; i < failedAttempts; i++)
		os << (i+1) << " ";
	
	os << std::endl;
}
