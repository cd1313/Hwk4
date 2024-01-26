#ifndef RIDES_H
#define RIDES_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "ride.h"
#include "passengers.h"
#include "drivers.h"
using namespace std;

class Rides {
    public:
        Rides() {rideCount = 0;};
        void addRide();
        void editRide();
        void deleteRide(int rideID);
        Ride* searchForRide(int rideID);
        void printAllRides();
        void printAllRidesWithDriver(int DID);
        void printAllRidesWithPassenger(int PID);
        void printAllRidesWithStatus(stat status);
        void printRideDetails(int rideID);
        void updateRideStatus();
        void deleteCancelledRides();
        void deleteCompletedRides();
        void printDriverSchedule(int DID);
        void printPassengerSchedule(int PID);
        int getRideCount() {return rideCount;};
        void setRideCount(int newRC) {rideCount = newRC;};
        void saveRides();
        void loadRides();
        int getCurrentID() {return currentID;};
        void setCurrentID(int newID) {currentID = newID;};

    private:
        vector<Ride> rideList;
        int rideCount;
        static int currentID;
};

#endif