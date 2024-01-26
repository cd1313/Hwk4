#ifndef BASIC_H
#define BASIC_H

#include <string>
#include <iostream>
#include "driver.h"
using namespace std;

class Basic : public Driver {
    public:
        Basic();
        //Parameterized constructor here
        Basic(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType);
        int getDType() {return dType;};
        void setDType(int newDType) {dType = newDType;};
        void printDetails();
    private:
        int dType;
        
};

#endif