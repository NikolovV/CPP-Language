#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
public:
    Vehicle(std::string reg, float weight, short seats, std::string chassis, 
            std::string engine, std::string owner) : 
    _regsitrationNumber(reg), _weightInTones(weight), _numberOfSeats(seats),
            _chassisNumber(chassis), _engineNumber(engine), _owner(owner)
    {};
    virtual ~Vehicle(){};
    
    std::string get_registration_number()const {return _regsitrationNumber;}
    float get_weight()const {return _weightInTones;}
    short get_seats()const {return _numberOfSeats;}
    std::string get_chassis_number()const {return _chassisNumber;}
    std::string get_engine_number()const {return _engineNumber;}
    std::string get_owner()const {return _owner;}
private:
    std::string _regsitrationNumber;
    float _weightInTones;
    short _numberOfSeats;
    std::string _chassisNumber;
    std::string _engineNumber;
    std::string _owner;
};

#endif /* VEHICLE_H */