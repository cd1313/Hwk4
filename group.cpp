#include "group.h"
using namespace std;

Group::Group(){
    Driver();
    dType = 2;
}

Group::Group(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType) : Driver(newID, newFN, newLN, newCap, newCC, newHC, newVT, newRating, newA, newPA, newNotes, newType){
    dType = 2;
}

void Group::printDetails(){
    //Print Details for driver
    Driver::printDetails();

    //Print driver's type (group)
    cout << "Driver Type: Group" << endl;
}