#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>
#include <sys/unistd.h>
#include <vector>

#define  CAPACITY_OF_DISCO 100

using namespace std;
int numberOfPeopleWaintingToBeChecked = 0;
int numberOfFreeSpotsForPeople = CAPACITY_OF_DISCO;
unsigned long secondsAfterStart = 0;
const int numberOfFaceControlEmployees = 1;
unsigned long long ticksOfProcessorOnStart = 0;
bool programMustEnd = false;
mutex faceCheckLock;
mutex exitLock;
mutex vectorLock;

std::vector<std::thread> vectorOfThreads;

void faceCheck()
{
    while (numberOfFreeSpotsForPeople < 1)
    {
        usleep(100);
    }

    faceCheckLock.lock();
    numberOfPeopleWaintingToBeChecked -= 1;
    numberOfFreeSpotsForPeople -= 1;
    usleep(3000);
    faceCheckLock.unlock();
}

//void exitTheDisco()
//{
//    exitLock.lock();
//    numberOfFreeSpotsForPeople += 1;
//    usleep(10000);
//    exitLock.unlock();
//}

void incommingPeople()
{
    while (programMustEnd == false)
    {
        usleep(60000);
        numberOfPeopleWaintingToBeChecked += ((rand() % 5) + 1);
    }

}

void outgoingPeople()
{
    while ((float)(clock() - ticksOfProcessorOnStart)/ CLOCKS_PER_SEC < 0.54) 
    {
        usleep(1000);
    }

    while (programMustEnd == false)
    {
        usleep(60000);
        numberOfFreeSpotsForPeople += ((rand() % 9) + 2);
    }

}

int main()
{
    numberOfPeopleWaintingToBeChecked = 50;
    ticksOfProcessorOnStart = clock();
    thread incoming = thread(incommingPeople);
    thread outgoing = thread(outgoingPeople);

    while (programMustEnd == false)
    {
        while (numberOfPeopleWaintingToBeChecked > 0)
        {
            vectorLock.lock();
            vectorOfThreads.push_back(std::thread(faceCheck));
            vectorLock.unlock();
        }
        if (numberOfPeopleWaintingToBeChecked == 0 &&
                numberOfFreeSpotsForPeople >= CAPACITY_OF_DISCO)
        {
            programMustEnd = true;
        }
    }

    for (int i = 0; i < vectorOfThreads.size(); i++)
    {
        vectorOfThreads[i].join();
    }
    incoming.join();
    outgoing.join();
    
    cout << (double)(clock() - ticksOfProcessorOnStart/CLOCKS_PER_SEC) << endl;
    return 0;
}