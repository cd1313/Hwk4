#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "passenger.h"
using namespace std;

class Passengers {
    public:
        Passengers() {passengerCount = 0;};
        void addPassenger();
        void editPassenger();
        void deletePassenger(int passengerID);
        Passenger* searchForPassenger(int passengerID);
        void printAllPassengers();
        void printPassengerDetails(int passengerID);
        int getPassengerCount() {return passengerCount;};
        void setPassengerCount(int newPC) {passengerCount = newPC;};
        int getCurrentID() {return currentID;};
        void setCurrentID(int newCurrentID) { currentID = newCurrentID;};
        void savePassengers();
        void loadPassengers();
        
    private:
        vector<Passenger> passengerList;
        int passengerCount;
        static int currentID;
}; 

#endif