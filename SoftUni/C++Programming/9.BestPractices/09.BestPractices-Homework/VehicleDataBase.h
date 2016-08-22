#ifndef VEHICLEDATABASE_H
#define VEHICLEDATABASE_H

#include "DataBase.h"

class VehicleDataBase : public DataBase
{
public:
    ~VehicleDataBase(){};
    void add_car_to_data_base(const Vehicle &obj) override;
    void add_truck_to_data_base(const Vehicle& obj) override;
    void add_motor_to_data_base(const Vehicle& obj) override;
    
    std::map<std::string, Vehicle> get_car_database() const override {return _carDataBase;}
    std::map<std::string, Vehicle> get_truck_database() const override {return _truckDataBase;}
    std::map<std::string, Vehicle> get_motorcycle_database() const override {return _motorcycleDataBase;}
private:
    std::map<std::string, Vehicle> _carDataBase;
    std::map<std::string, Vehicle> _truckDataBase;
    std::map<std::string, Vehicle> _motorcycleDataBase;
};

#endif /* VEHICLEDATABASE_H */