//Here temporarily while no main function exists in the program.
//Also using for testing of built classes

#include "RollOfDice.cpp"
#include <iostream>

int main(){

    RandomDice r;
    Dice d(Colour::RED);
    Dice e(Colour::BLUE);
    Dice f(Colour::YELLOW);
    Dice g(Colour::GREEN);
    Dice h(Colour::WHITE);

    RollOfDice rod(r);

    rod.add(d);
    rod.add(e);
    rod.add(f);
    rod.add(g);
    rod.add(h);

    std::cout << "Rolling all" << std::endl;
    rod.roll();
    std::cout << rod;

    RollOfDice pair = rod.pair(d, h);

    std::cout << "Roll Pair" << std::endl;
    pair.roll();
    std::cout << pair;

    rod.rmv(e);
    rod.rmv(f);

    std::cout << "Roll after deletion" << std::endl;
    rod.roll();
    std::cout << rod;


    for(Dice d : rod){
        std::cout << "Works";
    }

    return 0;
}
