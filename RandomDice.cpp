/*
    CPP file for RandomDice
    Author: Anthony Talevi
*/

//Consider making more random by changing the seed.
#ifndef RANDDICE
#define RANDDICE

#include<random>
#include "RandomDice.h"
#include <iostream>

std::mt19937 RandomDice::rand_engine = std::mt19937();
std::uniform_int_distribution<> RandomDice::rand = std::uniform_int_distribution<int>(1,6);

int RandomDice::generate(){
    return rand(rand_engine);
}

#endif
