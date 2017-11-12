/*
    CPP file for RandomDice
    Author: Anthony Talevi
*/

#include<random>
#include "RandomDice.h"

std::uniform_int_distribution<> RandomDice::rand = std::uniform_int_distribution<int>(1,6);
