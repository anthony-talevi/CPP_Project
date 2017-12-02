//Here temporarily while no main function exists in the program.
//Also using for testing of built classes

#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

#include "QwintoScoreSheet.h"
#include "QwixxScoreSheet.h"

using std::cout;
using std::endl;

void someSpace() {
	for (int i = 0; i < 2; i++)
		cout << std::endl;
}

int main(){
	//makes a bool value true/false   
    cout << std::boolalpha;
    
    //QwintoRow tests
    bool testQwintoRow = false;
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
	
	//QwixxRow tests
	bool testQwixxRow = false;
	if (testQwixxRow) {
		cout << "QwixxRow Tests";
		someSpace();
		
		QwixxRow<std::vector<int>, Colour::RED> qxRowRed;
		QwixxRow<std::list<int>, Colour::GREEN> qxRowGreen;
		
		cout << "Empty rows" <<endl;
		cout << qxRowRed;
		cout << qxRowGreen;
		cout << endl;
		
		cout << "Placing 2,6,3 in red" << endl;
		try {
			qxRowRed += 2;
			qxRowRed += 6;
			qxRowRed += 3;
		} catch (std::exception& error) {
			cout << error.what() << endl;
		}
		
		cout << "Placing 4,11 in green" << endl;
		try {
			qxRowGreen += 4;
			qxRowGreen += 11;
		} catch (std::exception& error) {
			cout << error.what() << endl;
		}
		
		cout << endl;
		cout <<"Rows with insertions" <<endl;
		cout << qxRowRed;
		cout << qxRowGreen;
		
		cout << endl << "locking red" <<endl;
		qxRowRed.lock();
		try {
			qxRowRed += 9;
		} catch (std::exception& error) {
			cout << error.what() << endl;
		}
		
		QwixxRow<std::vector<int>, Colour::RED> qxRowRed2;
		
		cout << qxRowRed;
		cout << qxRowRed2;
		cout << qxRowGreen;
	}
    
    //QwintoScoreSheet tests
    bool testQwintoScoreSheet = false;
    if (testQwintoScoreSheet) {
    	cout << "QwintoScoreSheet Tests";
    	someSpace();
    	
	    ScoreSheet* ss;
	    ss = new QwintoScoreSheet("Test");
	    ss->print(cout);
	    
	    delete ss;
	}
	
	//QwixxScoreSheet tests
	bool testQwixxScoreSheet = true;
	if (testQwixxScoreSheet) {
		cout << "QwixxScoreSheet Tests";
		someSpace();
		
		ScoreSheet* ss;
		ss = new QwixxScoreSheet("Test");
		ss->print(cout);
		ss->fail();
		ss->fail();
		ss->print(cout);
		
		delete ss;
	}
    
    return 0;
}
