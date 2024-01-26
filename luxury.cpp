#include "luxury.h"
using namespace std;

Luxury::Luxury(){
    Driver();
    amenities = "";
}

Luxury::Luxury(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType, string newAmenities) : Driver(newID, newFN, newLN, newCap, newCC, newHC, newVT, newRating, newA, newPA, newNotes, newType){
    amenities = newAmenities;
}

void Luxury::printDetails(){
    //Print Details for driver
    Driver::printDetails();

    //Print driver's type (luxury)
    cout << "Driver Type: Luxury" << endl;

    //Print amenities for driver
    cout << "Ameneties: " << amenities << endl;
}