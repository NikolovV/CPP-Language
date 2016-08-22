#ifndef PRINTVEHICLE_H
#define PRINTVEHICLE_H

#include <memory>

#include "DataBase.h"
/**
 * Print given database vehicle.
 * @param printer - shared pointer to abstract database.
 */
class PrintVehicle
{
public:
    PrintVehicle(std::shared_ptr<DataBase> printer) : _printer(printer) {}
    ~PrintVehicle(){};
    /**
     * Print specific information about vehicle.
     * @param registration - take string parameter represent vehicle registration number.
     */
    void print_vehicle(std::string registration);
private:
    std::shared_ptr<DataBase> _printer;
};

#endif /* PRINTVEHICLE_H */