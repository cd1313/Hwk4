#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>
using namespace std;

class Driver {
    public:
        Driver();
        Driver(int newID, string newFN, string newLN, int newCap, int newCC, bool newHC, string newVT, double newRating, bool newA, bool newPA, string newNotes, int newType);
        virtual ~Driver();
        int getID() {return id;};
        void setID(int newID) {id = newID;};
        string getFirstName() {return firstName;};
        void setFirstName(string newFN) {firstName = newFN;};
        string getLastName() {return lastName;};
        void setLastName(string newLN) {lastName = newLN;};
        int getCapacity() {return capacity;};
        void setCapacity(int newCap) {capacity = newCap;};
        int getCargoCapacity() {return cargoCapacity;};
        void setCargoCapacity(int newCC) {cargoCapacity = newCC;};
        bool getHandicappedCapable() {return handicappedCapable;};
        void setHandicappedCapable(bool newHC) {handicappedCapable = newHC;};
        string getVehicleType() {return vehicleType;};
        void setVehicleType(string newVT) {vehicleType = newVT;};
        double getRating() {return rating;};
        void setRating(double newRating) {rating = newRating;};
        bool getAvailable() {return available;};
        void setAvailable(bool newA) {available = newA;};
        bool getPetsAllowed() {return petsAllowed;};
        void setPetsAllowed(bool newPA) {petsAllowed = newPA;};
        string getNotes() {return notes;};
        void setNotes(string newNotes) {notes = newNotes;};
        int getType() {return type;};
        void setType(int newType) {type = newType;};
        virtual void printDetails();
         
    protected:
        int id;
        string firstName;
        string lastName;
        int capacity;
        int cargoCapacity;
        bool handicappedCapable;
        string vehicleType;
        double rating;
        bool available;
        bool petsAllowed;
        string notes;
        int type;
};

#endif