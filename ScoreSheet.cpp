#include "ScoreSheet.h"

ScoreSheet::ScoreSheet(): playerName("test"), failedAttempts(0), gameScore(0){};
ScoreSheet::ScoreSheet(std::string n, int f, int s): playerName(n), failedAttempts(f), gameScore(s){};

bool ScoreSheet::score(RollOfDice rd, Colour c, int offset) {
	validate(rd,c,offset);
}

int ScoreSheet::setTotal() {
	calcTotal();
}
