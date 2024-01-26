#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "passengers.h"
using namespace std;

int Passengers::currentID = 100000;

void Passengers::addPassenger(){
    string name;
    pay paymentPreference;
    int id;
    bool handicapped, hasPets;
    int temp;
    double requiredRating;

    //Auto assign ID number and increment current ID
    id = currentID;
    currentID++;

    //Prompt user for name
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    //Prompt user for payment preference
    cout << "Enter preferred payment method (0 for cash, 1 for credit, 2 for debit): ";
    cin >> temp;
    while(temp < 0 || temp > 2){
        cout << "Enter preferred payment method (0 for cash, 1 for credit, 2 for debit): ";
        cin >> temp;
    }
    paymentPreference = pay(temp);

    //Prompt user for handicapped status
    cout << "Enter handicapped status (0 for not handicapped, 1 for handicapped): ";
    cin >> temp;
    while (temp != 1 && temp != 0){
        cout << "Enter handicapped status (0 for not handicapped, 1 for handicapped): ";
        cin >> temp;
    }
    handicapped = temp;

    //Prompt user for required rating
    cout << "Enter default required rating (0-5): ";
    cin >> requiredRating;
    while(requiredRating < 0 || requiredRating > 5){
        cout << "Enter default required rating (0-5): ";
        cin >> requiredRating;
    }

    //Prompt user for pet ownership
    cout << "Enter pet ownership status (0 for no pets, 1 for has pets): ";
    cin >> temp;
    while (temp != 1 && temp != 0){
        cout << "Enter pet ownership status (0 for no pets, 1 for has pets): ";
        cin >> temp;
    }
    hasPets = temp;
    cout << endl;

    //Create and populate a new passenger object
    Passenger tempPassenger(name, id, paymentPreference, handicapped, requiredRating, hasPets);

    //Add passenger object to passenger list
    passengerList.push_back(tempPassenger);

    //Increment passenger count
    passengerCount++;

    //Store all passengers in passenger list in file
    savePassengers();
}

void Passengers::editPassenger(){
    int passengerID, choice;

    //Prompt user for ID number
    cout << "Enter Passenger ID (6 digits): ";
    cin >> passengerID;
    while(passengerID < 100000 || passengerID > 999999){
        cout << "Enter Passenger ID (6 digits): ";
        cin >> passengerID;
    }

    //Prompt user for data member to edit
    cout << "\nChoose Value to Edit:" << endl << endl;
    cout << "Name - 1\nPayment Preference - 2\nHandicapped - 3\nRequired Rating - 4\nHas Pets - 5\n";
    cout << "\nEnter choice (1-5): ";
    cin >> choice;
    while(choice < 1 || choice > 5){
        cout << "Enter choice (1-5): ";
        cin >> choice;
    }
    cout << endl;

    //Check through every passenger in passenger list
    for(int i = 0; i < passengerCount; i++){

        //If the passenger ID matches
        if(passengerList[i].getID() == passengerID){
            Passenger &p = passengerList[i];
            string name;
            bool handicapped, hasPets;
            int temp;
            double requiredRating;
            switch(choice){
                case 1:
                    //Prompt user for new name
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, name);

                    //Update the passenger information according to user input
                    p.setName(name);
                    break;
                case 2:
                    //Prompt user for new preferred payment method
                    cout << "Enter new preferred payment method (0 for cash, 1 for credit, 2 for debit): ";
                    cin >> temp;
                    while(temp < 0 || temp > 2){
                        cout << "Enter preferred payment method (0 for cash, 1 for credit, 2 for debit): ";
                        cin >> temp;
                    }

                    //Update the passenger information according to user input
                    p.setPaymentPreference(pay(temp));
                    break;
                case 3:
                    //Prompt user for new handicapped status
                    cout << "Enter new handicapped status (0 for not handicapped, 1 for handicapped): ";
                    cin >> temp;
                    while (temp != 1 && temp != 0){
                        cout << "Enter handicapped status (0 for not handicapped, 1 for handicapped): ";
                        cin >> temp;
                    }
                    handicapped = temp;

                    //Update the passenger information according to user input
                    p.setHandicapped(handicapped);
                    break;
                case 4:
                    //Prompt user for new required rating
                    cout << "Enter new required rating (0-5): ";
                    cin >> requiredRating;
                    while(requiredRating < 0 || requiredRating > 5){
                        cout << "Enter default required rating (0-5): ";
                        cin >> requiredRating;
                    }

                    //Update the passenger information according to user input
                    p.setRequiredRating(requiredRating);
                    break;
                case 5:
                    //Prompt user for new pet ownership status
                    cout << "Enter new pet ownership status (0 for no pets, 1 for has pets): ";
                    cin >> temp;
                    while (temp != 1 && temp != 0){
                        cout << "Enter pet ownership status (0 for no pets, 1 for has pets): ";
                        cin >> temp;
                    }
                    hasPets = temp;

                    //Update the passenger information according to user input
                    p.setHasPets(hasPets);
                    break;
            }
            cout << endl;

            //Store all passengers in passenger list in file
            savePassengers();
            return;
        }
    }

    cout << "Passenger Not Found." << endl << endl;
}

void Passengers::deletePassenger(int passengerID){

    //Check through every passenger in passenger list
    for(int i = 0; i < passengerCount; i++){

        //If the passenger ID matches
        if(passengerList[i].getID() == passengerID){

            //Erase the passenger object
            passengerList.erase(passengerList.begin()+i);

            //Decrement passenger count
            passengerCount--;

            //Store all passengers in passenger list in file
            savePassengers();
            return;
        }
    }
    cout << "Passenger not found." << endl << endl;
}

Passenger* Passengers::searchForPassenger(int passengerID){

    //Check through ever passenger in passenger list
    for(int i = 0; i < passengerCount; i++){

        //If passenger the ID matches
        if(passengerList[i].getID() == passengerID){

            //Return the passenger object
            return &passengerList[i];
        }
    }
    return nullptr;
}

void Passengers::printAllPassengers(){

    //Check through every passenger in passenger list
    if(passengerCount == 0){
        cout << "Passenger List Empty." << endl << endl;
        return;
    }
    cout << "Passengers:" << endl << endl;
    for(int i = 0; i < passengerCount; i++){

        //Print Details for passenger
        passengerList[i].printDetails();
        cout << endl;
    }
}

void Passengers::printPassengerDetails(int passengerID){    

    //Search For Passenger with the given ID number
    Passenger *p = searchForPassenger(passengerID);

    //Print Details for passenger
    if(p == nullptr){
        cout << "Passenger Not Found." << endl << endl;
        delete p;
        return;
    }
    cout << "Passenger Details:" << endl << endl;
    p->printDetails();
    cout << endl;
}

void Passengers::savePassengers(){

    //Open file stream
    ofstream fout("passengers.txt");

    fout << noboolalpha;

    //Check through every passenger in passenger list
    for(int i = 0; i < passengerCount; i++){
        Passenger p = passengerList[i];

        //Write out passenger
        fout << p;
    }
    fout << boolalpha;

    //Close file stream
    fout.close();
}

void Passengers::loadPassengers(){

    //Open file stream
    ifstream fin("passengers.txt");

    Passenger p;
    //While there is input in the file, read in passenger
    while(fin >> p){

        //Add passenger object to passenger list
        passengerList.push_back(p);

        //Increment passenger count
        passengerCount++;

        //Update current ID
        currentID = max(getCurrentID(), p.getID()+1);
    }

    //Close file stream
    fin.close();
}