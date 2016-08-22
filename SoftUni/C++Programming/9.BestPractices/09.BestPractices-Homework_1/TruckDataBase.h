#ifndef TRUCKDATABASE_H
#define TRUCKDATABASE_H

#include "DataBase.h"

/**
 * Specific database of trucks.
 */
class TruckDataBase : public DataBase
{
public:
    ~TruckDataBase(){};
    void add_vehicle_to_data_base(const Vehicle& obj) override
    {
        _truckDataBase.insert(std::pair<std::string, Vehicle>
                          (obj.get_registration_number(), obj));
    }
    
    std::map<std::string, Vehicle> get_vehicle_database() const override
    {
        return _truckDataBase;
    }
private:
    std::map<std::string, Vehicle> _truckDataBase;
};

#endif /* TRUCKDATABASE_H */