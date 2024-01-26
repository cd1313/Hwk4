#include <iostream>
#include <string>
#ifndef LUXURY_H
#define LUXURY_H

#include "driver.h"
using namespace std;

class Luxury : public Driver {
    public:
        Luxury();
        Luxury(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType, string newAmenities);
        void printDetails();
        string getAmenities() {return amenities;};
        void setAmenities(string newAmenities) {amenities = newAmenities;};
    private:
        string amenities;
};

#endif