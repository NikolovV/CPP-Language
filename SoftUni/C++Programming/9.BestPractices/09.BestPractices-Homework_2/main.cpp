#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <string>
#include <unistd.h>

#include "DataBase.h"
#include "CarDataBase.h"
#include "TruckDataBase.h"
#include "MotorcycleDataBase.h"
#include "Search.h"
#include "PrintVehicle.h"

using namespace std;

// Lock the console to synchronize output.
mutex consoleLock;

int main()
{
    /**
     * Some test data.
     */
    //              registr, weight, seats, chassis, engine, owner
    Car honda = Car("A2273MM", 1.0, 5, "123123123123123", "D14A400192", "Martin Kuvandzhiev");
    Car bmw = Car("B1234BN", 1.10, 5, "5314651313", "S6D5FDF3S2", "Kiro Spirov");
    
    Truck uaz = Truck("Z1234ZZ", 2.2, 8, "123456789", "AS54AS23ASD", "Ivan Petaknov");
    Truck gaz = Truck("G6542GZ", 2.1, 5, "654832134", "AS4D321F64F", "Min4o Genov");
    
    Motorcycle motoBmw = Motorcycle("M2134MM", 0.8, 2, "654A56SD4", "HW61GWQ6F65", "Gospodin Gospodinov");
    Motorcycle motoHonda = Motorcycle("M4652SD", 0.7, 3, "AS46F56S5F", "S5D4F5S32FD", "Go6o Rokera");

    /**
     * Add to separate database.
     */
    // Data base of cars.
    shared_ptr<DataBase> carData(new CarDataBase);
    carData->add_vehicle_to_data_base(honda);
    carData->add_vehicle_to_data_base(bmw);
//
    // Data base of trucks.
    shared_ptr<DataBase> truckData(new TruckDataBase);
    truckData->add_vehicle_to_data_base(uaz);
    truckData->add_vehicle_to_data_base(gaz);

    // Data base of motorcycle.
    shared_ptr<DataBase> motorcycleData(new MotorcycleDataBase);
    motorcycleData->add_vehicle_to_data_base(motoBmw);
    motorcycleData->add_vehicle_to_data_base(motoHonda);

    /**
     * User input
     */
    cout << "<< Please enter registration number of a vehicle to search:\n>> ";
    string userInput;
    getline(cin, userInput);
    cout << "<< Searching" << endl;

    // Lambda expression variables for cars.
    // It could be done with C++14 lambda template.
    auto carLambdaExpression = [userInput, carData] ()
    {
        PrintVehicle print(carData);
        // Lock the console, print the information and unlock it.
        consoleLock.lock();
        sleep(1);
        print.print_vehicle(userInput);
        consoleLock.unlock();
    };
    /**
     * Spawn a treads.
     * Note you must pass reference(example below) to search method because it is not static.
     */
    thread carThread(&Search::search_vehicle_in_database, Search(carData),
                     userInput, carLambdaExpression);

    auto truckLambdaExpression = [userInput, truckData] ()
    {
        PrintVehicle print(truckData);
        // Lock the console, print the information and unlock it.
        consoleLock.lock();
        sleep(1);
        print.print_vehicle(userInput);
        consoleLock.unlock();
    };
    thread truck(&Search::search_vehicle_in_database, Search(truckData),
                 userInput, truckLambdaExpression);

    auto motorLambdaExpression = [userInput, motorcycleData] ()
    {
        PrintVehicle print(motorcycleData);
        // Lock the console, print the information and unlock it.
        consoleLock.lock();
        sleep(1);
        print.print_vehicle(userInput);
        consoleLock.unlock();
    };
    thread motorcycle(&Search::search_vehicle_in_database, Search(motorcycleData),
                      userInput, motorLambdaExpression);

    // Joining treads to make main() wait the thread.
    carThread.join();
    truck.join();
    motorcycle.join();
    
    return 0;
}