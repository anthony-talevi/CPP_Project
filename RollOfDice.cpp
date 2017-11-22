#include "RollOfDice.h"

//Default constructor
RollOfDice::RollOfDice() = default;

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

//Call roll() on all dice in the structure
void RollOfDice::roll(){
    for(auto iter=begin(); iter!=end(); ++iter){
        iter->roll();
    }
}

//Return a RollOfDice containing Dice a an b
RollOfDice RollOfDice::pair(Dice a, Dice b){
    RollOfDice ret;
    for(auto iter=begin(); iter!=end(); ++iter){
        if(*iter.compareCol(a)){
            ret.add(*iter);
            break;
        }
    }
    for(auto iter=begin(); iter!=end(); ++iter){
        if(*iter.compareCol(b)){
            ret.add(*iter);
            break;
        }
    }

    return ret;
}
