/*
    Header file for Colour enum, and Dice class
    Author: Anthony Talevi
*/

#ifndef _DICE_H
#define _DICE_H

#include "RandomDice.h"
#include <iostream>
#include <string>

enum struct Colour {RED, YELLOW, GREEN, BLUE,
                    WHITE};


class Dice{

    Colour c;
    int current_face = 0;   //Defaults to zero because a 1-6 die cannot be zero,
                            //So this indicates an error to the progammer

    public:
        Dice(Colour col);
        int roll(RandomDice& rd);
        bool compareCol(Dice d);
        friend std::ostream& operator<<(std::ostream&, const Dice&);
        std::string getColour() const;
        int getCurrentFace() const;


    //Overload the == operator to replace compareCol
    //and make necessary changes to rest of code
};

#endif // _DICE_H
