/*
    CPP file for RandomDice
    Author: Anthony Talevi
*/

//Consider making more random by changing the seed.

#include <random>
#include <iostream>

#include "RandomDice.h"

std::random_device RandomDice::rd;
std::mt19937 RandomDice::rand_engine = std::mt19937(rd());
std::uniform_int_distribution<> RandomDice::rand = std::uniform_int_distribution<int>(1,6);

int RandomDice::generate(){
    return rand(rand_engine);
}
