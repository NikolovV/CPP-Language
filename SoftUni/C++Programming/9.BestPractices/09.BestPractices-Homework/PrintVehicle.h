#ifndef PRINTVEHICLE_H
#define PRINTVEHICLE_H

#include <memory>

#include "DataBase.h"

class PrintVehicle
{
public:
    PrintVehicle(std::shared_ptr<DataBase> printer){_printer = printer;};
    ~PrintVehicle(){};
    void print_car(std::string registration);
    void print_truck(std::string registration);
    void print_motorcycle(std::string registration);
private:
    std::shared_ptr<DataBase> _printer;
};


#endif /* PRINTVEHICLE_H */