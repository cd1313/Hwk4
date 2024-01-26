#include "economy.h"
using namespace std;

Economy::Economy(){
    Driver();
    dType = 0;
}


Economy::Economy(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType) : Driver(newID, newFN, newLN, newCap, newCC, newHC, newVT, newRating, newA, newPA, newNotes, newType){
    dType = 0;
}

void Economy::printDetails(){
    //Print Details for driver
    Driver::printDetails();

    //Print driver's type (economy)
    cout << "Driver Type: Economy" << endl;
}