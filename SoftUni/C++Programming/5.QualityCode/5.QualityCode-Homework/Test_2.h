#ifndef TEST_2_H
#define TEST_2_H

using namespace std;
#include "Characters.h"
#include "Environment.h"
#include "PhysicControl.h"
using namespace GraphicsFramework;

// Test 2
/**
 * Character name: ElfType_2, ID: 2, weight: 80, Jump speed: 80 km/h
 * @return
 */
Characters *elfType_2 = new Characters(2, "ElfType_2", 80, 80);
/**
 * Environment: name: AmanyarMap, ID: 1, gravity: 5.25
 * @return 
 */
Environment *amanyarMap = new Environment(1, "Amanyar", 5.25);
/**
 * Control the physics based on Character and environment.
 * @return 
 */
PhysicControl test_2_physicControl = PhysicControl(*amanyarMap);
cout << "Maximum jump height: ";
float test_2_maxHeight = test_2_physicControl.calc_max_jump_height(elfType_2);
cout << test_2_maxHeight << " meters" << endl;

float test_2_timeOfJump = test_2_physicControl.time_of_jump(elfType_2);
cout << "Time of jump is: ";
cout << test_2_timeOfJump << " seconds" << endl;
// Use of value 150 (in meters) as a certain heigh, to check if can jump.
float test_2_cetainHeight = 150;
cout << "Is capable of jumping on " << test_2_cetainHeight << " meters: ";
cout <<
test_2_physicControl.is_able_to_jump_on_height(test_2_maxHeight, test_2_cetainHeight)
<< endl;
// End Test 1.

#endif /* TEST_2_H */

