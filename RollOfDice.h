#ifndef _ROLL_OF_DICE_H
#define _ROLL_OF_DICE_H
#include "Dice.h"
#include "RandomDice.h"
#include <vector>
#include <iostream>
using std::vector;

class RollOfDice {
	vector<Dice> dice_vec;
	RandomDice rnd;
	int size=0;

	public:
		//Constructor that accepts a RandomDice as arguement
		RollOfDice(RandomDice r);

		//Returns RollOfDice Containing a,b
		RollOfDice pair(Dice a, Dice b);

		//Calls roll() on all dice managed by the object
		void roll();

		//Adds a Dice to the structure
		void add(Dice d);

		//Removes a Dice from the structure
		void rmv(Dice d);

		//Returns a pointer to 1st element in the vector.
		//Used for iterators that modify the structure
		vector<Dice>::iterator begin();

		//Returns a pointer to the position just after last element in the vector
		//Used for iterators that modify the structure
		vector<Dice>::iterator end();

		//Returns a pointer to 1st element in the vector.
		//Used for iterators that do not modify the structure
		vector<Dice>::const_iterator begin() const;

		//Returns a pointer to the position just after last element in the vector
		//Used for iterators that do not modify the structure
		vector<Dice>::const_iterator end() const;

		friend std::ostream& operator<<(std::ostream&, const RollOfDice&);



};

#endif // _ROLL_OF_DICE_H
