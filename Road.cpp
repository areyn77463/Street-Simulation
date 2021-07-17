#include "Road.h"


/// this is the constructor
/// it is used to initialize the structure variables
/// if they are not given values elsewhere
Road::Road(){
    cars[0][0]=1;
    cars[0][1]=1;
    cars[0][2]=1;
    cars[0][3]=1;
    cars[0][4]=2;
    cars[0][5]=2;
    cars[0][6]=2;
    cars[0][7]=3;
    cars[0][8]=3;
    cars[0][9]=3;
    cars[1][0]=39;
    cars[1][1]=37;
    cars[1][2]=35;
    cars[1][3]=32;
    cars[1][4]=39;
    cars[1][5]=37;
    cars[1][6]=35;
    cars[1][7]=39;
    cars[1][8]=37;
    cars[1][9]=35; // initialize
    light = 'G';
    numCars = 10;


}
/// this boolean function is meant to detect whether or not
/// a car is on the road
bool Road::CarOnRoad(int i){
    for(int j=0; j<numCars; j++){
        if(cars[0][i]>-1 && cars[1][i]>-1)
            return true;
    }
  return false;
}

int Road::coinToss(){
    return rand() % 10;
}

bool Road::CarOnLeft(int carIndex){
    int r = cars[0][carIndex];
    int c = cars[1][carIndex];
    for(int i=0; i<numCars; i++){
        if(cars[0][i] == r && cars[1][i]+1 == c)
            return true;
    }
    return false;
}
/// this void function is meant to adjust the light every 50
/// iterations of the index
void Road::AdjustLight(int index){
    //std::cout<< index;    /// this statement was to keep track of the index
    int i=index/50; //flag
    if(i%2==0)
        light='R';
    else
        light='G';

    //std::cout << endl<< i; /// this line was used to check
                             // the flag count for the modulus
}

char Road::GetLight(){
   return light;
}

int Road::GetCarX(int i){
    return cars[0][i];
}

int Road::GetCarY(int i){
    return cars[1][i];
}

/// this function is meant to move the cars one space to the left
/// if the light is green and one space to the left if it is before or
/// after the light when the light is red. If the light is red the cars will
/// stop and stack
void Road::MoveCars()
{
    if(light=='G'){
    for(int j=0;j<numCars; j++)
        if(CarOnRoad(j))
            cars[1][j]-=1;
    }
    if(light=='R'){
    for(int j=0;j<numCars; j++){
        if(cars[1][j]!=10 && !CarOnLeft(j) && CarOnRoad(j))
            cars[1][j]-=1;

    }
    }
    //this loop was to help keep track of car locations
    /*for(int y=0; y<road.numCars; y++){
    std::cout << road.GetCarX(y) << ' ';
    std::cout << road.GetCarY(y) << endl;
 }*/
}

/// this function is meant to generate a random number
/// and when that number is less than 3 it will spawn a
/// car in one of the rows on the right side of the screen
void Road::GenerateCars()
{

    for(int j=0;j<numCars; j++){
        int toss=coinToss();
        if(toss<3 && !CarOnRoad(j)){
                cars[1][j]=39;
        }
    }
    }
