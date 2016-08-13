#include <iostream>

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
};

int main()// TEMPORARY DRIVER PROGRAM TO TEST THE DYNAMICARRAY CLASS
{
    DynamicArray X;
    
    for (int i = 0; i < 50; i++)
    {
        X.AddElementToEnd(i + 1);
    }
    
    X.PrintFullArray();
    
    X.DeleteElementAtPosition(25);
    
    X.PrintFullArray();
    
    X.InsertElementAtPosition(25, 1020);
    
    X.PrintFullArray();
    
    X.PrintSpecificElement(25);
    
    
}

DynamicArray::DynamicArray()// DEFAULT CONSTRUCTOR
{
    ArraySize = 0;
    ArrayPointer = NULL;
}

DynamicArray::~DynamicArray()// DESTRUCTOR
{
    delete ArrayPointer;
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
    
    delete ArrayPointer;
    
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
    
    delete ArrayPointer;
    
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
    
    delete ArrayPointer;
    
    /* ASSIGN NEW ARRAY TO ARRAYPOINTER */
    
    ArrayPointer = TempIntPointer;
    
    /* POINT TEMPINTPOINTER TO NULL */
    
    TempIntPointer = NULL;
}

void DynamicArray::ClearArray()
{
    /* DELETE ARRAY */
    
    delete ArrayPointer;
    
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







