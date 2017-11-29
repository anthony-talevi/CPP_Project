#include "Dice.h"

#ifndef _QWINTO_ROW_H
#define _QWINTO_ROW_H

template <Colour C> class QwintoRow {
public:
	QwintoRow() {};
	void printRow(std::ostream& os) {
		for (auto i = 0 ; i < 12; i++) {
			os << column[i];
		}
		os << std::endl;
	}
private:
	int column[12] = {0};
};

#endif