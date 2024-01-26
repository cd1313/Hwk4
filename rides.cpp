#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <fstream>
#include "rides.h"

int Rides::currentID = 10000000;
Passengers myPassengers;
Drivers myDrivers;

void Rides::addRide(){
    int id, partySize, driverID, passengerID;
    string pickupLocation, dropoffLocation;
    double rating;
    stat status = stat(0);
    time_t pickupTime, dropoffTime = 0;
    int hour, minute, year, month, day;
    bool includesPets;
    int temp;
    tm *tempTime = new tm;

    //Auto assign ID number and increment current ID
    id = currentID;

    //Prompt user for passenger ID
    cout << "Enter your passenger ID (6 digits): ";
    cin >> passengerID;
    while(passengerID > 999999 || passengerID < 100000){
        cout << "Enter your passenger ID (6 digits): ";
        cin >> passengerID;
    }

    //Prompt user for pickup location
    cout << "Enter pickup location: ";
    cin.ignore();
    getline(cin, pickupLocation);

    //Prompt user for pickup time information
    cout << "Enter the year for your pickup date: ";
    cin >> year;
    cout << "Enter the month for your pickup date (0-11): ";
    cin >> month;
    while(month < 0 || month > 11){
        cout << "Enter the month for your pickup date (0-11): ";
        cin >> month;
    }
    cout << "Enter the day for your pickup date (1-31): ";
    cin >> day;
    while(day < 1 || day > 31){
        cout << "Enter the day for your pickup date (1-31): ";
        cin >> day;
    }
    cout << "Enter hour of the day for pickup time (0-23): ";
    cin >> hour;
    while(hour < 0 || hour > 23){
        cout << "Enter hour of the day for pickup time (0-23): ";
        cin >> hour;
    }
    cout << "Enter minute value for pickup time (0-59): ";
    cin >> minute;
    while(minute < 0 || minute > 59){
        cout << "Enter minute value for pickup time (0-59): ";
        cin >> minute;
    }
    tempTime->tm_min = minute;
    tempTime->tm_hour = hour;
    tempTime->tm_year = year-1900;
    tempTime->tm_mon = month;
    tempTime->tm_mday = day;
    tempTime->tm_sec = 0;
    tempTime->tm_isdst = -1;
    tempTime->tm_wday = 0;
    tempTime->tm_yday = 0;
    pickupTime = mktime(tempTime);
    delete tempTime;

    //Prompt user for dropoff location
    cout << "Enter dropoff location: ";
    cin.ignore();
    getline(cin, dropoffLocation);

    //Prompt user for party size
    cout << "Enter party size: ";
    cin >> partySize;

    //Prompt user for pets included
    cout << "Are you bringing pets? (0 for no, 1 for yes): ";
    cin >> temp;
    while(temp != 0 && temp != 1){
        cout << "Are you bringing pets? (0 for no, 1 for yes): ";
        cin >> temp;
    }
    includesPets = temp;

    rating = 0.0;

    //Prompt user for driver ID
    cout << "Enter ID of requested driver (6 digits): ";
    cin >> driverID;
    while(driverID < 100000 || driverID > 999999){
        cout << "Enter ID of requested driver (6 digits): ";
        cin >> driverID;
    }

    //Create and populate a new ride object (empty variables for drop off time, status, and rating)
    Ride tempRide(id, pickupLocation, pickupTime, dropoffLocation, partySize, includesPets, dropoffTime, status, rating, driverID, passengerID);
 
    Driver *d = myDrivers.searchForDriver(driverID);
    Passenger *p = myPassengers.searchForPassenger(passengerID);
    time_t now = time(nullptr);

    //Check if the passenger exists
    if(p == nullptr){
        cout << "\nThe passenger ID was invalid." << endl << endl;
        return;

    //Check if the driver exists
    } else if(d == nullptr){
        cout << "\nThe requested driver doesn't exist." << endl << endl;
        return;

    //Check if the driver has enough capacity
    } else if (d->getCapacity() < partySize){
        cout << "\nThe requested driver does not have sufficient capacity." << endl << endl;
        return;

    //Check if the driver has an appropriate pet policy
    } else if (!(d->getPetsAllowed()) && includesPets){
        cout << "\nThe requested driver does not have an appropriate pet policy." << endl << endl;
        return;

    //Check if the driver has an appropriate handicapped capability
    } else if (p->getHandicapped() && !(d->getHandicappedCapable())){
        cout << "\nThe requested driver does not have an appropraite handicapped policy." << endl << endl;
        return;
    
    //Check if the driver has the minimum required rating
    } else if(p->getRequiredRating() > d->getRating()){
        cout << "\nThe requested driver does not have a sufficient rating." << endl << endl;
        return;

    //Check if the pickup time has passed
    } else if (now > pickupTime){
        cout << "\nThe pickup time you requested has already passed." << endl << endl;
    }

    //Check if the driver is available, assuming that rides last 30 minutes by default
    for(int i = 0; i < rideCount; i++){
        Ride r = rideList[i];
        if(r.getDriverID() == driverID){
            if(r.getPickupTime() < pickupTime){
                if(r.getDropoffTime() == 0 && r.getPickupTime()+1800 >= pickupTime){
                    cout << "\nThe requested driver is busy at the time you requested." << endl << endl;
                    return;
                } else if (r.getDropoffTime() >= pickupTime){
                    cout << "\nThe requested driver is busy at the time you requested." << endl << endl;
                    return;
                }
            } else {
                if(r.getPickupTime() < pickupTime+1800){
                    cout << "\nThe requested driver is busy at the time you requested." << endl << endl;
                    return;
                }
            }
        }
    }

    cout << endl;

    //Add ride object to ride list and increment current ID
    rideList.push_back(tempRide);
    currentID++;

    //Increment ride count
    rideCount++;

    //Store all rides in ride list in file 
    saveRides();
    
}


void Rides::editRide(){
    int rideID, choice;

    //Prompt user for ID number
    cout << "Enter Ride ID (8 digits): ";
    cin >> rideID;
    while(rideID < 10000000 || rideID > 99999999){
        cout << "Enter Ride ID (8 digits): ";
        cin >> rideID;
    }

    //Prompt user for data member to update
    cout << "\nChoose Value to Edit:" << endl << endl;
    cout << "Pickup Location - 1\nPickup Time - 2\nDropoff Location - 3\nDropoff Time - 4\nRating - 5\nStatus - 6\nParty Size - 7\nIncludes Pets - 8" << endl << endl;
    cout << "Enter choice (1-8): ";
    cin >> choice;
    while(choice < 1 || choice > 8){
        cout << "Enter choice (1-8): ";
        cin >> choice;
    }
    cout << endl;

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If the ride ID matches
        if(rideList[i].getID() == rideID){
            Ride &r = rideList[i];
            Driver *d = myDrivers.searchForDriver(r.getDriverID());
            tm *t1 = new tm;
            t1->tm_sec = 0;
            t1->tm_isdst = -1;
            t1->tm_wday = 0;
            t1->tm_yday = 0;
            double t2;
            int t3;
            time_t t4;
            string t5;
            switch(choice){
                case 1:
                    //Check if the data member can be edited
                    if(r.getPickupTime() <= time(nullptr)){
                        cout << "You can no longer change the pickup location." << endl << endl;
                        return;
                    }

                    //Prompt user for new pickup location
                    cout << "Enter new pickup location: ";
                    cin.ignore();
                    getline(cin, t5);

                    //Update the ride information according to user input
                    r.setPickupLocation(t5);
                    break;
                case 2:
                    //Check if the data member can be edited
                    if(r.getPickupTime() <= time(nullptr)){
                        cout << "You can no longer change the pickup time." << endl << endl;
                        return;
                    }

                    //Prompt user for new pickup time information
                    cout << "Enter the year for your pickup date: ";
                    cin >> t3;
                    t1->tm_year = t3-1900;
                    cout << "Enter the month for your pickup date (0-11): ";
                    cin >> t3;
                    while(t3 < 0 || t3 > 11){
                        cout << "Enter the month for your pickup date (0-11): ";
                        cin >> t3;
                    }
                    t1->tm_mon = t3;
                    cout << "Enter the day for your pickup date (1-31): ";
                    cin >> t3;
                    while(t3 < 1 || t3 > 31){
                        cout << "Enter the day for your pickup date (1-31): ";
                        cin >> t3;
                    }
                    t1->tm_mday = t3;
                    cout << "Enter hour of the day for pickup time (0-23): ";
                    cin >> t3;
                    while(t3 < 0 || t3 > 23){
                        cout << "Enter hour of the day for pickup time (0-23): ";
                        cin >> t3;
                    }
                    t1->tm_hour = t3;
                    cout << "Enter minute value for pickup time (0-59): ";
                    cin >> t3;
                    while(t3 < 0 || t3 > 59){
                        cout << "Enter minute value for pickup time (0-59): ";
                        cin >> t3;
                    }
                    t1->tm_min = t3;

                    t4 = mktime(t1);
                    delete t1;
                    
                    //Check if the new pickup time is valid (assuming rides last 30 minutes by default)
                    if(t4 < time(nullptr)){
                        cout << "\nThat pickup time is invalid." << endl << endl;
                        return;
                    }
                    for(int i = 0; i < rideCount; i++){
                        Ride tempR = rideList[i];
                        if(tempR.getDriverID() == r.getDriverID() && tempR.getID() != r.getID()){
                            if(tempR.getPickupTime() < t4){
                                if(tempR.getDropoffTime() == 0 && tempR.getPickupTime()+1800 >= t4){
                                    cout << "\nYour requested driver is busy at this new pickup time." << endl << endl;
                                    return;
                                } else if (tempR.getDropoffTime() >= t4){
                                    cout << "\nYour requested driver is busy at this new pickup time." << endl << endl;
                                    return;
                                }
                            } else {
                                if(tempR.getPickupTime() < t4+1800){
                                    cout << "\nYour requested driver is busy at this new pickup time." << endl << endl;
                                    return;
                                }
                            }
                        }
                    }

                    //Update the ride information according to user input
                    r.setPickupTime(t4);
                    break;
                case 3:
                    //Check if the data member can be edited
                    if(r.getDropoffTime() != 0 && r.getDropoffTime() <= time(nullptr)){
                        cout << "You can no longer change the dropoff location." << endl << endl;
                        return;
                    }

                    //Prompt user for new dropoff location
                    cin.ignore();
                    cout << "Enter new dropoff location: ";
                    getline(cin, t5);

                    //Update the ride information according to user input
                    r.setDropoffLocation(t5);
                    break;
                case 4:
                    //Prompt user for new dropoff date information
                    cout << "Enter the year for your dropoff date: ";
                    cin >> t3;
                    t1->tm_year = t3-1900;
                    cout << "Enter the month for your dropoff date (0-11): ";
                    cin >> t3;
                    while(t3 < 0 || t3 > 11){
                        cout << "Enter the month for your dropoff date (0-11): ";
                        cin >> t3;
                    }
                    t1->tm_mon = t3;
                    cout << "Enter the day for your dropoff date (1-31): ";
                    cin >> t3;
                    while(t3 < 1 || t3 > 31){
                        cout << "Enter the day for your dropoff date (1-31): ";
                        cin >> t3;
                    }
                    t1->tm_mday = t3;
                    cout << "Enter hour of the day for dropoff time (0-23): ";
                    cin >> t3;
                    while(t3 < 0 || t3 > 23){
                        cout << "Enter hour of the day for dropoff time (0-23): ";
                        cin >> t3;
                    }
                    t1->tm_hour = t3;
                    cout << "Enter minute value for dropoff time (0-59): ";
                    cin >> t3;
                    while(t3 < 0 || t3 > 59){
                        cout << "Enter minute value for dropoff time (0-59): ";
                        cin >> t3;
                    }
                    t1->tm_min = t3;

                    t4 = mktime(t1);
                    delete t1;

                    //Check if the new dropoff time is valid
                    if(t4 < r.getPickupTime()){
                        cout << t4 << " " << "\nThat dropoff time is invalid." << endl << endl;
                        return;
                    }

                    //Update the ride information according to user input
                    r.setDropoffTime(t4);
                    r.setStatus(stat(1));
                    break;
                case 5:
                    //Prompt user for new rating
                    cout << "Enter new rating (0-5): ";
                    cin >> t2;
                    while(t2 < 0 || t2 > 5){
                        cout << "Enter new rating (0-5): ";
                        cin >> t2;
                    }

                    //Update the ride information according to user input
                    r.setRating(t2);
                    break;
                case 6:
                    //Check if the data member can be edited
                    if(r.getStatus() != 0){
                        cout << "The status of this ride can no longer be edited." << endl << endl;
                        return;
                    }

                    //Prompt user for new stats
                    cout << "Enter new status (1 for Completed, 2 for Cancelled): ";
                    cin >> t3;
                    while(t3 < 0 || t3 > 2){
                        cout << "Enter new status (1 for Completed, 2 for Cancelled): ";
                        cin >> t3;
                    }

                    //Update the ride information according to user input
                    if(t3 == 1 && r.getDropoffTime() == 0){
                        r.setDropoffTime(time(nullptr));
                    }
                    r.setStatus(stat(t3));
                    break;
                case 7:
                    //Check if the data member can be edited
                    if(r.getPickupTime() < time(nullptr)){
                        cout << "You can no longer change the party size." << endl << endl;
                        return;
                    }

                    //Prompt user for new party size
                    cout << "Enter new party size: ";
                    cin >> t3;

                    //Check if the new party size is valid
                    if(t3 > d->getCapacity()){
                        cout << "The driver does not have enough capacity for that party size." << endl << endl;
                        return;
                    }

                    //Update the ride information according to user input
                    r.setPartySize(t3);
                    break;
                case 8:
                    //Check if the data member can be edited
                    if(r.getPickupTime() < time(nullptr)){
                        cout << "You can no longer change pet status." << endl << endl;
                        return;
                    }

                    //Prompt user for new pet status
                    cout << "Enter new pet status (0 for no pets, 1 for includes pets): ";
                    cin >> t3;
                    while(t3 != 0 && t3 != 1){
                        cout << "Enter new pet status (0 for no pets, 1 for includes pets): ";
                        cin >> t3;
                    }

                    //Check if new pets status is valid
                    if(t3 && !(d->getPetsAllowed())){
                        cout << "Your driver does not allow pets, cannot change pet status." << endl << endl;
                        return;
                    }

                    //Update the ride information according to user input
                    r.setIncludesPets(t3);
                    break;

            }
            cout << endl;

            //Store all rides in ride list in file
            saveRides();
            return;
        }
    }

    cout << "Ride not found." << endl << endl;

}

void Rides::deleteRide(int rideID){

    //Check through ever ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If the ride ID matches
        if(rideList[i].getID() == rideID){

            //Erase the ride object
            rideList.erase(rideList.begin()+i);

            //Decrement ride count
            rideCount--;

            //Store all rides in ride list in file
            saveRides();
            return;
        }
    }
    cout << "Ride Not Found." << endl << endl;
}

Ride* Rides::searchForRide(int rideID){

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If the ride ID matches
        if(rideList[i].getID() == rideID){

            //Return the ride object
            return &rideList[i];
        }
    }
    return nullptr;
}

void Rides::printAllRides(){

    //Check through ever ride in ride list
    if(rideCount == 0){
        cout << "Ride List Empty." << endl << endl;
        return;
    }
    cout << "Rides:" << endl << endl;
    for(int i = 0; i < rideCount; i++){

        //Print Details for ride
        rideList[i].printDetails();
        cout << endl;
    }
}

void Rides::printAllRidesWithDriver(int DID){

    //Create a temporary collection of rides
    vector<Ride> tempV;

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If driver ID matches
        if(rideList[i].getDriverID() == DID){

            //Add ride to collection
            tempV.push_back(rideList[i]);
        }
    }

    //Check through every ride in the temporary collection
    if(tempV.size()==0){
        cout << "No Rides With Driver." << endl << endl;
        return;
    }
    cout << "Rides With Driver:" << endl << endl;
    for(int i = 0; i < tempV.size(); i++){

        //Print Details for ride
        tempV[i].printDetails();
        cout << endl;
    }
}

void Rides::printAllRidesWithPassenger(int PID){

    //Create a temporary collection of rides
    vector<Ride> tempV;

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If passenger ID matches
        if(rideList[i].getPassengerID() == PID){

            //Add ride to collection
            tempV.push_back(rideList[i]);
        }
    }

    //Check through every ride in the temporary collection
    if(tempV.size()==0){
        cout << "No Rides With Passenger." << endl << endl;
        return;
    }
    cout << "Rides With Passenger:" << endl << endl;
    for(int i = 0; i < tempV.size(); i++){

        //Print details for ride
        tempV[i].printDetails();
        cout << endl;
    }
}

void Rides::printAllRidesWithStatus(stat status){

    //Create a temporary collection of rides
    vector<Ride> tempV;

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If status matches
        if(rideList[i].getStatus() == status){

            //Add ride to collection
            tempV.push_back(rideList[i]);
        }
    }

    //Check through every ride in the temporary collection
    if(tempV.size() == 0){
        cout << "No Rides With that Status." << endl << endl;
    }
    for(int i = 0; i < tempV.size(); i++){

        //Print Details for ride
        tempV[i].printDetails();
        cout << endl;
    }
}

void Rides::printRideDetails(int rideID){

    //Search for ride with the given ID number
    Ride *r = searchForRide(rideID);

    //Print Details for ride
    if(r == nullptr){
        cout << "Ride Not Found." << endl << endl;
        return;
    }
    cout << "Ride Details:" << endl << endl;
    r->printDetails();
    cout << endl;
}

void Rides::updateRideStatus(){
    time_t currTime = time(nullptr);

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If the ride dropoff time as passed
        if(currTime > rideList[i].getDropoffTime() && rideList[i].getDropoffTime() != 0){

            //Set status of ride to complete
            rideList[i].setStatus(stat(1));
        }
    }

    //Store all rides in ride list in file
    saveRides();
}

void Rides::deleteCancelledRides(){

    //Check through all rides in ride list
    for(int i = 0; i < rideCount; i++){

        //If the ride status is cancelled
        if(rideList[i].getStatus() == stat(2)){

            //Erase the ride object
            rideList.erase(rideList.begin()+i);
            i--;

            //Decrement ride count
            rideCount--;
        }
    }

    //Store all rides in ride list in file
    saveRides();
}

void Rides::deleteCompletedRides(){

    //Check through all rides in ride list
    for(int i = 0; i < rideCount; i++){

        //If the ride status is completed
        if(rideList[i].getStatus() == stat(1)){

            //Erase the ride object
            rideList.erase(rideList.begin()+i);
            i--;

            //Decrement ride count
            rideCount--;
        }
    }

    //Store all rides in ride list in file
    saveRides();
}

void Rides::printDriverSchedule(int DID){

    //Create a temporary collection of rides
    vector<Ride> tempV;

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If driver ID matches
        if(rideList[i].getDriverID() == DID){

            //Add ride to collection
            tempV.push_back(rideList[i]);
        }
    }

    //While the temporary collection is not empty
    if(tempV.size()==0){
        cout << "No Rides With Driver." << endl << endl;
        return;
    }
    cout << "Driver Schedule:" << endl << endl;
    while(tempV.size() != 0){
        int t = 0;
        
        //Check through every ride in the temporary collection find first ride
        for(int i = 0; i < tempV.size(); i++){
            if(tempV[t].getPickupTime() >= tempV[i].getPickupTime()){
                t = i;
            }
        }

        //Print Details for first ride
        tempV[t].printDetails();
        cout << endl;

        //Erase the ride object
        tempV.erase(tempV.begin()+t);
    }
}

void Rides::printPassengerSchedule(int PID){

    //Create a temporary collection of rides
    vector<Ride> tempV;

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){

        //If  passenger ID matches
        if(rideList[i].getPassengerID() == PID){

            //Add ride to collection
            tempV.push_back(rideList[i]);
        }
    }

    //While the temporary collection is not empty
    if(tempV.size()==0){
        cout << "No Rides With Passenger." << endl << endl;
        return;
    }
    cout << "Passenger Schedule:" << endl << endl;
    while(tempV.size() != 0){
        int t = 0;

        //Check through every ride in the temporary collection and find first ride
        for(int i = 0; i < tempV.size(); i++){
            if(tempV[t].getPickupTime() >= tempV[i].getPickupTime()){
                t = i;
            }
        }

        //Print Details for first ride
        tempV[t].printDetails();
        cout << endl;

        //Erase the ride object
        tempV.erase(tempV.begin()+t);
    }
}

void Rides::saveRides(){

    //Open file stream
    ofstream fout("rides.txt");

    fout << noboolalpha;

    //Check through every ride in ride list
    for(int i = 0; i < rideCount; i++){
        Ride r = rideList[i];

        //Write out ID number, pickup location, pickup time, dropoff location, party size, pets included, dropoff time, status, rating, driver ID, and passenger ID 
        fout << r.getID() << endl << r.getPickupLocation() << endl << r.getPickupTime() << endl << r.getDropoffLocation() << endl;
        fout << r.getPartySize() << endl << r.getIncludesPets() << endl << r.getDropoffTime() << endl << r.getStatus() << endl;
        fout << r.getRating() << endl << r.getDriverID() << endl << r.getPassengerID() << endl << endl;
    }

    fout << boolalpha;

    //Close file stream
    fout.close();
}

void Rides::loadRides(){

    //Open file stream
    ifstream fin("rides.txt");

    int id, partySize, driverID, passengerID;
    string pickupLocation, dropoffLocation;
    int temp;
    stat status;
    bool includesPets;
    double rating;
    time_t pickupTime, dropoffTime;

    //While there is input in the file, read in ID number
    while(fin >> id){

        //Read in pickup location, pickup time, dropoff location, party size, pets included, dropoff time, status, rating, driver ID, and passenger ID
        fin.ignore();
        getline(fin, pickupLocation);
        fin >> pickupTime;
        fin.ignore();
        getline(fin, dropoffLocation);
        fin >> partySize >> includesPets >> dropoffTime >> temp >> rating >> driverID >> passengerID;
        status = stat(temp);

        //Create a populate a new ride object
        Ride r(id, pickupLocation, pickupTime, dropoffLocation, partySize, includesPets, dropoffTime, status, rating, driverID, passengerID);

        //Add ride object to ride list
        rideList.push_back(r);

        //Increment ride count
        rideCount++;

        //Update current ID
        currentID = max(getCurrentID(), id+1);
    }

    //Close file stream
    fin.close();
}