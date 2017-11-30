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
