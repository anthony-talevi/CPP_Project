#include "QwixxPlayer.h"
#include "Player.cpp"
#include "QwixxScoreSheet.cpp"
//Constructor
QwixxPlayer::QwixxPlayer(std::string name): Player(name) {
	ss = new QwixxScoreSheet(name);
};

void QwixxPlayer::inputAfterRoll(RollOfDice& rd) {

	//How many scores to record for this turn
	int num_scores;
	while(true){
		std::cout << "How many scores would you like to record?" << std::endl;
		std::cin >> num_scores;

		//Is active player.  Would like to record 2 scores
		if(isActive() && num_scores==2){
			Colour col = chooseColour();
			Dice c (col);
			Dice w1 (Colour::WHITE1);
			Dice w2 (Colour::WHITE2);

			//Getting the numbers of the current white dice

			RollOfDice whites = rd.pair(w1, w2);	//Getting the white dice from rd
			w1 = whites.rmv(w1);			// Pulling the dice out
			w2 = whites.rmv(w2);

			int face1 = w1.getCurrentFace();	//Getting the faces of the dice
			int face2 = w2.getCurrentFace();
			int white;

			// Which white die does the user want to use?
			// Also adds score to scoresheet
			while(true){
				std::cout << "Which white dice would you like to use? (" << face1 << "/"
				 	<< face2 << ")"<< std::endl;
				std::cin >> white;

				if(white==face1){
					RollOfDice forscore = rd.pair(c, w1);
					choosePosition(forscore, col);
					break;
				}
				else if(white==face2){
					RollOfDice forscore = rd.pair(c, w2);
					choosePosition(forscore, col);
					break;
				}
				else{
					std::cout << "Invalid Input" << std::endl;
				}
			}
			break;
		}

		//Is not active player and would like to record 0 scores.
		else if(!isActive() && num_scores==0){
			break;
		}

		//Would like to record 1 score.  All players can do this, and this looks
		//the same for both active and inactive players.
		// Active always has to score white dice.
		else if(num_scores==1 || isActive()){
			Dice w1 (Colour::WHITE1);
			Dice w2 (Colour::WHITE2);
			RollOfDice whites = rd.pair(w1, w2);
			int pos;

			Colour col = chooseColour();

			//Get position from user and add score to scoresheet.
			choosePosition(whites, col);
			break;
		}

		//Invalid input
		else{
			std::cout << "Invalid input.  Try again." << std::endl;
		}
	}
}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rd) {
	if(isActive()){
		std::string yes_or_no;					//Used to store user input

		/*
		*	The following block of code asks the users which dice they Would
		*   Like to use for their turn.  It is a series of yes or no questions,
		*   Looped until a valid input is entered.
		*   Essentially the same as QwintoPlayer only extended
		*/

		//Red Die

		while(true){
			std::cout << "Would you like to roll the red die? (y/n)" << std::endl;
			std::cin >> yes_or_no;
			if(yes_or_no=="n"||yes_or_no=="N"){
				Dice d (Colour::RED);
				removed_for_roll.push_back(rd.rmv(d));	//Add a Red die to temp vector
				break;									//Remove from the rollable dice
			}
			else if(yes_or_no=="y"||yes_or_no=="Y"){
				break;		//Leave die in vector
			}
			else{
				std::cout << "Invalid input" << std::endl;
			}
		}

		//Yellow Die
		while(true){
			std::cout << "Would you like to roll the yellow die? (y/n)" << std::endl;
			std::cin >> yes_or_no;
			if(yes_or_no=="n"||yes_or_no=="N"){
				Dice d (Colour::YELLOW);
				removed_for_roll.push_back(rd.rmv(d));	//Add a Blue die to temp vector
				break;							//Remove from the rollable dice
			}
			else if(yes_or_no=="y"||yes_or_no=="Y"){
				break;		//Leave die in vector
			}
			else{
				std::cout << "Invalid input" << std::endl;
			}
		}

		//Blue Die

		while(true){
			std::cout << "Would you like to roll the blue die? (y/n)" << std::endl;
			std::cin >> yes_or_no;
			if(yes_or_no=="n"||yes_or_no=="N"){
				Dice d (Colour::BLUE);
				removed_for_roll.push_back(rd.rmv(d));	//Add a Blue die to temp vector
				break;									//Remove from the rollable dice
			}
			else if(yes_or_no=="y"||yes_or_no=="Y"){
				break;		//Leave die in vector
			}
			else{
				std::cout << "Invalid input" << std::endl;
			}
		}

		//Green Die

		while(true){
			std::cout << "Would you like to roll the green die? (y/n)" << std::endl;
			std::cin >> yes_or_no;
			if(yes_or_no=="n"||yes_or_no=="N"){
				Dice d (Colour::GREEN);
				removed_for_roll.push_back(rd.rmv(d));	//Add a Blue die to temp vector
				break;									//Remove from the rollable dice
			}
			else if(yes_or_no=="y"||yes_or_no=="Y"){
				break;		//Leave die in vector
			}
			else{
				std::cout << "Invalid input" << std::endl;
			}
		}

		//Have no dice been chosen?  If so, recall inputBeforeRoll()
		if(removed_for_roll.size()==3){
			std::cout << "Cannot roll 0 dice.  Try again." << std::endl;
			inputBeforeRoll(rd);
		}
	}

	else{
		std::cout << "Please wait for the other player to finish their turn" << std::endl;
	}

}

int QwixxPlayer::choosePosition(RollOfDice rd, Colour col){
	// User selects position and score is added to the scoresheet
	while(true){
		int pos;
		std::cout << "In which position would you like to record the score?" << std::endl;
		std::cin >> pos;

		if(ss->score(rd, col, pos)){
			std::cout << "Score added to your sheet";
			break;
		}
		else{
			std::cout << "Score could not be added at this position.";
		}
	}

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
