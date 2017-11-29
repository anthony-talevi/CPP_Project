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
