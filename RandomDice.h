/*
    Header file for RandomDice classe
    Author: Anthony Talevi
*/

#include <random>

struct RandomDice{
    static std::default_random_engine rand_engine;        //Random number engine
    static std::uniform_int_distribution<> rand;     //Generates a random number,

};

//Here temporarily while no main function exists in the program.
int main(){
    return 0;
}
