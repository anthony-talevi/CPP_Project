#include <iostream>

#include "QwintoScoreSheet.h"

QwintoScoreSheet::QwintoScoreSheet(std::string name): ScoreSheet(name, 0, 0) {
}

void QwintoScoreSheet::calcTotal() {
	int score = 0;
	
	//take away for failed attempts
	score -= (failedAttempts * 5);
	
	//calculate row totals
	score += redRow.score();
	score += yellowRow.score();
	score += blueRow.score();
	
	//calculate bonus totals
	if (redRow[0] > 0 && yellowRow[1] > 0 && blueRow[2] > 0) //b1 = r1,y2,b3
	score += blueRow[2];
	if (redRow[1] > 0 && yellowRow[2] > 0 && blueRow[3] > 0) //b2 = r2,y3,b4
	score += redRow[2];
	if (redRow[4] > 0 && yellowRow[6] > 0 && blueRow[7] > 0) //b3 = r5,y7,b8
	score += redRow[4];
	if (redRow[5] > 0 && yellowRow[7] > 0 && blueRow[8] > 0) //b4 = r6,y8,b9
	score += yellowRow[7];
	if (redRow[6] > 0 && yellowRow[8] > 0 && blueRow[9] > 0) //b5 = r7,y9,b10
	score += blueRow[9];
	
	//assign value of local variable to class variable
	gameScore = score;	
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
	os << "Player name: " << playerName;
	
	for (auto i = 22; i > playerName.length(); i--)
		os << " ";
	os << "Points: ";
	if (gameScore < 10) os << " " << gameScore << std::endl;
	else os << gameScore << std::endl;
	
	os << redRow;
	os << yellowRow;
	os << blueRow;

	os << "Failed throws: ";
	for (auto i = 0; i < failedAttempts; i++)
		os << (i+1) << " ";
	
	os << std::endl;
}
