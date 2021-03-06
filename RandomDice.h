/*
    Header file for RandomDice classe
    Author: Anthony Talevi
*/

#ifndef _RANDOM_DICE_H
#define _RANDOM_DICE_H
#include <random>

#include <random>

struct RandomDice{
    static std::random_device rd;
    static std::mt19937 rand_engine;                  //Random number engine; uses default seed
    static std::uniform_int_distribution<> rand;     //Generates a random number,
    static int generate();
};

#endif // _RANDOM_DICE_H
