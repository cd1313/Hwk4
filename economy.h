#ifndef ECONOMY_H
#define ECONOMY_H

#include <iostream>
#include <string>
#include "driver.h"
using namespace std;

class Economy : public Driver {
    public:
        Economy();
        Economy(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType);
        int getDType() {return dType;};
        void setDType(int newDType) {dType = newDType;};
        void printDetails();
    private:
        int dType;
};

#endif