#include <iostream> // FOR INPUT AND OUTPUT STREAM
#include <time.h>   // FOR CLOCK FUNCTIONS - TESTING SPEED OF ALGORITHM
#include <iomanip>  // FOR MANIPULATING INPUT AND OUTPUT PRINTING
#include "DynamicArray.h"
using namespace std;

int main()// TEMPORARY DRIVER PROGRAM TO TEST THE DYNAMICARRAY CLASS
{
    DynamicArray X;
    
    unsigned long int StartTime;
    unsigned long int EndTime;
    const int AmountOfTimesThroughLoop = 2;
    float Speed;
    float TotalTime = 0;
    
    cout << "This program will test how fast this computer can dynamically allocate memory for a 20,000 element array.\n";
    cout << "The numbers will range from 1 to 10,000\n";
    cout << "This will also test the speed of various sorting algorithms";
    cout << "This entire process is repeated 10 times to check consistency of speeds\n\n";
    
    srand((unsigned) time (NULL));
    
    for (int i = 0; i < AmountOfTimesThroughLoop; i++)
    {
        StartTime = clock();
        
        for (int i = 0; i < 30000; i++)
        {
            X.AddElementToEnd(1 + (rand() % 10000));
        }
        
        EndTime = clock();
        
        Speed = ((float) EndTime - StartTime) / CLOCKS_PER_SEC;
        
        cout << (i + 1) << ") Seconds it took to build an array: ";
        cout << Speed << " seconds" << endl;
        
        StartTime = clock();
        
        X.SelectionSortArray();
        
        EndTime = clock();
        
        Speed = ((float) EndTime - StartTime) / CLOCKS_PER_SEC;
        
        TotalTime += Speed;
        
        cout << "Time it took to sort this array (Bubble Sort): ";
        cout << Speed << " seconds" << endl << endl;
        
        
        X.ClearArray();
    }
    
    cout << "Average sort speed from all 10 runs: ";
    
    cout << setprecision(4) << TotalTime / AmountOfTimesThroughLoop << endl << endl;
}