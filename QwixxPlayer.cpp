#include "QwixxPlayer.h"
#include "Player.h"
#include "ScoreSheet.h"
#include "QwixxScoreSheet.h"

//Constructor
QwixxPlayer::QwixxPlayer(std::string name): Player(name) {
	ss = new QwixxScoreSheet(name);
};

void QwixxPlayer::inputAfterRoll(RollOfDice& rd) {

	//Check for failed throw

	//How many scores to record for this turn
	int num_scores;
	while(true){
		if (isActive()) std::cout << "How many scores would you like to record? (0-2) >";
		else std::cout << "How many scores would you like to record (white dice only)? (0-1) >";
		std::cin >> num_scores;

		//Is active player.  Would like to record 2 scores
		if(isActive() && num_scores==2){
			Dice w1 (Colour::WHITE1);
			Dice w2 (Colour::WHITE2);
			RollOfDice whites = rd.pair(w1, w2);

			bool white;
			bool colour;

			//the white dice are always added first
			std::cout << "The white dice will be added to the ScoreSheet first" << std::endl;

			white = twoWhites(whites);
			colour = combine(rd);

			if (white || colour) break;
		}

		//inactive player can skip their turn whenever they want
		else if(!isActive() && num_scores==0){
			break;
		}

		//active player can choose to fail if they want
		else if(isActive() && num_scores==0){
			std::string failInput;
			std::cout << "As the active player, you must record at least 1 score." << std::endl;
			std::cout << "Or you can choose to fail the throw. This counts as a -5pt penalty." << std::endl;
			std::cout << "Would you like to fail the throw? (y/n) >";
			std::cin >> failInput;

			//fail the throw
			if (failInput == "y" || failInput == "Y") {
				ss->fail();
				break;
			}
		}

		//non active player can score the white dice in any colour
		else if(num_scores==1 && !isActive()){
			Dice w1 (Colour::WHITE1);
			Dice w2 (Colour::WHITE2);
			RollOfDice whites = rd.pair(w1, w2);

			if (twoWhites(whites)) break;
		}

		//active player can choose to combine or use the whites
		else if (num_scores == 1 && isActive()) {
			//get choice from user
			std::string choiceInput;
			std::cout << "Would you like to combine a white and a coloured dice, (c)" <<std::endl;
			std::cout << "Or place the two white dice in any colour? (w)" << std::endl;
			std::cin >> choiceInput;

			//combine
			if (choiceInput == "c" || choiceInput == "C") {
				if (combine(rd)) break;
			}
			//whites
			else if (choiceInput == "w" || choiceInput == "W") {
				Dice w1 (Colour::WHITE1);
				Dice w2 (Colour::WHITE2);
				RollOfDice whites = rd.pair(w1, w2);

				if (twoWhites(whites)) break;
			}
			//bad input
			else {
				std::cout << "Invalid input. Try again." <<std::endl;
			}
		}

		//Invalid input
		else{
			std::cout << "Invalid input. Try again." << std::endl;
		}
	}
}

//adds the two white dice to a colour
bool QwixxPlayer::twoWhites(RollOfDice& whites) {
	//get the colour
	Colour col = chooseColour("colour row should the white dice be added to", whites);

	//try to place the white dice
	bool success = ss->score(whites, col);
	if(success) std::cout << "Score successfully added to scoresheet" << std::endl;
	else { //print out error message
		std::cout << "Invalid entry: Score could not be added in this row, at this position." << std::endl;
		std::cout << "Select a different row, or different number of scores.";
		std::cout << std::endl;
	}

	return success;
}

bool QwixxPlayer::combine(RollOfDice& rd) {
	//get the colour
	Colour col = chooseColour("colour row should we combine with", rd);
	int white;
	RollOfDice combined = RollOfDice(rd);

	//find out which white dice to use
	while(true){
		std::cout << "Which white dice would you like to use? (1/2) >";
		std::cin >> white;
		if(white==1){
			combined = rd.pair(Dice(col), Dice(Colour::WHITE1));
			break;
		}
		else if(white==2){
			combined = rd.pair(Dice(col), Dice(Colour::WHITE2));
			break;
		}
		else{
			std::cout << "Invalid input. Try again.";
		}
	}

	//try to place the dice
	bool success = ss->score(combined,col);
	if(success) std::cout << "Score successfully added to scoresheet" << std::endl;
	else { //print out error message
		std::cout << "Invalid entry. Score could not be added in this row, at this position." << std::endl;
		std::cout << "Select a different row, or different number of scores.";
		std::cout << std::endl;
	}

	return success;
}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rd) {
	//function does nothing in qwixx
}

//chooses the colour the player wants to interact with
Colour QwixxPlayer::chooseColour(std::string msg, RollOfDice& rd){
	std::string second_col;
	Colour col;
	//What colour for second score?
	while(true){
		std::cout << "Which " << msg << "? (";
		//Get colours in the RollOfDice
		for(Dice d : rd){
			std::string colour = d.getColour();
			if(colour=="Red"){
				std::cout << "r/";
			}
			else if(colour=="Yellow"){
				std::cout << "y/";
			}
			else if(colour=="Blue"){
				std::cout << "b/";
			}
			else if(colour=="Green"){
				std::cout << "g/";
			}
		}
		std::cout << ")" << std::endl;
		std::cin >> second_col;		//Second colour input

		//Convert input to Colour
		if(second_col.compare("r") == 0){
			col = Colour::RED;
			break;
		}
		else if(second_col.compare("y") == 0){
			col = Colour::YELLOW;
			break;
		}
		else if(second_col.compare("b") == 0){
			col = Colour::BLUE;
			break;
		}
		else if(second_col.compare("g") == 0){
			col = Colour::GREEN;
			break;
		}
		else{
			std::cout << "Invalid input." << std::endl;
		}
	}
	return col;
}
