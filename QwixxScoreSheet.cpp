#include <iostream>
#include <stdexcept>

#include "ScoreSheet.h"
#include "QwixxScoreSheet.h"

QwixxScoreSheet::QwixxScoreSheet(std::string name): ScoreSheet(name, 0, 0) {}

void QwixxScoreSheet::calcTotal() {
	int score = 0;

	//subtract points for failed attempts
	score -= (failedAttempts * 5);

	//add the scores from the rows
	score += redRow.score();
	score += yellowRow.score();
	score += greenRow.score();
	score += blueRow.score();

	//assign the local variable to the class variable
	gameScore = score;
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
				//if the row was locked we remove the dice from the roll
				if (redRow.lockStatus()) {
					Dice d (Colour::RED);
					rd.rmv(d);
				}
			} catch (std::exception& e) { ok = false; } //if we can't insert an error is thrown
			break;
		case Colour::YELLOW:
			try {
				yellowRow += rd;
				ok = true;
				if (yellowRow.lockStatus()) {
					Dice d (Colour::YELLOW);
					rd.rmv(d);
				}
			} catch (std::exception& e) { ok = false; }
			break;
		case Colour::GREEN:
			try {
				greenRow += rd;
				ok = true;
				if (greenRow.lockStatus()) {
					Dice d (Colour::GREEN);
					rd.rmv(d);
				}
			} catch (std::exception& e) { ok = false; }
			break;
		case Colour::BLUE:
			try {
				blueRow += rd;
				ok = true;
				if (blueRow.lockStatus()) {
					Dice d (Colour::BLUE);
					rd.rmv(d);
				}
			} catch (std::exception& e) { ok = false; }
			break;
		//default return false means we were passed a bad colour
		default:
			return false;
	}
	if (ok) return true;
	else return false;
}

//overloaded not operator
//return true when the scoresheet would cause the game to be over
bool QwixxScoreSheet::operator!() const {
	//4+ failed attempts for a player and the game is over
	if (failedAttempts > 3) return true;

	//2+ locked rows and the game is over
	int numLocked = 0;
	if (redRow.lockStatus()) numLocked++;
	if (yellowRow.lockStatus()) numLocked++;
	if (greenRow.lockStatus()) numLocked++;
	if (blueRow.lockStatus()) numLocked++;

	if (numLocked > 1) return true;
	return false;
}

//prints the scoresheet, works with the overloaded << operator
//of the scoresheet class to behave polymorphically
std::ostream& QwixxScoreSheet::printSheet(std::ostream& os) const {
	os << "---------------------------------------------";
	os << std::endl;
	os << "Player name: " << playerName;

	for (auto i = 22; i > playerName.length(); i--)
		os << " ";
	os << "Points: ";
	if (gameScore < 10) os << " " << gameScore << std::endl;
	else os << gameScore << std::endl;

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
	os << "---------------------------------------------";
	os << std::endl << std::endl;

	return os;
}
