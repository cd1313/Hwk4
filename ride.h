#ifndef RIDE_H
#define RIDE_H

#include <string>
#include <iostream>
#include <ctime>
using namespace std;

enum stat {Active = 0, Completed = 1, Cancelled = 2};

class Ride {
    public:
        Ride();
        Ride(int newID, string newPL, time_t newPT, string newDL, int newPS, bool newIP, time_t newDT, stat newStatus, double newRating, int newDID, int newPID);
        int getID() {return id;};
        void setID(int newID) {id = newID;};
        string getPickupLocation() {return pickupLocation;};
        void setPickupLocation(string newPL) {pickupLocation = newPL;};
        time_t getPickupTime() {return pickupTime;};
        void setPickupTime(time_t newPT) {pickupTime = newPT;};
        string getDropoffLocation() {return dropoffLocation;};
        void setDropoffLocation(string newDL) {dropoffLocation = newDL;};
        int getPartySize() {return partySize;};
        void setPartySize(int newPS) {partySize = newPS;};
        bool getIncludesPets() {return includesPets;};
        void setIncludesPets(bool newIP) {includesPets = newIP;};
        time_t getDropoffTime() {return dropoffTime;};
        void setDropoffTime(time_t newDT) {dropoffTime = newDT;};
        stat getStatus() {return status;};
        void setStatus(stat newStatus) {status = newStatus;};
        double getRating() {return rating;};
        void setRating(double newRating) {rating = newRating;};
        int getDriverID() {return driverID;};
        void setDriverID(int newDID) {driverID = newDID;};
        int getPassengerID() {return passengerID;};
        void setPassengerID(int newPID) {passengerID = newPID;};
        void printDetails();

    private:
        int id;
        string pickupLocation;
        time_t pickupTime;
        string dropoffLocation;
        int partySize;
        bool includesPets;
        time_t dropoffTime;
        stat status;
        double rating;
        int driverID;
        int passengerID;
        
};

#endif