#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define SIZE 3

class Company
{
private:
    string companyName;
    uint16_t employees;
    uint16_t freeWorkSeats;
public:
    Company() :
    companyName("No company"), employees(0), freeWorkSeats(0) {}
    Company(string newCompanyName, uint16_t newEmployees, uint16_t newFreeWorkSeats)
    {
        set_companyName(newCompanyName);
        set_employees(newEmployees);
        set_freeWorkSeats(newFreeWorkSeats);
    }
    ~Company() {/*cout << "Destroying Object of Company." << endl;*/}
    
    void set_companyName(string newCompanyName){companyName = newCompanyName;}
    void set_employees(int newEmployees){employees = newEmployees;}
    void set_freeWorkSeats(int newFreeWorkSeats){freeWorkSeats = newFreeWorkSeats;}
    
    string get_companyName() const {return companyName;}
    uint16_t get_employees() const {return employees;}
    uint16_t get_freeWorkSeats() const {return freeWorkSeats;}
};

class Building
{
private:
    uint16_t floors;
    uint16_t offices;
    bool isThereRestaurant;
public:
    Building() : floors(0), offices(0), isThereRestaurant(0) {}
    Building(uint16_t newFloors, uint16_t newOffices, bool _isThereRestaurant)
    {
        set_floors(newFloors);
        set_offices(newOffices);
        set_restaurant(_isThereRestaurant);
    }
    ~Building() {/*cout << "Destroying Object of Building." << endl;*/}
    
    void set_floors(uint16_t newFloors) {floors = newFloors;}
    void set_offices(uint16_t newOffices) {offices = newOffices;}
    void set_restaurant(bool _isThereRestaurant) {isThereRestaurant = _isThereRestaurant;}
    
    uint16_t get_floors() const {return floors;}
    uint16_t get_offices() const {return offices;}
    bool get_restaurant() const {return isThereRestaurant;}
};

class BusinessPark
{
public:
    Building building;
    Company company;
    
    BusinessPark() : building(), company() {}
    BusinessPark(Building newBuilding, Company newCompany) : 
    building(newBuilding), company(newCompany) {}
    ~BusinessPark () {cout << "Destroying Object of BusinessPark." << endl;}
    
    void set_building (Building newBuilding) {building = newBuilding;}
    void set_company (Company newCompany) {company = newCompany;}

    /* The three function below round the return parameter: 0.5 -> 1; 0.4 -> 0
       because there is no person and a half. :)
     */ 
    uint16_t people_per_floor(const BusinessPark &rBusinessPark);
    uint16_t offices_per_floor(const BusinessPark &rBusinessPark);
    uint16_t people_per_office(const BusinessPark &rBusinessPark);
    
    float high_coef_emp_free_seat(const BusinessPark &rBusinessPark);
    void print_business_info(const BusinessPark &rBusinessPark, string msg, uint16_t value);
    // Overload function to print Highest coefficient.
    void print_business_info(const BusinessPark &rBusinessPark, string msg, float value);
};

int main()
{
    // Allocate heap memory.
    BusinessPark *businessPark = new BusinessPark[SIZE];
    
    // Making the Business park.
    
    // Building 1
    // params Bulding: floors, offices, isThereRestaurant
    businessPark[0].set_building(Building(6, 127, 0)); 
    // params Company: companyName, employees, freeWorkSeats
    businessPark[0].set_company(Company("XYZ industries", 600, 196)); 
    
    // Building 2
    businessPark[1].set_building(Building(8, 210, 1));
    businessPark[1].set_company(Company("Rapid Development Crew", 822, 85));
    
    // Building 3
    businessPark[2].set_building(Building(11, 106, 0));
    businessPark[2].set_company(Company("SoftUni", 200, 60));
    
    // Indexes.
    uint16_t mostEmployees_index, mostFreePlaces_index, highCoefEmpFreeSeat_index;
    uint16_t mostPeoplePerFloor_index, leastPeoplePerFloor_index = 0;
    uint16_t mostOfficesPerFloor_index, leastOfficesPerFloor_index = 0;
    uint16_t mostPeoplePerOffice_index, leastPeoplePerOffice_index = 0;
    // Parameters.
    uint16_t mostEmployees = 0, mostFreePlaces = 0 ;
    uint16_t mostPeoplePerFloor = 0, leastPeoplePerFloor;
    uint16_t mostOfficesPerFloor = 0, leastOfficesPerFloor;
    uint16_t mostPeoplePerOffice = 0, leastPeoplePerOffice;
    
    float highCoefEmpFreeSeat = 0.0;
    
    leastPeoplePerFloor = businessPark->people_per_floor(businessPark[0]);
    leastOfficesPerFloor = businessPark->offices_per_floor(businessPark[0]);
    leastPeoplePerOffice = businessPark->people_per_office(businessPark[0]);
    
    for (int i = 0; i < SIZE; i++)
    {
        if (mostEmployees < businessPark[i].company.get_employees())
        {
            mostEmployees = businessPark[i].company.get_employees();
            mostEmployees_index = i;                    
        }
        if (mostFreePlaces < businessPark[i].company.get_freeWorkSeats())
        {
            mostFreePlaces = businessPark[i].company.get_freeWorkSeats();
            mostFreePlaces_index = i;
        }
        
        float coef = businessPark->high_coef_emp_free_seat(businessPark[i]);
        if (highCoefEmpFreeSeat < coef)
        {
            highCoefEmpFreeSeat = coef;
            highCoefEmpFreeSeat_index = i;
        }
        
        uint16_t tempVal = businessPark->people_per_floor(businessPark[i]);
        if (mostPeoplePerFloor < tempVal)
        {
            mostPeoplePerFloor = tempVal;
            mostPeoplePerFloor_index = i;
        }
        if (leastPeoplePerFloor > tempVal)
        {
            leastPeoplePerFloor = tempVal;
            leastPeoplePerFloor_index = i;
        }
        
        tempVal = businessPark->offices_per_floor(businessPark[i]);
        if (mostOfficesPerFloor < tempVal)
        {
            mostOfficesPerFloor = tempVal;
            mostOfficesPerFloor_index = i;
        }
        if (leastOfficesPerFloor > tempVal)
        {
            leastOfficesPerFloor = tempVal;
            leastOfficesPerFloor_index = i;
        }
        
        tempVal = businessPark->people_per_office(businessPark[i]);
        if (mostPeoplePerOffice < tempVal)
        {
            mostPeoplePerOffice = tempVal;
            mostPeoplePerOffice_index = i;
        }
        if (leastPeoplePerOffice > tempVal)
        {
            leastPeoplePerOffice = tempVal;
            leastPeoplePerOffice_index = i;
        }
    }
    
    // Printing info....
    businessPark->print_business_info(businessPark[mostEmployees_index], 
    "Most employees: ", mostEmployees);
    businessPark->print_business_info(businessPark[mostFreePlaces_index], 
    "Most free places: ", mostFreePlaces);  
    businessPark->print_business_info(businessPark[highCoefEmpFreeSeat_index], 
    "Highest coefficient: ", highCoefEmpFreeSeat*100);  
    businessPark->print_business_info(businessPark[mostPeoplePerFloor_index], 
    "Most people per floor: ", mostPeoplePerFloor);  
    businessPark->print_business_info(businessPark[leastPeoplePerFloor_index], 
    "Least people per floor: ", leastPeoplePerFloor);  
    businessPark->print_business_info(businessPark[mostOfficesPerFloor_index], 
    "Most offices per floor: ", mostOfficesPerFloor);  
    businessPark->print_business_info(businessPark[leastOfficesPerFloor_index], 
    "Least offices per floor: ", leastOfficesPerFloor);  
    businessPark->print_business_info(businessPark[mostPeoplePerOffice_index], 
    "Most people per office: ", mostPeoplePerOffice);  
    businessPark->print_business_info(businessPark[leastPeoplePerOffice_index], 
    "Least people per office: ", leastPeoplePerOffice);  
    cout << endl;
        
    // Free used heap memory.
    delete [] businessPark;
    
    return 0;
}

float BusinessPark::high_coef_emp_free_seat(const BusinessPark &rBusinessPark)
{
    double coef = (double)rBusinessPark.company.get_employees()/
         (rBusinessPark.company.get_employees()+rBusinessPark.company.get_freeWorkSeats());
    return coef;
}
uint16_t BusinessPark::people_per_floor(const BusinessPark &rBusinessPark)
{
    float peoplePerFoloor;
    if (rBusinessPark.building.get_restaurant())
    {
        peoplePerFoloor = (float)rBusinessPark.company.get_employees()/
            (rBusinessPark.building.get_floors() - 1);
    }
    else
    {
        peoplePerFoloor = (float)rBusinessPark.company.get_employees()/
            rBusinessPark.building.get_floors();
    }
    return (uint16_t)round(peoplePerFoloor);
}
uint16_t BusinessPark::offices_per_floor(const BusinessPark &rBusinessPark)
{
    float officePerFloor;
    if (rBusinessPark.building.get_restaurant())
    {
        officePerFloor = (float)rBusinessPark.building.get_offices()/
            (rBusinessPark.building.get_floors() - 1);
    }
    else
    {
        officePerFloor = (float)rBusinessPark.building.get_offices()/
            rBusinessPark.building.get_floors();
    }
    return (uint16_t)round(officePerFloor);
}
uint16_t BusinessPark::people_per_office(const BusinessPark &rBusinessPark)
{
    float peoplePerOffice = (float)rBusinessPark.company.get_employees()/
        rBusinessPark.building.get_offices();
    return (uint16_t)round( peoplePerOffice);
}
void BusinessPark::print_business_info(const BusinessPark &rBusinessPark, string msg, uint16_t value)
{
    cout.fill(' ');
    cout.width(25);
    cout.setf(iostream::left);
    cout << msg;
    cout.width(22);
    cout.setf(iostream::left);
    cout.fill('-');
    cout << rBusinessPark.company.get_companyName();
    cout << " - " << value << endl;
}
void BusinessPark::print_business_info(const BusinessPark &rBusinessPark, string msg, float value)
{
    cout.fill(' ');
    cout.width(25);
    cout.setf(iostream::left);
    cout << msg;
    cout.width(22);
    cout.setf(iostream::left);
    cout.fill('-');
    cout << rBusinessPark.company.get_companyName();
//    cout << " - " << value << '%' << endl;
    printf(" - %.2f%%\n", value);
}