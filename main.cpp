/// Aaron Reynolds UIN:01118087
/// Assg4_areynol
/// CS250

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <ostream>      // std::flush
#include <fstream>
#include "Road.h"

void Operate(char grid[][40], int rows, int cols);
void ResetGrid(char grid[][40], int rows, int cols);
void SetGrid(char grid[][40], int cols, int rows);
void PrintGrid(char grid[][40], char light, int rows, int cols);
void InitializeGrid(char grid[][40], int rows, int cols);
void LoadCarsOnGrid(char grid[][40], Road *road, int rows, int cols);

int main(){
    int rows = 5;
    int cols = 40;
    char grid[5][40];

    srand (time(NULL));
    Operate(grid, rows, cols);

    return 0;
}

void InitializeGrid(char grid[][40], int rows, int cols){
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            grid[i][j]= ' ';
}

void ResetGrid(char grid[][40], int rows, int cols){
    for(int i=1; i<rows-1; i++)
        for(int j=0; j<cols; j++)
            grid[i][j] = ' ';
}

void SetGrid(char grid[][40], int rows, int cols){
    cout<<cols;
    for(int i=0; i<cols; i++)
    {
        grid[0][i]='-';
        grid[4][i]='-';
    }

    grid[0][10]= 'G';
    grid[4][10]= 'G';
}

void PrintGrid(char grid[][40], char light, int rows, int cols){
    grid[0][10]= light;
    grid[4][10]= light;

    system("CLS");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++)
            cout<<grid[i][j];

        cout<<endl;
    }
}

void LoadCarsOnGrid(char grid[][40], Road *road, int rows, int cols)
{
    int r, c;
    ResetGrid(grid, rows, cols);
    for(int i=0; i<road->numCars; i++){
        r = road->GetCarX(i);
        c = road->GetCarY(i);
        if(r!=-1 && c!= -1)
            grid[r][c] = 'O';
    }
}

void Operate(char grid[][40], int rows, int cols){
    Road road;
    InitializeGrid(grid, rows, cols);
    SetGrid(grid, rows, cols);

    int index = 0;
    while(true){
        /// here i needed to add the struct and access operator to the functions
        /// that were previously standalone functions
        road.GenerateCars();
        road.MoveCars();
        LoadCarsOnGrid(grid, &road, rows, cols);
        road.AdjustLight(index);
        PrintGrid(grid, road.GetLight(), rows, cols);
        index++;
    }
}
