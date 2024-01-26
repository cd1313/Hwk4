#include "basic.h"
using namespace std;

Basic::Basic(){
    dType = 1;
    Driver();
}

Basic::Basic(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType) : Driver(newID, newFN, newLN, newCap, newCC, newHC, newVT, newRating, newA, newPA, newNotes, newType){
   dType = 1;
}

void Basic::printDetails(){
    //Print Details for driver
    Driver::printDetails();

    //Print driver's type (basic)
    cout << "Driver Type: Basic" << endl;
}