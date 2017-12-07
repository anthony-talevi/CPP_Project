#include <iostream>
#include <string>

#include "ScoreSheet.h"
#include "QwixxScoreSheet.h"
#include "QwintoScoreSheet.h"
#include "Player.h"
#include "QwixxPlayer.h"
#include "QwintoPlayer.h"
#include "RandomDice.h"
#include "RollOfDice.h"

int getNumPlayers(){
    int numPlayers;
    while(true){
        std::cout << "How many players will be playing?  ";
        std::cin >> numPlayers;
        if(numPlayers > 0  && numPlayers < 4){
            return numPlayers;
        }
        else{
            std::cout << "Invalid Input.  Try again." << std::endl;
        }
    }
}

//determines whether the game is over
//returns true when game is over
bool gameStatus(Player* players[], int size) {
	//loop over all players
	for (int i = 0; i < size; i++) {
		if (!players[i]->ss) //use the ! opeator of the ss
			return true;
	}

	return false;
}

//helper function that tries to clear the screen a bit so we can see what is going on
void clearConsole() {
	for (int i = 0; i < 5; i++) {
		std::cout << std::endl;
	}
}

int main() {
    std::cout << "Welcome!  Which version would you like to play?" << std::endl;
    std::cout << "Enter '0' for Qwinto, enter '1' for Qwixx" << std::endl;
    char game;
    int numPlayers;

    //Initializing RollOfDice
    RandomDice rd;
    RollOfDice rod = RollOfDice(rd);
    Dice r (Dice(Colour::RED));
    Dice y (Dice(Colour::YELLOW));
    Dice b (Dice(Colour::BLUE));

    rod.add(r);
    rod.add(y);
    rod.add(b);

    //active player holds the index of the active player
    int activePlayer = 0;
    //turn count is the turn, is also used to determine the active player with
    //the equation activePlayer = turnCount % numPlayers
    int turnCount = 0;

    //Select type of game.
    //Also creates
    while(true){
        std::cin >> game;

        if(game=='0'){
            std::cout << "Qwinto Selected" << std::endl;
            numPlayers = getNumPlayers();
            break;
        }
        else if(game=='1'){
            std::cout << "Qwixx Selected" << std::endl;
            numPlayers = getNumPlayers();
            Dice w1 (Dice(Colour::WHITE1));
            Dice w2 (Dice(Colour::WHITE2));
            Dice g (Dice(Colour::GREEN));
            rod.add(w1);
            rod.add(w2);
            rod.add(g);
            break;
        }
        else{
            std::cout << "Invalid input.  Try again." << std::endl;
        }
    }

    //Create array of pointers to scoresheets, of size numPlayers
    Player *players [numPlayers];
    int scores[numPlayers];

    //Enter names and create scoresheets for those players
    for(int i=0; i<numPlayers; ++i){
        std::string name;
        std::cout << "Enter the name of Player #" << i+1 << ": ";
        std::cin >> name;
        if(game=='0'){
            players[i] = new QwintoPlayer(name);
        }
        //Validity of game was already checked, so no sense in wasting resources
        //Checking for equality to 1.  If it isn't 0, it must be 1
        else{
            players[i] = new QwixxPlayer(name);
        }
    }

	clearConsole();
    std::cout << "Great! Let's get started!" << std::endl;

    //TODO: create roll of dice

    /* main loop pseudocode -- x indicates complete

    x	while end condition is not reached
	x		next player takes a turn i.e., becomes active
			get input from active player before roll
			roll dice and show result
	x		print scoresheet of active player
			get input from active player after roll
			score dice according to input from active player
	x		loop over all non-active players
	x			print scoresheet of non-active player
				get input from non-active player
				score dice according to input
	x	loop over all players
	x		calculate points for player
	x		print scoresheet
	x	print overall winner
    */

    //main loop
    while (!gameStatus(players, numPlayers)) {
    	//determine the next active player
    	activePlayer = turnCount % numPlayers;
    	//set player to active
    	players[activePlayer]->activate();

    	//show turn data to players
    	std::cout << "Beginning turn #" << (turnCount+1) << std::endl;
    	std::cout << players[activePlayer]->getName() << "'s turn" << std::endl << std::endl;

    	//active player specific code
    	std::cout << *players[activePlayer] -> ss;
    	players[activePlayer]->inputBeforeRoll(rod);

		//roll the dice
        rod.roll();
        
        //reprint active player scoresheet & show dice
        std::cout << *players[activePlayer]->ss;
        std::cout << rod;

        //get active player's after roll input
        players[activePlayer]->inputAfterRoll(rod);

        for(int i=0; i < numPlayers; ++i) {
        	if (players[i]->isActive()) continue;
        	//inactive players get their turns
			std::cout << *players[i]->ss; //show ss
            std::cout << rod; //reshow rod
			players[i]->inputAfterRoll(rod);
        }


    	//deactivate player
    	players[activePlayer]->deactivate();
    	turnCount++; //increment turn count

    	if (turnCount > 5) break;
	}

	//print out scoresheets
	for (int i = 0; i < numPlayers; i++) {
		//calculate final scores
		scores[i] = players[i]->ss->setTotal();

		//output scoresheets
		std::cout << *players[i]->ss;
	}

	//output winner
	int largest = 0;
	for (int i = 0; i < numPlayers; i++) {
		if (scores[i] > scores[largest]) largest = i;
	}

	std::cout << std::endl << std::endl << players[largest]->getName() << " is the winner!" << std::endl;
}
