#include <iostream>

#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"

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

//this function ensures that each value in each column is unique
bool QwintoScoreSheet::validateColumn(int r, int y, int b, int roll) {
	int rr, yy, bb;
	
	//get the values from the rows and prevent OOB errors by defaulting to -1
	if (r < 0 || r > 9) rr = -1;
	else rr = redRow[r];
	if (y < 0 || y > 9) yy = -1;
	else yy = yellowRow[y];
	if (b < 0 || b > 9) bb = -1;
	else bb = blueRow[b];
	
	//check and make sure none of the columns already contain the roll
	if ((rr == roll && rr > 0) || (yy == roll && yy > 0) || (bb == roll && bb > 0)) return false;
	else return true;
}

//this function will try and play a RollOfDice into the Row "c" at the spot "offset"
//must meet the validation rules of a row (ascending order) and column (unique values)
//returns true if the "rd" was placed, false if it was not
bool QwintoScoreSheet::validate(RollOfDice rd, Colour c, int offset) {
	if (offset < 0 || offset > 9) return false;
	
	bool row, col;

	//switch the colour
	switch (c) {
		//same logic for each colour
		case Colour::RED:
			//check the rules for the row
			row = redRow.validate(offset, rd);
			
			//check the rules for the column
			col = validateColumn(offset, offset+1, offset+2, rd);
			
			//if validation passed insert the roll
			if (row && col) redRow[offset] = rd;
			break;
		case Colour::YELLOW:
			row = yellowRow.validate(offset, rd);
			col = validateColumn(offset-1, offset, offset+1, rd);
			if (row && col) yellowRow[offset] = rd;
			break;
		case Colour::BLUE:
			row = blueRow.validate(offset, rd);
			col = validateColumn(offset-2, offset-1, offset, rd);
			if (row && col) blueRow[offset] = rd;
			break;
		//default return false means we were passed a bad colour
		default:
			return false;
	}

	//return true if we inserted, else false
	if (row && col) return true;
	else return false;
}

bool QwintoScoreSheet::operator!() const {
	//4+ failed attempts for a player and the game is over
	if (failedAttempts > 3) return true;

	//2+ full rows means the game is over
	int sum = 0;
	if (redRow.full()) sum++;
	if (yellowRow.full()) sum++;
	if (blueRow.full()) sum++;

	if (sum > 1) return true;
	std::cout << "fa: " << failedAttempts << "f: " << sum << std::endl;
	return false;
}

std::ostream& QwintoScoreSheet::printSheet(std::ostream& os) const {
	os << "---------------------------------------------";
	os << std::endl;
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
	os << "---------------------------------------------";
	os << std::endl << std::endl;
	return os;
}
