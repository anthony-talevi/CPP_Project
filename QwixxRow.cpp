#ifndef _QWIXX_ROW_H
#define _QWIXX_ROW_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Dice.h"

template <class T, Colour C> class QwixxRow {
public:
	QwixxRow() {}
	~QwixxRow() {}

	//overload the compound += operator for insertion of an int
	//does error checking on list size, locked rows and invalid entry order
	QwixxRow& operator+=(int a) {
		if (locked)
			throw std::overflow_error("unable to place: " + std::to_string(a) + ". Row locked");

		//handle empty list exception case
		if (myList.size() == 0) {
			myList.emplace_back(a);

			return *this;
		}

		//handle overflow just in case
		if (myList.size() == 11) {
			throw std::overflow_error("unable to place: " + std::to_string(a) + ". Row full");
		}

		//throw error message unique by type
		auto end = myList.back();
		switch (C) {
			case Colour::RED:
			case Colour::YELLOW:
				if (a < end) {
					throw std::range_error("unable to place: " + std::to_string(a) + ". Too small");
				}
				break;
			case Colour::GREEN:
			case Colour::BLUE:
				if (a > end) {
					throw std::range_error("unable to place: " + std::to_string(a) + ". too large");
				}
				break;
		}

		//add element to list
		myList.emplace_back(a);
		
		//lock list on insertion of element farthest to the right
		switch (C) {
			case Colour::RED:
			case Colour::YELLOW:
				if (a == 12 && myList.size() >= 5) lock();
				break;
			case Colour::GREEN:
			case Colour::BLUE:
				if (a == 2 && myList.size() >= 5) lock();
				break;
		}

		return *this;
	}

	//locks the row
	void lock() {
		locked = true;
		myLock = true;
	}
	
	//returns whether or not the row is locked
	bool lockStatus() const {
		return locked;
	}

	//calculates the score of the row
	int score() {
		int score = 0;
		int temp = myList.size();

		//if you were the one to lock the row you get a bonus
		if (myLock) temp++;

		//determine the score
		switch (temp) {
			case  1: score =  1; break;
			case  2: score =  3; break;
			case  3: score =  6; break;
			case  4: score = 10; break;
			case  5: score = 15; break;
			case  6: score = 21; break;
			case  7: score = 28; break;
			case  8: score = 36; break;
			case  9: score = 45; break;
			case 10: score = 55; break;
			case 11: score = 66; break;
			case 12: score = 78; break;
			default: score =  0; break;
		}

		return score;
	}

	//insertion operator overload
	friend std::ostream& operator<<(std::ostream& os, const QwixxRow& qr) {
		//start row
		switch (C) {
			case Colour::RED:
				os << "Red      ";
				break;
			case Colour::YELLOW:
				os << "Yellow   ";
				break;
			case Colour::GREEN:
				os << "Green    ";
				break;
			case Colour::BLUE:
				os << "Blue     ";
				break;
		}

		//handle empty row special case
		if (qr.myList.size() == 0) {
			switch (C) {
				case Colour::RED:
				case Colour::YELLOW:
					os << "| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12";
					break;
				case Colour::GREEN:
				case Colour::BLUE:
					os << "|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2";
					break;
			}
		}
		else {
			//iterator is used to place the XX on the board
			typename T::const_iterator it = qr.myList.begin();

			//seperate by colour
			switch (C) {
				//red & Yellow ascending
				case Colour::RED:
				case Colour::YELLOW:
					for (int i = 2; i < 13; i++) {
						//check if there is a match
						if (i == *it) {
							os << "|XX";
							it++;
						}
						else {
							if (i > 9) os << "|" << i;
							else os << "| " << i;
						}
					}
					break;
				//green & blue descending
				case Colour::GREEN:
				case Colour::BLUE:
					for (int i = 12; i > 1; i--) {
						if (i == *it) {
							os << "|XX";
							it++;
						}
						else {
							if (i > 9) os << "|" << i;
							else os << "| " << i;
						}
					}
					break;
			}
		}

		//outputs the lock status
		if (locked)
			os << "| L";
		else
			os << "| U";

		//end of line
		os << std::endl;

		return os;
	}
private:
	T myList;
	bool myLock = false; //whether or not we were the ones who locked the row
	static bool locked; //locked is a static variable so it affects all rows of that colour
};

//this prevents linker errors: https://stackoverflow.com/a/20642192
template<class T, Colour C>
bool QwixxRow<T,C>::locked = false;

#endif // _QWIXX_ROW_H
