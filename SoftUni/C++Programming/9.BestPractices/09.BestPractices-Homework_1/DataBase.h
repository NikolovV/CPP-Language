#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <map>

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

/**
 * Abstract class for database.
 */
class DataBase
{
public:
    virtual ~DataBase(){};
    
    /**
     * Method to add base class reference vehicle object.
     * @param obj - base class reference vehicle object.
     */
    virtual void add_vehicle_to_data_base(const Vehicle &obj) = 0;
    
    /**
     * Access to database. 
     * @return - current database.
     */
    virtual std::map<std::string, Vehicle> get_vehicle_database() const = 0;
};

#endif /* DATABASE_H */