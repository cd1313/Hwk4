#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <iostream>
using namespace std;

enum pay {Cash = 0, Credit = 1, Debit = 2};

class Passenger {
    public:
        Passenger();
        Passenger(string newName, int newID, pay newPP, bool newH, double newRR, bool newHP);
        string getName() {return name;};
        void setName(string newName) {name = newName;};
        int getID() {return id;};
        void setID(int newID) {id = newID;};
        pay getPaymentPreference() {return paymentPreference;};
        void setPaymentPreference(pay newPP) {paymentPreference = newPP;};
        bool getHandicapped() {return handicapped;};
        void setHandicapped(bool newH) {handicapped = newH;};
        double getRequiredRating() {return requiredRating;};
        void setRequiredRating(double newRR) {requiredRating = newRR;};
        bool getHasPets() {return hasPets;};
        void setHasPets(bool newHP) {hasPets = newHP;};
        void printDetails();
        friend ostream& operator<<(ostream& fout, Passenger& p); 
        friend istream& operator>>(istream& fin, Passenger& p); 

    private:
        string name;
        int id;
        pay paymentPreference;
        bool handicapped;
        double requiredRating;
        bool hasPets;
        
};

#endif