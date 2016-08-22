#ifndef TEST_4_H
#define TEST_4_H

using namespace std;
#include "Characters.h"
#include "Environment.h"
#include "PhysicControl.h"
using namespace GraphicsFramework;

cout << "Maximum jump height: ";
// Set physic control to new environment amanyarMap.
physicControl.set_environment(mordorMap);
float test_4_maxHeight = physicControl.calc_max_jump_height(elfType_2);
cout << test_4_maxHeight << " meters" << endl;

float test_4_timeOfJump = physicControl.time_of_jump(elfType_2);
cout << "Time of jump is: ";
cout << test_4_timeOfJump << " seconds" << endl;
// Use of value 10000 (in meters) as a certain heigh, to check if can jump.
float test_4_cetainHeight = 10000;
cout << "Is capable of jumping on " << test_4_cetainHeight << " meters: ";
cout <<
physicControl.is_able_to_jump_on_height(test_4_maxHeight, test_4_cetainHeight)
<< endl;

#endif /* TEST_4_H */