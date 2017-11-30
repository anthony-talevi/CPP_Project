#ifndef _QWIXX_ROW_H
#define _QWIXX_ROW_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Dice.h"

template <class T, Colour C> class QwixxRow {
public:
	QwintoRow() {
		
	}
	
	QwixxRow& operator+=(int a) {
		if (myList.size() == 0) {
			myList.emplace_back(a);

			return *this;
		}
		
		//throw error message unique by type
		auto end = myList.back();
		switch (C) {
			case Colour::RED:
			case Colour::YELLOW:
				if (a < end) {
					throw std::range_error("too small");
				}
				break;
			case Colour::GREEN:
			case Colour::BLUE:
				if (a > end) {
					throw std::range_error("too large");
				}
				break;
		}
		
		//TODO: handle rule for proper insertion of elements
		
		myList.emplace_back(a);
		
		return *this;
	}
	
	void lock() {
		locked = true;
	}
	
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
		
		//need to display row
		if (myList.size() == 0) //TODO display properly for FW/BW
			os << "|  |  |  |  |  |  |  |  |  |  |  ";
		else {
			typename T::iterator it = myList.begin();
			
			for (int i = 2; i < 13; i++) {
				if (i == *it) {
					os << "|XX";
					it++;
				}
				else {
					if (i > 9)
						os << "|" <<i;
					else
						os << "| " << i;
				}
			}
		}
		
		//TODO fix locked/unlocked
		
		/*if (locked)
			os << "| L";
		else
			os << "| U";*/
		
		os << std::endl;
		
		return os;
	}
private:
	static T myList;
	bool locked = false;
};

//this prevents linker errors: https://stackoverflow.com/a/20642192
template<class T, Colour C>
T QwixxRow<T,C>::myList;

#endif // _QWIXX_ROW_H
