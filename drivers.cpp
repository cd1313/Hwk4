#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "drivers.h"
using namespace std;

int Drivers::currentID = 100000;

void Drivers::addDriver(){
    int type;
    int id, capacity, cargoCapacity;
    string firstName, lastName, vehicleType, notes;
    double rating;
    int temp;
    bool handicappedCapable, available, petsAllowed;

    //Auto assign ID number and increment current ID
    id = currentID;
    currentID++;

    //Prompt user for driver type
    cout << "Enter driver type (0 for economy, 1 for basic, 2 for group, 3 for luxury): ";
    cin >> type;
    while(type < 0 || type > 3){
        cout << "Enter driver type (0 for economy, 1 for basic, 2 for group, 3 for luxury): ";
        cin >> type;
    }

    //Prompt user for first name
    cout << "Enter first name (20 char limit): ";
    cin >> firstName;
    while(firstName.size() > 20){
        cout << "Enter first name (20 char limit): ";
        cin >> firstName;
    }

    //Prompt user for last name
    cout << "Enter last name (20 char limit): ";
    cin >> lastName;
    while(lastName.size() > 20){
        cout << "Enter last name (20 char limit): ";
        cin >> lastName;
    }

    //Prompt user for capacity and check that it is valid for the driver type
    bool valid = false;
    while(!valid){
        cout << "Enter capacity: ";
        cin >> capacity;
        switch(type){
            case 0:
                if(capacity < 1 || capacity > 2){
                    cout << "That capacity is not valid for an economy driver. Enter a value from 1-2." << endl;
                } else {
                    valid = true;
                }
                break;
            case 1:
                if(capacity < 2 || capacity > 4){
                    cout << "That capacity is not valid for a basic driver. Enter a value from 2-4." << endl;
                } else {
                    valid = true;
                }
                break;
            case 2:
                if(capacity < 5 || capacity > 7){
                    cout << "That capacity is not valid for a group driver. Enter a value from 5-7." << endl;
                } else {
                    valid = true;
                }
                break;
            case 3:
                if(capacity < 7){
                    cout << "That capacity is not valid for a luxury driver. Enter a value 7 or higher." << endl;
                } else {
                    valid = true;
                }
                break;
        }
    }

    //Prompt user for cargo capacity and check that it is valid for the driver type
    valid = false;
    while(!valid){
        cout << "Enter cargo capacity: ";
        cin >> cargoCapacity;
        switch(type){
            case 0:
                if(cargoCapacity < 1 || cargoCapacity > 2){
                    cout << "That cargo capacity is not valid for an economy driver. Enter a value from 1-2." << endl;
                } else {
                    valid = true;
                }
                break;
            case 1:
                if(cargoCapacity < 2 || cargoCapacity > 4){
                    cout << "That cargo capacity is not valid for a basic driver. Enter a value from 2-4." << endl;
                } else {
                    valid = true;
                }
                break;
            case 2:
                if(cargoCapacity < 5 || cargoCapacity > 7){
                    cout << "That cargo capacity is not valid for a group driver. Enter a value from 5-7." << endl;
                } else {
                    valid = true;
                }
                break;
            case 3:
                if(cargoCapacity < 7){
                    cout << "That cargo capacity is not valid for a luxury driver. Enter a value 7 or higher." << endl;
                } else {
                    valid = true;
                }
                break;
        }
    }

    //Prompt user for handicap capability
    cout << "Enter handicapped capability (0 for no, 1 for yes): ";
    cin >> temp;
    while(temp != 0 && temp != 1){
        cout << "Enter handicapped capability (0 for no, 1 for yes): ";
        cin >> temp;
    }
    handicappedCapable = temp;

    //Prompt user for vehicle type
    cout << "Enter vehicle type: ";
    cin.ignore();
    getline(cin, vehicleType);

    //Prompt user for rating
    cout << "Enter rating (0-5): ";
    cin >> rating;
    while(rating < 0 || rating > 5){
        cout << "Enter rating (0-5): ";
        cin >> rating;
    }

    //Prompt user for availability
    cout << "Enter availability (0 for no, 1 for yes): ";
    cin >> temp;
    while(temp != 0 && temp != 1){
        cout << "Enter availability (0 for no, 1 for yes): ";
        cin >> temp;
    }
    available = temp;

    //Prompt user for pet allowance
    cout << "Enter pet policy (0 for not allowed, 1 for allowed): ";
    cin >> temp;
    while(temp != 0 && temp != 1){
        cout << "Enter pet policy (0 for not allowed, 1 for allowed): ";
        cin >> temp;
    }
    petsAllowed = temp;

    //Prompt user for notes
    cout << "Enter additional notes: ";
    cin.ignore();
    getline(cin, notes);
    
    //Create and populate new driver object based on driver type
    Driver *tempDriver = nullptr;
    switch(type){
        case 0:
            tempDriver = new Economy(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type);
            cout << endl;
            break;
        case 1:
            tempDriver = new Basic(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type);
            cout << endl;
            break;
        case 2:
            tempDriver = new Group(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type);
            cout << endl;
            break;
        case 3:
            //If the driver type is luxury: prompt user for amenities
            string amenities;

            cout << "Enter list of amenities: ";
            getline(cin, amenities);
            cout << endl;
    
            tempDriver = new Luxury(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type, amenities);
            break;
    }

    //Add driver object to the driver list
    driverList.push_back(tempDriver);

    //Increment driver count
    driverCount++;

    //Store all drivers in driver list in file
    saveDrivers();
}


void Drivers::editDriver(){
    int driverID, choice;

    //Prompt user for ID number
    cout << "Enter Driver ID (6 digits): ";
    cin >> driverID;
    while(driverID < 100000 || driverID > 999999){
        cout << "Enter Driver ID (6 digits): ";
        cin >> driverID;
    }

    //Prompt user for data member to update
    cout << "\nChoose Value to Edit:" << endl << endl;
    cout << "First Name - 1\nLast Name - 2\nCapacity - 3\nHandicapped Capable - 4\n";
    cout << "Vehicle Type - 5\nRating - 6\nAvailable - 7\nPets Allowed - 8\nNotes - 9\nAmenities - 10\nCargo Capacity - 11\n";
    cout  << "\nEnter choice (1-11): ";
    cin >> choice;
    while(choice < 1 || choice > 11){
        cout << "Enter choice (1-11): ";
        cin >> choice;
    }
    cout << endl;

    //Check through every driver in driver list
    for(int i = 0; i < driverCount; i++){

        //If driver ID matches
        if(driverList[i]->getID() == driverID){
            Driver *d = driverList[i];
            string t1;
            int t2;
            bool t3;
            double t4;
            bool valid;
            
            switch(choice){
                case 1:
                    //Prompt user for new first name
                    cout << "Enter new first name (20 char limit): ";
                    cin >> t1;
                    while(t1.size() > 20){
                        cout << "Enter new first name (20 char limit): ";
                        cin >> t1;
                    }

                    //Update the driver information according to user input
                    d->setFirstName(t1);
                    break;

                case 2:
                    //Prompt user for new last name
                    cout << "Enter new last name (20 char limit): ";
                    cin >> t1;
                    while(t1.size() > 20){
                        cout << "Enter new last name (20 char limit): ";
                        cin >> t1;
                    }

                    //Update the driver information according to user input
                    d->setLastName(t1);
                    break;
                case 3:
                    //Prompt user for new capacity
                    valid = false;
                    while(!valid){
                        cout << "Enter new capacity: ";
                        cin >> t2;
                        switch(d->getType()){
                            case 0:
                                if(t2 < 1 || t2 > 2){
                                    cout << "That capacity is not valid for an economy driver. Enter a value from 1-2." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                            case 1:
                                if(t2 < 2 || t2 > 4){
                                    cout << "That capacity is not valid for a basic driver. Enter a value from 2-4." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                            case 2:
                                if(t2 < 5 || t2 > 7){
                                    cout << "That capacity is not valid for a group driver. Enter a value from 5-7." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                            case 3:
                                if(t2 < 7){
                                    cout << "That capacity is not valid for a luxury driver. Enter a value 7 or higher." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                        }
                    }
                    //Update the driver information accordingly
                    d->setCapacity(t2);
                    break;
                case 4:
                    //Prompt user for new handicapped capability
                    cout << "Enter new handicapped capable (0 for no, 1 for yes): ";
                    cin >> t2;
                    while(t2 != 0 && t2 != 1){
                        cout << "Enter new handicapped capable (0 for no, 1 for yes): ";
                        cin >> t2;
                    }

                    //Update the driver information according to user input
                    t3 = t2;
                    d->setHandicappedCapable(t3);
                    break;
                case 5:
                    //Prompt user for new vehicle type
                    cout << "Enter new vehicle type: ";
                    cin.ignore();
                    getline(cin, t1);

                    //Update the driver information according to user input
                    d->setVehicleType(t1);
                    break;
                case 6:
                    //Prompt user for new rating
                    cout << "Enter new rating (0-5): ";
                    cin >> t4;
                    while(t4 < 0 || t4 > 5){
                        cout << "Enter new rating (0-5): ";
                        cin >> t4;
                    }

                    //Update the driver information according to user input
                    d->setRating(t4);
                    break;
                case 7:
                    //Prompt user for new availability
                    cout << "Enter new availability (0 for no, 1 for yes): ";
                    cin >> t2;
                    while(t2 != 0 && t2 != 1){
                        cout << "Enter new availability (0 for no, 1 for yes): ";
                        cin >> t2;
                    }

                    //Update the driver information according to user input
                    t3 = t2;
                    d->setAvailable(t3);
                    break;
                case 8:
                    //Prompt user for new pet policy
                    cout << "Enter new pet policy (0 for not allowed, 1 for allowed): ";
                    cin >> t2;
                    while(t2 != 0 && t2 != 1){
                        cout << "Enter new pet policy (0 for no, 1 for yes): ";
                        cin >> t2;
                    }

                    //Update the driver information according to user input
                    t3 = t2;
                    d->setPetsAllowed(t3);
                    break;
                case 9:
                    //Prompt user for new notes
                    cout << "Enter new notes: ";
                    cin.ignore();
                    getline(cin, t1);

                    //Update the driver information according to user input
                    d->setNotes(t1);
                    break;
                case 10:
                    Luxury *tempL;

                    //Check that the value to edit is valid for driver type
                    if(d->getType() != 3){
                        cout << "You are not a luxury driver, so you do not have an amenities list." << endl;
                        break;
                    }
                    //Prompt user for new amenities
                    cout << "Enter new list of amenities: ";
                    cin.ignore();
                    getline(cin, t1);
                    //Update driver information accordingly
                    tempL = dynamic_cast<Luxury*>(d);
                    tempL->setAmenities(t1);
                    break;
                case 11:
                    //Prompt user for new cargo capacity
                    valid = false;
                    while(!valid){
                        cout << "Enter new cargo capacity: ";
                        cin >> t2;
                        switch(d->getType()){
                            case 0:
                                if(t2 < 1 || t2 > 2){
                                    cout << "That cargo capacity is not valid for an economy driver. Enter a value from 1-2." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                            case 1:
                                if(t2 < 2 || t2 > 4){
                                    cout << "That cargo capacity is not valid for a basic driver. Enter a value from 2-4." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                            case 2:
                                if(t2 < 5 || t2 > 7){
                                    cout << "That cargo capacity is not valid for a group driver. Enter a value from 5-7." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                            case 3:
                                if(t2 < 7){
                                    cout << "That cargo capacity is not valid for a luxury driver. Enter a value 7 or higher." << endl;
                                } else {
                                    valid = true;
                                }
                                break;
                        }
                    }

                    //Update driver information accordingly
                    d->setCargoCapacity(t2);
                    break;
            }
            cout << endl;

            //Store all drivers in driver list in file
            saveDrivers();
            return;
        }
    }
    cout << "Driver Not Found." << endl << endl;
}

void Drivers::deleteDriver(int driverID){

    //Check through every driver in driver list
    for(vector<Driver*>::iterator it = driverList.begin(); it != driverList.end(); it++){

        //If the driver ID matches
        if((**it).getID() == driverID){
            
            //Erase the driver object
            delete *it;
            driverList.erase(it);

            //Decrement driver count
            driverCount--;

            //Store all drivers in driver list in file
            saveDrivers();
            return;
        }
    }

    cout << "Driver not found." << endl << endl;
}

Driver* Drivers::searchForDriver(int driverID){

    //Check through every driver in driver list
    for(int i = 0; i < driverCount; i++){

        //If the driver ID matches
        if(driverList[i]->getID() == driverID){

            //Return the driver object
            return driverList[i];
        }
    }
    return nullptr;
}

void Drivers::printAllDrivers(){

    //Check through every driver in driver list
    if(driverCount == 0){
        cout << "Driver List Empty." << endl << endl;
        return;
    }
    cout << "Drivers:" << endl << endl;
    for(int i = 0; i < driverCount; i++){

        //Print Details for driver
        driverList[i]->printDetails();
        cout << endl;
    }
    
}

void Drivers::printDriverDetails(int driverID){

    //Search For Driver with the given ID number
    Driver *d = searchForDriver(driverID);

    //Print Details for driver
    if(d == nullptr){
        cout << "Driver not found." << endl << endl;
        delete d;
        return;
    }
    cout << "Driver Details:" << endl << endl;
    d->printDetails();
    cout << endl;
}

void Drivers::saveDrivers(){

    //Open file stream
    ofstream fout("drivers.txt");

    fout << noboolalpha;

    //Check through every driver in driver list
    for(int i = 0; i < driverCount; i++){
        Driver *d = driverList[i];

        //Write out ID number, first name, last name, capacity, cargo capacity, handicap capability, vehicle type, rating, availability, pet allowance, notes, and type
        fout << d->getID() << endl << d->getFirstName() << endl << d->getLastName() << endl << d->getCapacity() << endl << d->getCargoCapacity() << endl;
        fout << d->getHandicappedCapable() << endl << d->getVehicleType() << endl << d->getRating() << endl << d->getAvailable() << endl;
        fout << d->getPetsAllowed() << endl << d->getNotes() << endl << d->getType() << endl;
        Luxury* newL;

        //If driver type is luxury
        if(d->getType() == 3){

            //Write out amenities
            newL = dynamic_cast<Luxury*>(d);
            fout << newL->getAmenities() << endl;
        }

        fout << endl;
    }
    fout << boolalpha;

    //Close file stream
    fout.close();
}

void Drivers::loadDrivers(){

    //Open file stream
    ifstream fin("drivers.txt");

    int id, capacity, cargoCapacity, type;
    string firstName, lastName, vehicleType, notes, amenities;
    bool handicappedCapable, available, petsAllowed;
    double rating;

    //While there is input in the file, read in ID number
    while(fin >> id){

        //Read in first name, last name, capacity, cargo capacity, handicap capability, vehicle type, rating, availability, pet allowance, notes, and type
        fin >> firstName >> lastName >> capacity >> cargoCapacity >> handicappedCapable;
        fin.ignore();
        getline(fin, vehicleType);
        fin >> rating >> available >> petsAllowed;
        fin.ignore();
        getline(fin, notes);
        fin >> type;

        //Create and populate a new driver object based on driver type
        Driver *d;
        switch(type){
            case 0:
                d = new Economy(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type);
                break;
            case 1:
                d = new Basic(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type);
                break;
            case 2:
                d = new Group(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type);
                break;
            case 3:
                //If driver type is luxury, read in amenities
                fin.ignore();
                getline(fin, amenities);
                d = new Luxury(id, firstName, lastName, capacity, cargoCapacity, handicappedCapable, vehicleType, rating, available, petsAllowed, notes, type, amenities);
                break;
        }

        //Insert driver object to driver list
        driverList.push_back(d);

        //Increment driver count
        driverCount++;

        //Update current ID
        currentID = max(getCurrentID(), id+1);
    }

    //Close file stream
    fin.close();

}
