/*
    Class: RollOfDice
    Author: Anthony Talevi
    Description: RollOfDice CPP file.

*/

#include "RollOfDice.h"
#include "Dice.cpp"

//Constructor
//Accepts a RandomDice Object that will be used for rolls.
RollOfDice::RollOfDice(RandomDice r): rnd(r) {}

//Add a die to the set
void RollOfDice::add(Dice d){
    dice_vec.push_back(d);
    ++size;
}

//Remove a die from the set.
void RollOfDice::rmv(Dice d){
    for(auto iter = begin(); iter != end(); ++iter){
        if(iter->compareCol(d)){
            dice_vec.erase(iter);
            --size;
            return;
        }
    }
}
//Return an iterator for RollOfDice
vector<Dice>::iterator RollOfDice::begin(){
    return dice_vec.begin();
}
//Return an iterator for RollOfDice
vector<Dice>::iterator RollOfDice::end(){
    return dice_vec.end();
}

//Return a const iterator for RollOfDice
vector<Dice>::const_iterator RollOfDice::begin() const{
    return dice_vec.begin();
}
//Return a const iterator for RollOfDice
vector<Dice>::const_iterator RollOfDice::end() const{
    return dice_vec.end();
}


//Call roll() on all dice in the structure
void RollOfDice::roll(){
    for(int i=0; i<size; ++i){
        dice_vec[i].roll(rnd);
    }
}

//Return a RollOfDice containing Dice a an b
RollOfDice RollOfDice::pair(Dice a, Dice b){
    RollOfDice ret(this->rnd);
    for(Dice d : *this){
        if(d.compareCol(a)){
            ret.add(d);
            break;
        }
    }
    for(Dice d : *this){
        if(d.compareCol(b)){
            ret.add(d);
            break;
        }
    }

    return ret;
}

//Overloaded << operator
std::ostream& operator<<(std::ostream& output, const RollOfDice& rod){
    for(Dice d : rod){
        output << d << std::endl;
    }
    return output;
}
