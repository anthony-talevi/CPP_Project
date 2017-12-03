#ifndef _QWINTO_ROW_H
#define _QWINTO_ROW_H

#include <iostream>
#include <string>

#include "Dice.h"

template <Colour C> class QwintoRow {
public:
	//constructor
	QwintoRow() {
		// block columns
		switch (C) {
			case Colour::RED:
				column[3] = -1;
				break;
			case Colour::YELLOW:
				column[5] = -1;
				break;
			case Colour::BLUE:
				column[4] = -1;
				break;
		}
	}
	~QwintoRow(){}
	
	//overloads the subscript operator to access column
	int& operator[](const int pos) {
		return column[pos];
	}
	
	//validates that it is ok to place 'id' in position 'position'
	bool validate(int position, int id) {
		//make sure the spot isn't already taken
		if (column[position] != 0) {
			return false;
		}
		
		//check for the same number & if there is a smaller number after
		for (int i = 0; i < 10; i++) {
			//first half checks for the same number
			//second half checks that there are no non-zero numbers after the postion
			if (column[i] == id || (i > position && column[i] < id && column[i] > 0)) {
				return false;
			}
		}
		
		//all tests passed
		return true;
	}
	
	//determines the score for the row
	int score() {
		int num = 0;
		
		//count the number of entries
		for (int i = 0; i < 10; i++) {
			if (column[i] > 0)
				num++;
		}
		
		//return the row score
		if (num == 9) return column[9];
		else return num;
	}

	//allows for outputing via overloading the the insertion operator
	friend std::ostream& operator<<(std::ostream& os, const QwintoRow& qr) {
		int h;
		char colText[3][11] = {
			{'|','%','%','|','|','%','%','|','|','|','|'},
			{'|','|','|','|','|','|','|','%','%','|','|'},
			{'|','|','%','%','|','|','|','|','|','%','%'},
		};
		
		//apply colour specific changes
		switch (C) {
			case Colour::RED:
				os << "              -------------------------------" << std::endl; //row top
				os << "Red           "; //row starter
				h = 0; //array index helper
				break;
			case Colour::YELLOW:
				os << "           ----------------------------------" << std::endl;
				os << "Yellow     ";
				h = 1;
				break;
			case Colour::BLUE:
				os << "        ----------------------------------" << std::endl;
				os << "Blue    ";
				h = 2;
				break;
		}
		
		//draw the row
		for (auto i = 0 ; i < 10; i++) {
			os << colText[h][i] << twoSpaces(qr.column[i]);
		}
		os << colText[h][10] << std::endl; //finish off the row
		
		//add bottom topper for BLUE row
		switch(C) {
			case Colour::BLUE:
				os << "        -------------------------------" << std::endl;
				break;
		}
		
		return os;
	}
	
private:
	//values are stored in an array of ints
	int column[10] = {0};
	
	//helper function to output spaces when needed
	static std::string twoSpaces(const int n) {
		//handle special cases
		if (n == -1)
			return "XX";
		if  (n == 0)
			return "  ";
		
		//build string to return
		std::string retVal = "";
		
		if (n < 10) retVal += " ";
		retVal += std::to_string(n);
		
		return retVal;
	}
};

#endif //_QWINTO_ROW_H
