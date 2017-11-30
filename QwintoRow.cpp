<<<<<<< HEAD
/*
*   Author: Anthony Talevi
*   
*/
#include "QwintoRow.h"

template<Colour C>
QwintoRow<C>::QwintoRow(): col(C), points{0,0,0,0,0,0,0,0,0,0}{}


//Validate function for RED row.
template<>
bool QwintoRow<Colour::RED>::validate(int index, RollOfDice rd){
    //Has this position already been given a value?
    if(points[index]!=0) return false;

    //If the position is not the invalid position
    if(index!=3){

        //Nothing to compare with
        if(index==0) return true;

        //For the condition index = 4, index-1 would be invalid position, so
        //must compare with index -2
        else if(index==4) return points[index-2] < rd;

        //Check for strict increase in the row
        else return points[index-1] < rd;
    }
    return false;
}

//Validate function for YELLOW row.
template<>
bool QwintoRow<Colour::YELLOW>::validate(int index, RollOfDice rd){
    //Has this position already been given a value?
    if(points[index]!=0) return false;

    //If the position is not the invalid position
    if(index!=5){

        //Nothing to compare with
        if(index==0) return true;

        //For the condition index = 4, index-1 would be invalid position, so
        //must compare with index -2
        else if(index==6) return points[index-2] < rd;

        //Check for strict increase in the row
        else return points[index-1] < rd;
    }
    return false;
}

//Validate function for BLUE row.
template<>
bool QwintoRow<Colour::BLUE>::validate(int index, RollOfDice rd){
    //Has this position already been given a value?
    if(points[index]!=0) return false;

    //If the position is not the invalid position
    if(index!=4){

        //Nothing to compare with
        if(index==0) return true;

        //For the condition index = 4, index-1 would be invalid position, so
        //must compare with index -2
        else if(index==5) return points[index-2] < rd;

        //Check for strict increase in the row
        else return points[index-1] < rd;
    }
    return false;
}

//Overloaded [] operator
//Returns the index in the points array if it is valid to add the result of a
//Dice roll there.   Else returns the null pointer
template <Colour C>
int& QwintoRow<C>::operator[](int index){
    return points[index];
}

//Const version of the overloaded [] operator
template <Colour C>
const int& QwintoRow<C>::operator[](int index) const{
    return points[index];
}


//Overloaded insertion operator for Colour RED
template<>
std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::RED>& qr){
    os << "Red" << "             |";
    for(int i=0; i<10; ++i){

        //Invalid column
        if(i==3){
            os << "XX";
        }
        //Empty field
        else if(qr[i]==0) os << "  ";

        //Insert point value
        else {
            //If qr[i] is single digit, it will require an extra space
            if(qr[i] < 10) os << " ";
            os << qr[i];
        }

        //Bonus entries that require %
        if(i==0 || i==1 || i==4 || i==5){
            os << "%";
        }
        else os <<"|";

    }
    os << std::endl;

    return os;
}

//Overloaded insertion operator for Colour YELLOW
template<>
std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::YELLOW>& qr){
    os << "Yellow" << "       |";
    for(int i=0; i<10; ++i){

        //Invalid column
        if(i==5){
            os << "XX";
        }

        //Empty field
        else if(qr[i]==0) os << "  ";

        //Insert point value
        else {
            //If qr[i] is single digit, it will require an extra space
            if(qr[i] < 10) os << " ";
            os << qr[i];
        }

        //Bonus entries that require %
        if(i==6 || i==7){
            os << "%";
        }
        else os <<"|";

    }
    os << std::endl;

    return os;
}

//Overloaded insertion operator for Colour Blue
template<>
std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::BLUE>& qr){
    os << "Blue" << "      |";
    for(int i=0; i<10; ++i){

        //Invalid column
        if(i==4){
            os << "XX";
        }

        //Empty field
        else if(qr[i]==0) os << "  ";

        //Insert point value
        else {
            //If qr[i] is single digit, it will require an extra space
            if(qr[i] < 10) os << " ";
            os << qr[i];
        }

        //Bonus entries that require %
        if(i==1 || i==2 || i==8 || i==9){
            os << "%";
        }
        else os <<"|";

    }
    os << std::endl;

    return os;
}
=======
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
	
	//enum struct Colour {RED, YELLOW, GREEN, BLUE, WHITE};
};

#endif
>>>>>>> remotes/origin/connor
