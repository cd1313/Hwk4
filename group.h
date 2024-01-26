#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include "driver.h"
using namespace std;

class Group : public Driver {
    public:
        Group();
        Group(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType);
        int getDType() {return dType;};
        void setDType(int newDType) {dType = newDType;};
        void printDetails();
    private:
        int dType;
        
};

#endif