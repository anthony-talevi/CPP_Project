#ifndef _ROLL_OF_DICE_H
#define _ROLL_OF_DICE_H
#include "Dice.h"
#include <vector>
using std::vector;

class RollOfDice {
	vector<Dice> dice_vec;
	int size=0;

	vector<Dice>::iterator begin();						//Returns a pointer to 1st element
	vector<Dice>::iterator end();						//Returns a pointer to last element

	public:
		RollOfDice();						//Constructor
		RollOfDice pair(Dice a, Dice b);	//Returns RollOfDice Containing a,b
		void roll();						//calls roll() on all dice in self
		void add(Dice d);					//Adds a Dice to the structure
		void rmv(Dice d);					//Removes a Dice from the structure

};

#endif // _ROLL_OF_DICE_H
