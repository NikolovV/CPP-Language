#include <iostream>
#include <string>

using namespace std;
#include "Characters.h"
#include "Environment.h"
#include "PhysicControl.h"
using namespace GraphicsFramework;
/**
 * NOTE: Maybe the formulas are not so correct. The base idea is class design
 * and implementation.
 * @return 
 */
void print_formater(string msg);

int main()
{
    print_formater("Test 1: OrkType_1 on MordorMap");
    // Test 1
    /**
     * Character name: OrkType_1, ID: 1, weight: 120, Jump speed: 50 km/h
     * @return
     */
    Characters *orkType_1 = new Characters(1, "OrkType_1", 120, 50);
    /**
     * Environment: name: MordorMap, ID: 123, gravity: 9.81
     * @return 
     */
    Environment *mordorMap = new Environment(123, "MordorMap", 9.81);
    /**
     * Control the physics based on Character and environment.
     * @return 
     */
    PhysicControl physicControl = PhysicControl(*mordorMap);
    cout << "Maximum jump height: ";
    float maxHeight = physicControl.calc_max_jump_height(orkType_1);
    cout << maxHeight << " meters" << endl;

    float timeOfJump = physicControl.time_of_jump(orkType_1);
    cout << "Time of jump is: ";
    cout << timeOfJump << " seconds" << endl;
    // Use of value 15 (in meters) as a certain heigh, to check if can jump.
    float cetainHeight = 15;
    cout << "Is capable of jumping on " << cetainHeight << " meters: ";
    cout << physicControl.is_able_to_jump_on_height(maxHeight, cetainHeight) << endl;
    
    // End Test 1.
    print_formater("End Test 1");
    
    cout << endl;
    
    print_formater("Test 2: ElfType_2 on AmanyarMap");
#include "Test_2.h"
    print_formater("End Test 2");
    
    cout << endl;
    
    print_formater("Test 3: OrkTupe_1 on AmanyarMap");
#include "Test_3.h"
    print_formater("End Test 3");
   
     cout << endl;
     
    print_formater("Test 4: ElfType_2 on MordorMap");
#include "Test_4.h"
    print_formater("End Test 4");
    
    // Free heap.
    delete orkType_1;
    delete elfType_2;
    delete mordorMap;
    delete amanyarMap;
    
    return 0;
}

void print_formater(string msg)
{
    cout << "*********************************************************" << endl;
    cout << msg << endl;
    cout << "*********************************************************" << endl;
}