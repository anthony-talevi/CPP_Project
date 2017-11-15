/*
    Header file for RandomDice classe
    Author: Anthony Talevi
*/

#include <random>

#ifndef _RANDOM_DICE_H
#define _RANDOM_DICE_H

struct RandomDice{
    static std::mt19937 rand_engine;                  //Random number engine; uses default seed
    static std::uniform_int_distribution<> rand;     //Generates a random number,
    static int generate();
};

#endif // _RANDOM_DICE_H
