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
		else std::cout << "How many scores would you like to record? (0-1) >";
		std::cin >> num_scores;

		//Is active player.  Would like to record 2 scores
		if(isActive() && num_scores==2){
			Colour col = chooseColour();
			Dice c (col);
			Dice w1 (Colour::WHITE1);
			Dice w2 (Colour::WHITE2);
			bool success;

			int white;

			// Which white die does the user want to use?
			// Also adds score to scoresheet

			//Initialized only because no default constructor.  Never used in
			//This state,
			RollOfDice forscore = RollOfDice(rd);
			while(true){
				std::cout << "Which white dice would you like to use? (1/2) >";
				std::cin >> white;
				if(white==1){
					forscore = rd.pair(c, w1);
					break;
				}
				else if(white==2){
					forscore = rd.pair(c, w2);
					break;
				}
				else{
					std::cout << "Invalid input.  Try again.";
				}
			}
			//Check if that white die can be used.
			int pos = forscore;
			success = ss->score(forscore, col, pos);
			if(success){
				std::cout << "Score successfully added to scoresheet";
				std::cout << std::endl;
				break;
			}
			else{
				std::cout << "Invlaid entry.  Score could not be added in this row, at this position.";
				std::cout << "  Select a different row, different white die, or different number of scores.";
				std::cout << std::endl;
			}
		}

		else if(!isActive() && num_scores==2){
			std::cout << "You are not the active player. You can record at most 1 score." << std::endl;
		}

		//Is not active player and would like to record 0 scores.
		else if(!isActive() && num_scores==0){
			break;
		}

		else if(isActive() && num_scores==0){
			std::string failInput;
			std::cout << "As the active player, you must record at least 1 score." << std::endl;
			std::cout << "Or you can choose to fail the throw. This counts as a -5pt penalty." << std::endl;
			std::cout << "Would you like to fail the throw? (y/n) >";
			std::cin >> failInput;
			
			if (failInput == "y" || failInput == "Y") {
				ss->fail();
				break;
			}
		}

		//Would like to record 1 score.  All players can do this, and this looks
		//the same for both active and inactive players.
		// Active always has to score white dice.
		else if(num_scores==1 || isActive()){
			Dice w1 (Colour::WHITE1);
			Dice w2 (Colour::WHITE2);
			RollOfDice whites = rd.pair(w1, w2);
			int pos = whites;

			Colour col = chooseColour();
			bool success = ss -> score(whites, col, pos);
			if(success){
				std::cout << "Score successfully added to scoresheet" << std::endl;
				break;
			}
			else{
				std::cout << "Invalid entry.  Score could not be added in this row, at this position.";
				std::cout << "  Select a different row, or different number of scores.";
				std::cout << std::endl;
			}
		}

		//Invalid input
		else{
			std::cout << "Invalid input.  Try again." << std::endl;
		}
	}
}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rd) {
	//Print player name
	// std::cout << getName() << std::endl;
	//
	// if(isActive()){
	// 	std::string yes_or_no;					//Used to store user input
	//
	// 	/*
	// 	*	The following block of code asks the users which dice they Would
	// 	*   Like to use for their turn.  It is a series of yes or no questions,
	// 	*   Looped until a valid input is entered.
	// 	*   Essentially the same as QwintoPlayer only extended
	// 	*/
	//
	// 	//Red Die
	//
	// 	while(true){
	// 		std::cout << "Would you like to roll the red die? (y/n)" << std::endl;
	// 		std::cin >> yes_or_no;
	// 		if(yes_or_no=="n"||yes_or_no=="N"){
	// 			Dice d (Colour::RED);
	// 			removed_for_roll.push_back(rd.rmv(d));	//Add a Red die to temp vector
	// 			break;									//Remove from the rollable dice
	// 		}
	// 		else if(yes_or_no=="y"||yes_or_no=="Y"){
	// 			break;		//Leave die in vector
	// 		}
	// 		else{
	// 			std::cout << "Invalid input" << std::endl;
	// 		}
	// 	}
	//
	// 	//Yellow Die
	// 	while(true){
	// 		std::cout << "Would you like to roll the yellow die? (y/n)" << std::endl;
	// 		std::cin >> yes_or_no;
	// 		if(yes_or_no=="n"||yes_or_no=="N"){
	// 			Dice d (Colour::YELLOW);
	// 			removed_for_roll.push_back(rd.rmv(d));	//Add a Blue die to temp vector
	// 			break;							//Remove from the rollable dice
	// 		}
	// 		else if(yes_or_no=="y"||yes_or_no=="Y"){
	// 			break;		//Leave die in vector
	// 		}
	// 		else{
	// 			std::cout << "Invalid input" << std::endl;
	// 		}
	// 	}
	//
	// 	//Blue Die
	//
	// 	while(true){
	// 		std::cout << "Would you like to roll the blue die? (y/n)" << std::endl;
	// 		std::cin >> yes_or_no;
	// 		if(yes_or_no=="n"||yes_or_no=="N"){
	// 			Dice d (Colour::BLUE);
	// 			removed_for_roll.push_back(rd.rmv(d));	//Add a Blue die to temp vector
	// 			break;									//Remove from the rollable dice
	// 		}
	// 		else if(yes_or_no=="y"||yes_or_no=="Y"){
	// 			break;		//Leave die in vector
	// 		}
	// 		else{
	// 			std::cout << "Invalid input" << std::endl;
	// 		}
	// 	}
	//
	// 	//Green Die
	//
	// 	while(true){
	// 		std::cout << "Would you like to roll the green die? (y/n)" << std::endl;
	// 		std::cin >> yes_or_no;
	// 		if(yes_or_no=="n"||yes_or_no=="N"){
	// 			Dice d (Colour::GREEN);
	// 			removed_for_roll.push_back(rd.rmv(d));	//Add a Blue die to temp vector
	// 			break;									//Remove from the rollable dice
	// 		}
	// 		else if(yes_or_no=="y"||yes_or_no=="Y"){
	// 			break;		//Leave die in vector
	// 		}
	// 		else{
	// 			std::cout << "Invalid input" << std::endl;
	// 		}
	// 	}
	//
	// 	//Have no dice been chosen?  If so, recall inputBeforeRoll()
	// 	if(removed_for_roll.size()==3){
	// 		std::cout << "Cannot roll 0 dice.  Try again." << std::endl;
	// 		inputBeforeRoll(rd);
	// 	}
	// }
	//
	// else{
	// 	std::cout << "Please wait for the other player to finish their turn" << std::endl;
	// }

}



Colour QwixxPlayer::chooseColour(){
	std::string second_col;
	Colour col;
	//What colour for second score?
	while(true){
		std::cout << "Which colour dice would you like to use for your second score? (r/y/b/g)" << std::endl;

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
