//Here temporarily while no main function exists in the program.
//Also using for testing of built classes

<<<<<<< HEAD
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

=======
#include <iostream>

#include "RandomDice.h"
#include "Dice.h"
#include "QwintoRow.cpp"
#include "ScoreSheet.h"
#include "QwintoScoreSheet.h"

using std::cout;
using std::endl;

void someSpace() {
	for (int i = 0; i < 2; i++)
		cout << std::endl;
}

int main(){
    //Colour c = RED;
    /*RandomDice r;
    Dice d(Colour::RED);
    d.roll(r);*/
    
    cout << std::boolalpha;
    
    //QwintoRow tests
    bool testQwintoRow = true;
    if (testQwintoRow) {
    	cout << "QwintoRow Tests";
    	someSpace();
    	
	    QwintoRow<Colour::RED> qwRowRed;
	    cout << qwRowRed;
	    cout << "validating (2,4): " << qwRowRed.validate(2,4) << endl;
	    cout << "placing (2,4)" << endl;
	    qwRowRed[2] = 4;
	    cout << "validating (2,3): " << qwRowRed.validate(2,3) << endl;
	    cout << "validating (1,5): " << qwRowRed.validate(1,5) << endl;
	    cout << "validating (1,3): " << qwRowRed.validate(1,3) << endl;
	    cout << "placing (1,3)" << endl;
	    qwRowRed[1] = 3;
	    cout << "validating (3,18): " << qwRowRed.validate(3,18) << endl;
	    cout << qwRowRed;
	    
	    someSpace();
	}
    
    //QwintoScoreSheet tests
    bool testQwintoScoreSheet = true;
    if (testQwintoScoreSheet) {
    	cout << "QwintoScoreSheet Tests";
    	someSpace();
    	
	    ScoreSheet* ss;
	    ss = new QwintoScoreSheet("Test");
	    ss->print(cout);
	    
	    delete ss;
	}
    
>>>>>>> remotes/origin/connor
    return 0;
}
