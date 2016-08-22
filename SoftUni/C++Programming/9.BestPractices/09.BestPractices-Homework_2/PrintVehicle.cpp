#include "PrintVehicle.h"

void PrintVehicle::print_vehicle(std::string registration)
{
    std::cout << "<< " << _printer->get_vehicle_database().at(registration).
            get_registration_number() << std::endl;
    std::cout << "<< " << _printer->get_vehicle_database().at(registration).
            get_weight() << std::endl;
    std::cout << "<< " << _printer->get_vehicle_database().at(registration).
            get_seats() << std::endl;
    std::cout << "<< " << _printer->get_vehicle_database().at(registration).
            get_chassis_number() << std::endl;
    std::cout << "<< " << _printer->get_vehicle_database().at(registration).
            get_engine_number() << std::endl;
    std::cout << "<< " << _printer->get_vehicle_database().at(registration).
            get_owner() << std::endl;
}