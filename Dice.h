/*
    Header file for Colour enum, and Dice class
    Author: Anthony Talevi
*/

#include "RandomDice.h"

#ifndef _DICE_H
#define _DICE_H

enum struct Colour {RED, YELLOW, GREEN, BLUE, WHITE};

class Dice{

    Colour c;
    static constexpr int possible_faces[6] = {1,2,3,4,5,6};
    int current_face;

    public:
        Dice(Colour col);
        int roll(RandomDice& rd);
        bool compareCol(Dice d);


    //Needs to overload insertion operator
    //Overload the == operator to replace compareCol
    //and make necessary changes to rest of code
};

#endif // _DICE_H
