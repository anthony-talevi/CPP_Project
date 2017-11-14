/*
    CPP file for Dice class
    Author: Anthony Talevi
*/

#include <iostream>

#include "Dice.h"
#include "RandomDice.h"

Dice::Dice(Colour col): c(col){};

int Dice::roll(RandomDice& rd){
    for(int i=0; i< 10; ++i){
        std::cout << rd.generate() << std::endl;
    }
}
