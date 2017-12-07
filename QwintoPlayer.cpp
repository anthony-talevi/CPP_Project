#include "QwintoPlayer.h"
#include "Player.h"
#include "RollOfDice.h"
#include "ScoreSheet.h"
#include "QwintoScoreSheet.h"

//Constructor
QwintoPlayer::QwintoPlayer(std::string name): Player(name) {
	ss = new QwintoScoreSheet(name);
};

void QwintoPlayer::inputAfterRoll(RollOfDice& rd) {

	/*
	*	The following block of code asks the users where in the score sheet they
	*	would like to add the rolled score.  Both active and inactive players
	*   behave the same way / perform the same actions after a roll.
	*/

	// Both active and inactive players perform the same actions after the roll
	if(isActive()){
		deactivate();
	}

	//Information needed to add score to scoresheet
	Colour col;
	int pos;

	//Colour input
	while(true){
		std::string row;
		std::cout << "For which colour would you like to score these points? (r/y/b)"
		 	<< std::endl;

		std::cin >> row;

		if(row=="r"){
			col = Colour::RED;
			break;
		}

		else if(row=="y"){
			col = Colour::YELLOW;
			break;
		}

		else if(row=="b"){
			col = Colour::BLUE;
			break;
		}

		else{
			std::cout << "Invalid input." << std::endl;
		}
	}

	//Position input
	while(true){
		std::cout << "In which position would you like to record the score?" << std::endl;
		std::cin >> pos;

		if(ss->score(rd, col, pos-1)){
			std::cout << "Score added to your sheet" << std::endl;
			break;
		}
		else{
			std::cout << "Score could not be added at this position." << std::endl;
		}

	}

	//Put removed dice back in the RollOfDice
	for(Dice d : removed_for_roll){
		rd.add(d);
	}

}

void QwintoPlayer::inputBeforeRoll(RollOfDice& rd) {
	//Print player name
	std::cout << getName() << std::endl;

	if(isActive()){
		std::string yes_or_no;					//Used to store user input

		/*
		*	The following block of code asks the users which dice they Would
		*   Like to use for their turn.  It is a series of yes or no questions,
		*   Looped until a valid input is entered.
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

		//Have no dice been chosen?  If so, recall inputBeforeRoll()
		if(removed_for_roll.size()==3){
			std::cout << "Cannot roll 0 dice.  Try again." << std::endl;
			inputBeforeRoll(rd);
		}
	}

	else{
		std::cout << "Please wait for the other player to finish their turn" << std::endl << std::endl;
	}


}
