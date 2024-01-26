#include <iostream>
#include "rides.h"
using namespace std;

/*  Name: Cathy Du
    Email: cathydu@my.unt.edu

    Description: This program is created to implement a system to schedule drivers and passengers for rides. 
    Three classes, Driver, Passenger, and Ride, are used to represent the different entities involved in the system.
    Driver now has four subclasses: Economy, Basic, Group, and Luxury drivers.
    Three other classes, Drivers, Passengers, and Rides, are used to represent collections of the entities.
    A menu system is provided for the user to modify and access information about the involved entities.
    Methods are provided to facilitate transactions between entities.

*/

int main(){
    cout << boolalpha;

    extern Passengers myPassengers;
    extern Drivers myDrivers;
    Rides myRides;

    myPassengers.loadPassengers();
    myDrivers.loadDrivers();
    myRides.loadRides();

    cout << "CSCE 1040.002\nHomework 4\nCathy Du\ncathydu@my.unt.edu\n\n";

    int collect = -1;
    while(collect != 0){
        cout << "Drivers - 1\nPassengers - 2\nRides - 3\nQuit - 0" << endl << endl;
        cout << "Enter your choice (0-3): ";
        cin >> collect;
        while(collect < 0 || collect > 3){
            cout << "Ener your choice (0-3): ";
            cin >> collect;
        }

        cout << endl;
        int choice = 0;
        int d, p, r, s;
        switch(collect){
            case 1:
                cout << "Add Driver - 1\nEdit Driver - 2\nDelete Driver - 3\nPrint All Drivers - 4\nPrint Driver Details - 5" << endl << endl;
                cout << "Enter your choice (1-5): ";
                cin >> choice;
                while(choice < 1 || choice > 5){
                    cout << "Enter your choice (1-5): ";
                    cin >> choice;
                }
                cout << endl;

                switch(choice){
                    case 1:
                        myDrivers.addDriver();
                        break;
                    case 2:
                        myDrivers.editDriver();
                        break;
                    case 3:
                        cout << "Enter Driver ID (6 digits): ";
                        cin >> d;
                        while(d < 100000 || d > 999999){
                            cout << "Enter Driver ID (6 digits): ";
                            cin >> d;
                        }
                        cout << endl;
                        myDrivers.deleteDriver(d);
                        break;
                    case 4:
                        myDrivers.printAllDrivers();
                        break;
                    case 5:
                        cout << "Enter Driver ID (6 digits): ";
                        cin >> d;
                        while( d < 100000 || d > 999999){
                            cout << "Enter Driver ID (6 digits): ";
                            cin >> d;
                        }
                        cout << endl;
                        myDrivers.printDriverDetails(d);
                        break;
                }
                break;
            case 2:
                cout << "Add Passenger - 1\nEdit Passenger - 2\nDelete Passenger - 3\nPrint All Passengers - 4\nPrint Passenger Details - 5" << endl << endl;
                cout << "Enter your choice (1-5): ";
                cin >> choice;
                while(choice < 1 || choice > 5){
                    cout << "Enter your choice (1-5): ";
                    cin >> choice;
                }
                cout << endl;

                switch(choice){
                    case 1:
                        myPassengers.addPassenger();
                        break;
                    case 2:
                        myPassengers.editPassenger();
                        break;
                    case 3:
                        cout << "Enter Passenger ID (6 digits): ";
                        cin >> p;
                        while(p < 100000 || p > 999999){
                            cout << "Enter Passenger ID (6 digits): ";
                            cin >> p;
                        }
                        cout << endl;
                        myPassengers.deletePassenger(p);
                        break;
                    case 4:
                        myPassengers.printAllPassengers();
                        break;
                    case 5:
                        cout << "Enter Passenger ID (6 digits): ";
                        cin >> p;
                        while(p < 100000 || p > 999999){
                            cout << "Enter Passenger ID (6 digits): ";
                            cin >> p;
                        }
                        cout << endl;
                        myPassengers.printPassengerDetails(p);
                        break;
                }
                break;
            case 3:
                cout << "Add Ride - 1\nEdit Ride - 2\nDelete Ride - 3\nPrint All Rides - 4\nPrint Ride Details - 5\nPrint All Rides With Driver - 6\n";
                cout << "Print All Rides With Passenger - 7\nPrint All Rides With Status - 8\nUpdate Ride Status - 9\nDelete Cancelled Rides - 10\nDelete Completed Rides - 11\n";
                cout << "Print Driver Schedule - 12\nPrint Passenger Schedule - 13" << endl << endl;
                cout << "Enter your choice (1-13): ";
                cin >> choice;
                while(choice < 1 || choice > 13){
                    cout << "Enter your choice (1-13): ";
                    cin >> choice;
                }
                cout << endl;

                switch(choice){
                    case 1:
                        myRides.addRide();
                        break;
                    case 2:
                        myRides.editRide();
                        break;
                    case 3:
                        cout << "Enter Ride ID (8 digits): ";
                        cin >> r;
                        while(r < 10000000 || r > 99999999){
                            cout << "Enter Ride ID (8 digits): ";
                            cin >> r;
                        }
                        cout << endl;
                        myRides.deleteRide(r);
                        break;
                    case 4:
                        myRides.printAllRides();
                        break;
                    case 5:
                        cout << "Enter Ride ID (8 digits): ";
                        cin >> r;
                        while(r < 10000000 || r > 99999999){
                            cout << "Enter Ride ID (8 digits): ";
                            cin >> r;
                        }
                        cout << endl;
                        myRides.printRideDetails(r);
                        break;
                    case 6:
                        cout << "Enter Driver ID (6 digits): ";
                        cin >> d;
                        while(d < 100000 || d > 999999){
                            cout << "Enter Driver ID (6 digits): ";
                            cin >> d;
                        }
                        cout << endl;
                        myRides.printAllRidesWithDriver(d);
                        break;
                    case 7:
                        cout << "Enter Passenger ID (6 digits): ";
                        cin >> p;
                        while(p < 100000 || p > 999999){
                            cout << "Enter Passenger ID (6 digits): ";
                            cin >> p;
                        }
                        cout << endl;
                        myRides.printAllRidesWithPassenger(p);
                        break;
                    case 8:
                        cout << "Enter Status (0 for active, 1 for completed, 2 for cancelled): ";
                        cin >> s;
                        while(s != 0 && s != 1 && s != 2){
                            cout << "Enter Status (0 for active, 1 for completed, 2 for cancelled): ";
                            cin >> s;
                        }
                        cout << endl;
                        myRides.printAllRidesWithStatus(stat(s));
                        break;
                    case 9:
                        myRides.updateRideStatus();
                        break;
                    case 10:
                        myRides.deleteCancelledRides();
                        break;
                    case 11:
                        myRides.deleteCompletedRides();
                        break;
                    case 12:
                        cout << "Enter Driver ID (6 digits): ";
                        cin >> d;
                        while(d < 100000 || d > 999999){
                            cout << "Enter Driver ID (6 digits): ";
                            cin >> d;
                        }
                        cout << endl;
                        myRides.printDriverSchedule(d);
                        break;
                    case 13:
                        cout << "Enter Passenger ID (6 digits): ";
                        cin >> p;
                        while(p < 100000 || p > 999999){
                            cout << "Enter Passenger ID (6 digits): ";
                            cin >> p;
                        }
                        cout << endl;
                        myRides.printPassengerSchedule(p);
                        break;
                }
                break;
        }
    }

    myPassengers.savePassengers();
    myDrivers.saveDrivers();
    myRides.saveRides();
}
