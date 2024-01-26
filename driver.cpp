#include "driver.h"
using namespace std;

Driver::Driver(){
        id = 0;
        firstName = "";
        lastName = "";
        capacity = 0;
        cargoCapacity = 0;
        handicappedCapable = false;
        vehicleType = "";
        rating = 0.0;
        available = false;
        petsAllowed = false;
        notes = "";
}

Driver::Driver(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType){
        id = newID;
        firstName = newFN;
        lastName = newLN;
        capacity = newCap;
        cargoCapacity = newCC;
        handicappedCapable = newHC;
        vehicleType = newVT;
        rating = newRating;
        available = newA;
        petsAllowed = newPA;
        notes = newNotes;
        type = newType;
}

Driver::~Driver(){
        
}

void Driver::printDetails(){
        
        //Print ID of the driver
        cout << "ID: " << id << endl;

        //Print first name of driver
        cout << "First Name: " << firstName << endl;

        //Print last name of driver
        cout << "Last Name: " << lastName << endl;

        //Print capacity of driver
        cout << "Capacity: " << capacity << endl;

        //Print cargo capacity of driver
        cout << "Cargo Capacity: " << cargoCapacity << endl;

        //Print handicapped capable for driver
        cout << "Handicapped Capable: " << handicappedCapable << endl;

        //Print vehicle type of driver
        cout << "Vehicle Type: " << vehicleType << endl;

        //Print rating of driver
        cout << "Rating: " << rating << endl;

        //Print available for driver
        cout << "Available: " << available << endl;

        //Print pets allowed for driver
        cout << "Pets Allowed: " << petsAllowed << endl;

        //Print notes of driver
        cout << "Notes: " << notes << endl;

}