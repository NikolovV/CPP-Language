#include "PrintVehicle.h"

void PrintVehicle::print_car(std::string registration)
{
    std::cout << "<< " << _printer->get_car_database().at(registration).get_registration_number() << std::endl;
    std::cout << "<< " << _printer->get_car_database().at(registration).get_weight() << std::endl;
    std::cout << "<< " << _printer->get_car_database().at(registration).get_seats() << std::endl;
    std::cout << "<< " << _printer->get_car_database().at(registration).get_chassis_number() << std::endl;
    std::cout << "<< " << _printer->get_car_database().at(registration).get_engine_number() << std::endl;
    std::cout << "<< " << _printer->get_car_database().at(registration).get_owner() << std::endl;
}

void PrintVehicle::print_truck(std::string registration)
{
    std::cout << "<< " << _printer->get_truck_database().at(registration).get_registration_number() << std::endl;
    std::cout << "<< " << _printer->get_truck_database().at(registration).get_weight() << std::endl;
    std::cout << "<< " << _printer->get_truck_database().at(registration).get_seats() << std::endl;
    std::cout << "<< " << _printer->get_truck_database().at(registration).get_chassis_number() << std::endl;
    std::cout << "<< " << _printer->get_truck_database().at(registration).get_engine_number() << std::endl;
    std::cout << "<< " << _printer->get_truck_database().at(registration).get_owner() << std::endl;
}

void PrintVehicle::print_motorcycle(std::string registration)
{
    std::cout << "<< " << _printer->get_motorcycle_database().at(registration).get_registration_number() << std::endl;
    std::cout << "<< " << _printer->get_motorcycle_database().at(registration).get_weight() << std::endl;
    std::cout << "<< " << _printer->get_motorcycle_database().at(registration).get_seats() << std::endl;
    std::cout << "<< " << _printer->get_motorcycle_database().at(registration).get_chassis_number() << std::endl;
    std::cout << "<< " << _printer->get_motorcycle_database().at(registration).get_engine_number() << std::endl;
    std::cout << "<< " << _printer->get_motorcycle_database().at(registration).get_owner() << std::endl;
}
