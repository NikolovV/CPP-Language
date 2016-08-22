#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <map>

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

class DataBase
{
public:
    virtual ~DataBase(){};
    
    virtual void add_car_to_data_base(const Vehicle &obj) = 0;
    virtual void add_truck_to_data_base(const Vehicle &obj) = 0;
    virtual void add_motor_to_data_base(const Vehicle &obj) = 0;
    
    virtual std::map<std::string, Vehicle> get_car_database() const = 0;
    virtual std::map<std::string, Vehicle> get_truck_database() const = 0;
    virtual std::map<std::string, Vehicle> get_motorcycle_database() const = 0;
};

#endif /* DATABASE_H */