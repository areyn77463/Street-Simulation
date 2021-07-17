#ifndef ROAD_H
#define ROAD_H
//#include <windows.h>
#include <iostream>

using namespace std;

struct Road{
    //public:
        Road();
        int coinToss();

        bool CarOnRoad(int i);
        void AdjustLight(int index);

        bool CarOnLeft(int carIndex);
        /// below are the two member function declerations
        void MoveCars();
        void GenerateCars();

        int GetCarX(int i);
        int GetCarY(int i);
        char GetLight();

        int  cars[2][10];

        char light;
        int numCars;

};

#endif // ROAD_H
