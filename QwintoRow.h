#ifndef _QWINTOROW
#define _QWINTOROW
#include "RollOfDice.h"
#include <iostream>
#include <array>

template <Colour C>
class QwintoRow{

    Colour col;
    int points[10];
    bool validate(int);
    public:
        QwintoRow();
        bool validate(int, RollOfDice);
        int& operator[](int);
        const int& operator[](int)const;
        template<Colour T>friend std::ostream& operator<<(std::ostream&, const QwintoRow<T>&);

};


#endif
