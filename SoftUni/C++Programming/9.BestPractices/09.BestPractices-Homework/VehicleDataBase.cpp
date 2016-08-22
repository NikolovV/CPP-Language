#include "VehicleDataBase.h"

void VehicleDataBase::add_car_to_data_base(const Vehicle &obj)
{
    _carDataBase.insert(std::pair<std::string, Vehicle>
                        (obj.get_registration_number(), obj));
}

void VehicleDataBase::add_truck_to_data_base(const Vehicle &obj)
{
    _truckDataBase.insert(std::pair<std::string, Vehicle>
                          (obj.get_registration_number(), obj));
}

void VehicleDataBase::add_motor_to_data_base(const Vehicle &obj)
{
    _motorcycleDataBase.insert(std::pair<std::string, Vehicle>
                               (obj.get_registration_number(), obj));
}