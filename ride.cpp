#include <string>
#include <iostream>
#include <ctime>
#include "ride.h"
using namespace std;

Ride::Ride(){

    id = 0;
    pickupLocation = "";
    pickupTime = 0;
    dropoffLocation = "";
    partySize = 0;
    includesPets = false;;
    dropoffTime = 0;
    status = stat(0);
    rating = 0.0;
    driverID = 0;
    passengerID = 0;
}

Ride::Ride(int newID, string newPL, time_t newPT, string newDL, int newPS, bool newIP, time_t newDT, stat newStatus, double newRating, int newDID, int newPID){
    id = newID;
    pickupLocation = newPL;
    pickupTime = newPT;
    dropoffLocation = newDL;
    partySize = newPS;
    includesPets = newIP;
    dropoffTime = newDT;
    status = newStatus;
    rating = newRating;
    driverID = newDID;
    passengerID = newPID;
}

void Ride::printDetails(){

    //Print ID of ride
    cout << "ID: " << id << endl;

    //Print pickup location of ride
    cout << "Pickup Location: " << pickupLocation << endl;

    //Print pickup time of ride
    cout << "Pickup Time: " << ctime(&pickupTime);

    //Print drop off location of ride
    cout << "Dropoff Location: " << dropoffLocation << endl;

    //Print party size of ride
    cout << "Party Size: " << partySize << endl;

    //Print includes pets for ride 
    cout << "Includes Pets: " << includesPets << endl;

    //Print drop off time of ride
    if(dropoffTime == 0){
        cout << "Dropoff Time: Not Yet Dropped Off." << endl;
    } else {
        cout << "Dropoff Time: " << ctime(&dropoffTime);
    }

    //Print status of ride
    cout << "Status: ";
    switch(status){
        case 0:
            cout << "Active" << endl;
            break;
        case 1:
            cout << "Completed" << endl;
            break;
        case 2:
            cout << "Cancelled" << endl;
            break;
    }

    //Print rating of ride
    cout << "Rating: " << rating << endl;

    //Print driver ID of ride
    cout << "Driver ID: " << driverID << endl;

    //Print passenger ID of ride
    cout << "Passenger ID: " << passengerID << endl;

}