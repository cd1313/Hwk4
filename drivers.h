#ifndef DRIVERS_H
#define DRIVERS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "driver.h"
#include "economy.h"
#include "basic.h"
#include "group.h"
#include "luxury.h"
using namespace std;

class Drivers {
    public:
        Drivers() {driverCount = 0;};
        void addDriver();
        void editDriver();
        void deleteDriver(int driverID);
        Driver* searchForDriver(int driverID);
        void printAllDrivers();
        void printDriverDetails(int driverID);
        int getDriverCount() {return driverCount;};
        void setDriverCount(int newDC) {driverCount = newDC;};
        int getCurrentID() {return currentID;};
        void setCurrentID(int newCurrentID) { currentID = newCurrentID;};
        void saveDrivers();
        void loadDrivers();
        
    private:
        vector<Driver*> driverList;
        int driverCount;
        static int currentID;
};

#endif