/*
    CPP file for Dice class
    Author: Anthony Talevi
*/

#include "Dice.h"
#include "RandomDice.h"

Dice::Dice(Colour col): c(col){};

//rolls the dice
int Dice::roll(RandomDice& rd){
    current_face = rd.generate();
    return current_face;
}

//Returns true if this and d are the same colour.
bool Dice::compareCol(Dice d){
    if(this->c == d.c){return true;}
    else{return false;}
}

//returns the string value for the colour
std::string Dice::getColour()const{
    switch(c){

        case Colour::RED :
            return "Red";

        case Colour::YELLOW :
            return "Yellow";

        case Colour::GREEN :
            return "Green";

        case Colour::BLUE :
            return "Blue";

        case Colour::WHITE1 :
            return "White 1";
        case Colour::WHITE2 :
            return "White 2";
    }
}

//returns the current face
int Dice::getCurrentFace() const{
    return current_face;
}

//overloads the << operator for printing
std::ostream& operator<<(std::ostream& output, const Dice& d){
	if (d.getCurrentFace() == 0) return output; //empty dice aren't print
	
    output <<  d.getColour() << ": " << d.getCurrentFace() << std::endl;
    return output;
}
