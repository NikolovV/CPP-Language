#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <string>
#include <unistd.h>

#include "DataBase.h"
#include "VehicleDataBase.h"
#include "Search.h"
#include "PrintVehicle.h"

using namespace std;

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
     * Add to data base.
     */
    shared_ptr<DataBase> vehicleData(new VehicleDataBase);
    vehicleData->add_car_to_data_base(honda);
    vehicleData->add_car_to_data_base(bmw);
    vehicleData->add_truck_to_data_base(uaz);
    vehicleData->add_truck_to_data_base(gaz);
    vehicleData->add_motor_to_data_base(motoBmw);
    vehicleData->add_motor_to_data_base(motoHonda);
    
    /**
     * User input
     */
    cout << "<< Please enter registration number of a vehicle to search:\n>> ";
    string userInput;
    getline(cin, userInput);
    cout << "<< Searching" << endl;
    
    PrintVehicle print(vehicleData);
    
    // Lambda expression variables for different vehicles.
    auto carLambdaExpression = [&] ()
    {
        // Lock the console, print the information and unlock it.
        consoleLock.lock();
        print.print_car(userInput);
        sleep(1);
        consoleLock.unlock();
    };
    /**
     * Spawn a treads.
     * Note you must pass reference(example below) to search method because it is not static.
     */
    thread car(&Search::search_car_in_database, Search(vehicleData), userInput, carLambdaExpression);
    
    auto truckLambdaExpression = [&] ()
    {
        consoleLock.lock();
        print.print_truck(userInput);
        sleep(1);
        consoleLock.unlock();
    };
    thread truck(&Search::search_truck_in_database, Search(vehicleData), userInput, truckLambdaExpression);
    
    auto motorLambdaExpression = [&] ()
    {   
        consoleLock.lock();
        print.print_motorcycle(userInput);
        sleep(1);
        consoleLock.unlock();
    };
    thread motorcycle(&Search::search_motorcycle_in_database, Search(vehicleData), userInput, motorLambdaExpression);

    // Joining treads to make main() wait the thread.
    car.join();
    truck.join();
    motorcycle.join();

    return 0;
}