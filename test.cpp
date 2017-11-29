//Here temporarily while no main function exists in the program.
//Also using for testing of built classes

#include "RollOfDice.cpp"
#include "QwintoRow.cpp"
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


    QwintoRow<Colour::RED> qr;
    QwintoRow<Colour::YELLOW> qr2;
    QwintoRow<Colour::BLUE> qr3;

    // for(int i=0; i<10; ++i){
    //     try{
    //         rod.roll();
    //         qr[i] = rod;
    //     } catch(const char* errormsg){
    //         std::cout << errormsg << std::endl;
    //     }
    //
    //     try{
    //         rod.roll();
    //         qr2[i] = rod;
    //     } catch(const char* errormsg){
    //         std::cout << errormsg << std::endl;
    //     }
    //
    //     try{
    //         rod.roll();
    //         qr3[i] = rod;
    //     } catch(const char* errormsg){
    //         std::cout << errormsg << std::endl;
    //     }
    //
    // }

    for(int i=0; i<10; ++i){
        try{
            qr[i]=i+1;
        } catch(const char* errormsg){
            std::cout << errormsg << std::endl;
        }
    }


    std::cout << std::endl << qr << qr2 << qr3 << std::endl;



    // std::cout << "Rolling all" << std::endl;
    // rod.roll();
    // std::cout << rod;
    //
    // RollOfDice pair = rod.pair(d, h);
    //
    // std::cout << "Roll Pair" << std::endl;
    // pair.roll();
    // std::cout << pair;
    //
    // rod.rmv(e);
    // rod.rmv(f);
    //
    // std::cout << "Roll after deletion" << std::endl;
    // rod.roll();
    // std::cout << rod;
    //
    //
    // for(Dice d : rod){
    //     std::cout << "Works";
    // }

    return 0;
}
