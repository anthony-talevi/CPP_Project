/*
    Header file for Colour enum, and Dice class
    Author: Anthony Talevi
*/

#include <random>
#include <string>

enum struct Colour {RED, YELLOW, GREEN, BLUE, WHITE};

class Dice{
    const Colour c;
    static constexpr int possible_faces[6] = {1,2,3,4,5,6};
    int current_face;

    Dice(Colour col);
    int roll();

    //Needs to overload insertion operator
};
