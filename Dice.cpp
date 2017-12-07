/*
    CPP file for Dice class
    Author: Anthony Talevi
*/

#include "Dice.h"
#include "RandomDice.h"

Dice::Dice(Colour col): c(col){};

int Dice::roll(RandomDice& rd){
    current_face = rd.generate();
    return current_face;
}

//Returns true if this and d are the same colour.
bool Dice::compareCol(Dice d){
    if(this->c == d.c){return true;}
    else{return false;}
}

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
            return "White";
        case Colour::WHITE2 :
            return "White";
    }
}

int Dice::getCurrentFace() const{
    return current_face;
}


std::ostream& operator<<(std::ostream& output, const Dice& d){
    output << "Colour: " << d.getColour() << " Face: " << d.current_face << std::endl;
    return output;
}
