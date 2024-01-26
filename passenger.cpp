#include "passenger.h"
using namespace std;

Passenger::Passenger(){
    name = "";
    id = 0;
    paymentPreference = pay(0);
    handicapped = false;;
    requiredRating = 0.0;
    hasPets = false;
}

Passenger::Passenger(string newName, int newID, pay newPP, bool newH, double newRR, bool newHP){
    name = newName;
    id = newID;
    paymentPreference = newPP;
    handicapped = newH;;
    requiredRating = newRR;
    hasPets = newHP;
}

void Passenger::printDetails(){

    //Print name of passenger
    cout << "Name: " << name << endl;

    //Print ID of passenger
    cout << "ID: " << id << endl;

    //Print payment preference of passenger
    cout << "Payment Preference: ";
    switch(paymentPreference){
        case 0:
            cout << "Cash" << endl;
            break;
        case 1:
            cout << "Credit" << endl;
            break;
        case 2:
            cout << "Debit" << endl;
            break;
    } 

    //Print handicapped for passenger
    cout << "Handicapped: " << handicapped << endl;

    //Print required rating of passenger
    cout << "Required Rating: " << requiredRating << endl;

    //Print has pets for passenger
    cout << "Has Pets: " << hasPets << endl;
    
}

ostream& operator<<(ostream& fout, Passenger& p){
    //Read out id, name, payment preference, handicapped, required rating, and has pets for passenger
    fout << p.id << endl << p.name << endl << p.paymentPreference << endl << p.handicapped << endl << p.requiredRating << endl << p.hasPets << endl << endl;

    //Return the stream
    return fout;
}

istream& operator>>(istream& fin, Passenger& p){
    //Read in id of passenger
    fin >> p.id;

    //Read in name of passenger
    fin.ignore();
    getline(fin, p.name);

    //Read in payment preference of passenger
    int i;
    fin >> i;
    p.paymentPreference = pay(i);

    //Read in handicapped, required rating, and has pets for passenger
    fin >> p.handicapped >> p.requiredRating >> p.hasPets;

    //Return the stream
    return fin;
}