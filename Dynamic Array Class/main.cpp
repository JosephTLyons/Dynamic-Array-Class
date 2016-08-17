#include <iostream> // FOR INPUT AND OUTPUT STREAM
#include <time.h>   // FOR CLOCK FUNCTIONS - TESTING SPEED OF ALGORITHM
#include <iomanip>

using namespace std;

class DynamicArray
{
    int *ArrayPointer;
    int ArraySize;
    
public:
    
    DynamicArray(); // DEFAULT CONSTRUCTOR
    ~DynamicArray();// DESTRUCTOR
    
    void AddElementToEnd(const int &NewElement);
    void InsertElementAtPosition(const int &Position, const int &NewElement);
    void PrintFullArray();
    void DeleteElementAtPosition(const int &ElementToBeDeleted);
    void ClearArray();
    void PrintSpecificElement(const int &ElementToPrint);
    void BubbleSortArray();
    void SelectionSortArray();
    void InsertionSortArray();
};

int main()// TEMPORARY DRIVER PROGRAM TO TEST THE DYNAMICARRAY CLASS
{
    DynamicArray X;
    
    unsigned long int StartTime;
    unsigned long int EndTime;
    const int AmountOfTimesThroughLoop = 10;
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
        
        for (int i = 0; i < 20000; i++)
        {
            X.AddElementToEnd(1 + (rand() % 10000));
        }
        
        EndTime = clock();
        
        Speed = ((float) EndTime - StartTime) / CLOCKS_PER_SEC;
        
        cout << (i + 1) << ") Seconds it took to build an array: ";
        cout << Speed << " seconds" << endl;
        
        StartTime = clock();
        
        X.BubbleSortArray();
        
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

DynamicArray::DynamicArray()// DEFAULT CONSTRUCTOR
{
    ArraySize = 0;
    ArrayPointer = NULL;
}

DynamicArray::~DynamicArray()// DESTRUCTOR
{
    delete[] ArrayPointer;
}

void DynamicArray::AddElementToEnd(const int &NewElement)
{
    int *TempIntPointer = NULL;
    
    /* INCREASE SIZE BY ONE */
    
    ArraySize++;
    
    /* CREATE NEW ARRAY THATS ONE ELEMENT LARGER THAN THE ONE ASSOCIATED WITH DATA MEMBER */
    
    TempIntPointer = new(nothrow) int[ArraySize];
    
    /* CHECK TO MAKE SURE MEMORY WAS ALLOCATED, IF MEMORY ISN'T AVAILABLE, DISPLAY MESSAGE AND RETURN */
    
    if (TempIntPointer == NULL)
    {
        cout << "\n\nRan out of memory, couldn't grow array.\n\n";
        return;
    }
    
    /* COPY INFORMATION FROM DATA MEMBER ARRAY, TO NEWLY MADE ARRAY, IF ORIGINAL ARRAYPOINER ISN'T POINTING TO NULL */
    /* THIS IS IMPORTANT FOR THE FIRST PASS WHEN ARRAY IS EMPTY AND THE COPY STATEMENT AFTER TRIES TO ACCESS IT, PRODUCING AN ERROR */
    
    if (ArrayPointer != NULL)
    {
        for (int i = 0; i < ArraySize; i++)
        {
            TempIntPointer[i] = ArrayPointer[i];
        }
    }
    
    /* ASSIGN NEW NUMBER TO THE END OF THE ARRAY */
    
    TempIntPointer[ArraySize - 1] = NewElement;
    
    /* DELETE MEMORY ASSOCIATED WITH ORIGINAL ARRAY IN ARRAYPOINTER */
    
    delete[] ArrayPointer;
    
    /* ASSIGN THE MEMORY LOCATION OF THEW NEW (LARGER) ARRAY TO ARRAYPOINTER */
    
    ArrayPointer = TempIntPointer;
    
    /* POINT TEMPINTPOINTER TO NULL */
    
    TempIntPointer = NULL;
}

void DynamicArray::InsertElementAtPosition(const int &Position, const int &NewElement)
{
    /* MAKE NEW ARRAY THATS ONE SIZE BIGGER */
    
    int *TempIntPointer = new(nothrow) int[ArraySize + 1];
    
    /* COPY ORIGINAL ARRAY FROM ARRAYPOINTER TO TEMPINTPOINTER*/
    
    for (int i = 0; i < ArraySize; i++)
    {
        TempIntPointer[i] = ArrayPointer[i];
    }
    
    /* INCREASE ARRAYSIZE BY ONE */
    
    ArraySize++;
    
    /* MOVE ALL ELEMENTS OVER ONE SPOT, STARTING FROM RIGHT AND WORKING LEFT, LEAVING SPACE AT THE DESIRED POSITION */
    
    for (int i = (ArraySize - 1); i > (Position - 1); i--)
    {
        TempIntPointer[i] = TempIntPointer[i - 1];
    }
    
    /* INSERT NEW ELEMENT AT DESIRED POSITION */
    
    TempIntPointer[Position - 1] = NewElement;
    
    /* DELETE THE ORIGINAL ARRAY FROM ARRAYPOINTER */
    
    delete[] ArrayPointer;
    
    /* ASSIGN NEW ARRAY TO ARRAYPOINTER */
    
    ArrayPointer = TempIntPointer;
    
    /* POINT TEMPINTPOINTER TO NULL */
    
    TempIntPointer = NULL;
}

void DynamicArray::PrintFullArray()
{
    cout << endl;
    
    for (int i = 0; i < ArraySize; i++)
    {
        cout << (i + 1) << ") " << this -> ArrayPointer[i] << endl;
    }
    
    if (ArrayPointer == NULL || ArraySize == 0)
    {
        cout << "Array is empty";
    }
    
    cout << endl;
}

void DynamicArray::DeleteElementAtPosition(const int &ElementToBeDeleted)
{
    int *TempIntPointer = NULL;
    
    /* MOVE ALL ELEMENTS LEFT ONE, OVERWRITING THE ELEMENT TO BE DELETED, STOPPING THERE */
    
    for (int i = (ElementToBeDeleted - 1); i < ArraySize ; i++)
    {
        this -> ArrayPointer[i] = this -> ArrayPointer[i + 1];
    }
    
    /* DECREASE ARRAY SIZE */
    
    ArraySize--;
    
    /* CREATE NEW ARRAY WITH NEW ARRAY SIZE */
    
    TempIntPointer = new(nothrow) int[ArraySize];
    
    /* COPY CONTENTS FROM ORIGINAL ARRAY TO NEW ARRAY */
    
    if (ArrayPointer != NULL)
    {
        for (int i = 0; i < ArraySize; i++)
        {
            TempIntPointer[i] = ArrayPointer[i];
        }
    }
    
    /* DELETE ORIGINAL ARRAY */
    
    delete[] ArrayPointer;
    
    /* ASSIGN NEW ARRAY TO ARRAYPOINTER */
    
    ArrayPointer = TempIntPointer;
    
    /* POINT TEMPINTPOINTER TO NULL */
    
    TempIntPointer = NULL;
}

void DynamicArray::ClearArray()
{
    /* DELETE ARRAY */
    
    delete[] ArrayPointer;
    
    /* POINT ARRAYPOINTER TO NULL */
    
    ArrayPointer = NULL;
    
    /* RESET ARRAYSIZE BACK TO ZERO */
    
    ArraySize = 0;
}

void DynamicArray::PrintSpecificElement(const int &ElementToPrint)
{
    cout << ElementToPrint << ") ";
    
    /* PRINT ELEMENT REQUESTED */
    
    cout << ArrayPointer[ElementToPrint - 1];
    cout << endl;
}

void DynamicArray::BubbleSortArray()
{
    /* USING BUBBLE SORT TO SORT ARRAY */
    
    bool SwapsMadeFlag = true;
    
    /* ALWAYS REPEAT THROUGH AS LONG AS A SWAP WAS MADE */
    
    while (SwapsMadeFlag == true)
    {
        SwapsMadeFlag = false;
        
        /* GO THROUGH WHOLE ARRAY ONCE, CHECKING TWO NEIGHBORING NUMBERS */
        /* SWAPPING NUMBERS AS NECESSARY, FIRST TIME THROUGH PUTS LARGEST NUMBER AT END */
        
        for (int i = 0; i < (ArraySize - 1); i++)
        {
            if (ArrayPointer[i] > ArrayPointer[i +1 ])
            {
                swap(ArrayPointer[i], ArrayPointer[i +1]);
                SwapsMadeFlag = true;
            }
        }
    }
    
}

/* BOTH SELECTION SORT AND INSERTION SORT ALGORITH ARE DIRECTLY COPIED FROM */
/* http://www.cprogramming.com/tutorial/computersciencetheory/sortcomp.html */

void DynamicArray::SelectionSortArray()
{
    for(int x = 0; x < ArraySize; x++)
        
    {
        int index_of_min = x;
        
        for(int y = x; y < ArraySize; y++)
            
        {
            if(ArrayPointer[index_of_min] > ArrayPointer[y])
            {
                index_of_min = y;
                
            }
        }
        
        int temp = ArrayPointer[x];
        
        ArrayPointer[x] = ArrayPointer[index_of_min];
        
        ArrayPointer[index_of_min] = temp;
    }
}

void DynamicArray::InsertionSortArray()
{
    for(int x = 0; x < ArraySize; x++)
        
    {
        int index_of_min = x;
        
        for(int y = x; y < ArraySize; y++)
            
        {
            if(ArrayPointer[index_of_min] > ArrayPointer[y])
                
            {
                index_of_min = y;
            }
        }
        
        int temp = ArrayPointer[x];
        
        ArrayPointer[x] = ArrayPointer[index_of_min];
        
        ArrayPointer[index_of_min] = temp;
    }
}





