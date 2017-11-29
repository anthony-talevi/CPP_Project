#include <iostream>

#include "ScoreSheet.h"
#include "QwixxScoreSheet.h"
#include "QwintoScoreSheet.h"
#include "Player.h"
#include "QwixxPlayer.h"
#include "QwintoPlayer.h"

/*int main() {
    std::cout << "Welcome!  Which version would you like to play?" << std::endl;
    std::cout << "Enter '0' for Qwinto, enter '1' for Qwixx" << std::endl;
    char game;
    
    ScoreSheet* ss;
    
    while(true){
        std::cin >> game;

        if(game=='0'){
            //std::cout << "Qwinto Selected" << std::endl;
            ss = new QwintoScoreSheet("Connor");
            break;
        }
        else if(game=='1'){
            //std::cout << "Qwixx Selected" << std::endl;
            ss = new QwixxScoreSheet("Connor");
            break;
        }
        else{
            std::cout << "Invalid input.  Try again." << std::endl;
        }
    }
    
    ss->setTotal();
	ss->print(std::cout);
}*/
