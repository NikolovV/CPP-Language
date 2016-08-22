#ifndef TEST_3_H
#define TEST_3_H

using namespace std;
#include "Characters.h"
#include "Environment.h"
#include "PhysicControl.h"
using namespace GraphicsFramework;

cout << "Maximum jump height: ";
// Set physic control to new environment amanyarMap.
physicControl.set_environment(amanyarMap);
float test_3_maxHeight = physicControl.calc_max_jump_height(orkType_1);
cout << test_3_maxHeight << " meters" << endl;

float test_3_timeOfJump = physicControl.time_of_jump(orkType_1);
cout << "Time of jump is: ";
cout << test_3_timeOfJump << " seconds" << endl;
// Use of value 5000 (in meters) as a certain heigh, to check if can jump.
float test_3_cetainHeight = 5000;
cout << "Is capable of jumping on " << test_3_cetainHeight << " meters: ";
cout <<
physicControl.is_able_to_jump_on_height(test_3_maxHeight, test_3_cetainHeight)
<< endl;

#endif /* TEST_3_H */