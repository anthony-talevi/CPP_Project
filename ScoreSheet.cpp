#include "ScoreSheet.h"

ScoreSheet::ScoreSheet(): playerName("test"), failedAttempts(0), gameScore(0){};
ScoreSheet::ScoreSheet(std::string n, int f, int s): playerName(n), failedAttempts(f), gameScore(s){};

bool ScoreSheet::score(RollOfDice rd, Colour c, int offset) {
	validate(rd,c,offset);
	
	return false;
}

int ScoreSheet::setTotal() {
	calcTotal();
	
	return 0;
}

void ScoreSheet::printZero(std::ostream& s, int n) {
	if (n == 0) {
		s << " ";
	} else {
		s << n << "";
	}
}

void ScoreSheet::print(std::ostream& os) {
	printSheet(os);
}