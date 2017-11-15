//Here temporarily while no main function exists in the program.
//Also using for testing of built classes

#include "RandomDice.h"
#include "Dice.h"

int main(){
    //Colour c = RED;
    RandomDice r;
    Dice d(Colour::RED);
    d.roll(r);
    return 0;
}
