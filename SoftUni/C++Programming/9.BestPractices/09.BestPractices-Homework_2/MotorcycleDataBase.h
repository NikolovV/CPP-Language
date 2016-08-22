#ifndef MOTORCYCLEDATABASE_H
#define MOTORCYCLEDATABASE_H

#include "DataBase.h"

/**
 * Specific database of motorcycles.
 */
class MotorcycleDataBase : public DataBase
{
public:
    ~MotorcycleDataBase(){}
    void add_vehicle_to_data_base(const Vehicle& obj) override
    {
        _motorcycleDataBase.insert(std::make_pair(obj.get_registration_number(), obj));
    }
    
    const std::map<std::string, Vehicle> &get_vehicle_database() const override
    {
        return _motorcycleDataBase;
    }
private:
    std::map<std::string, Vehicle> _motorcycleDataBase;
};

#endif /* MOTORCYCLEDATABASE_H */

