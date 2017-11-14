/*
    CPP file for Dice class
    Author: Anthony Talevi
*/
#ifndef DICE
#define DICE

#include "Dice.h"
#include <iostream>
Dice::Dice(Colour col): c(col){};

int Dice::roll(RandomDice& rd){
    for(int i=0; i< 10; ++i){
        std::cout << rd.generate() << std::endl;
    }
}

#endif
