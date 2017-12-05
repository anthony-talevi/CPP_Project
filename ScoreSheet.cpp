#include <iostream>

#include "ScoreSheet.h"

ScoreSheet::ScoreSheet(): playerName("default_name"), failedAttempts(0), gameScore(0){};
ScoreSheet::ScoreSheet(std::string n, int f, int s): playerName(n), failedAttempts(f), gameScore(s){};

bool ScoreSheet::score(RollOfDice rd, Colour c, int offset) {
	return validate(rd,c,offset);
}

//user records a failed throw
//returns true when they have more than 3 failed throws
//returns false otherwise
bool ScoreSheet::fail() {
	failedAttempts++;
	
	if (failedAttempts > 3) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os, const ScoreSheet& ss) {
	return ss.printSheet(os);
}

int ScoreSheet::setTotal() {
	calcTotal();
	
	return gameScore;
}
