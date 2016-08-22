#ifndef CARDATABASE_H
#define CARDATABASE_H

#include "DataBase.h"

/**
 * Specific database of cars.
 */
class CarDataBase : public DataBase
{
public:
    ~CarDataBase(){}

    void add_vehicle_to_data_base(const Vehicle& obj) override
    {
        _carDataBase.insert(std::make_pair(obj.get_registration_number(), obj));
    }

    const std::map<std::string, Vehicle> &get_vehicle_database() const override
    {
        return _carDataBase;
    }
private:
    std::map<std::string, Vehicle> _carDataBase;
};

#endif /* CARDATABASE_H */