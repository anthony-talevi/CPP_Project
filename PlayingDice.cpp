#include <iostream>
#include <string>

#include "ScoreSheet.h"
#include "QwixxScoreSheet.h"
#include "QwintoScoreSheet.h"
#include "Player.h"
#include "QwixxPlayer.h"
#include "QwintoPlayer.h"

int getNumPlayers(){
    int numPlayers;
    while(true){
        std::cout << "How many players will be playing?" << std::endl;
        std::cin >> numPlayers;
        if(numPlayers > 0  && numPlayers < 4){
            return numPlayers;
        }
        else{
            std::cout << "Invalid Input.  Try again." << std::endl;
        }
    }
}

int main() {
    std::cout << "Welcome!  Which version would you like to play?" << std::endl;
    std::cout << "Enter '0' for Qwinto, enter '1' for Qwixx" << std::endl;
    char game;
    int numPlayers;

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
            break;
        }
        else{
            std::cout << "Invalid input.  Try again." << std::endl;
        }
    }

    //Create array of pointers to scoresheets, of size numPlayers
    Player *players [numPlayers];

    //Enter names and create scoresheets for those players
    for(int i=0; i<numPlayers; ++i){
        std::string name;
        std::cout << "Enter the name of Player " << i+1 << ":" << std::endl;
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

    std::cout << "Great! Let's get started!" << std::endl;

    //While not end condition loop
}
