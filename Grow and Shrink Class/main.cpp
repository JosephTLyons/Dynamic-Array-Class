#include <iostream>

using namespace std;

class DynamicArray
{
    int *ArrayPointer;
    int ArraySize;
    
public:
    
    DynamicArray();// DEFAULT CONSTRUCTOR
    ~DynamicArray();// DESTRUCTOR
    
    void GrowArrayByOne(const int &X);
    void PrintArray();
    void DeleteNumber(const int &X);
    void ClearArray();
};

int main()// TEMPORARY DRIVER PROGRAM TO TEST THE DYNAMICARRAY CLASS
{
    DynamicArray X;
    int Insert;
    int Delete;
    
    cout << "Enter Numbers: ";
    cin >> Insert;
    
    for (int i = 0; Insert != 0; i++)
    {
        X.GrowArrayByOne(Insert);
        X.PrintArray();
        cout << "Enter Numbers: ";
        cin >> Insert;
        
        cout << "Delete a number: ";
        cin >> Delete;
        
        if (Delete > 0)
        {
            X.DeleteNumber(Delete);
        }
    }
    
    X.ClearArray();
    
    X.PrintArray();
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

void DynamicArray::GrowArrayByOne(const int &X)
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
    
    TempIntPointer[ArraySize - 1] = X;
    
    /* DELETE MEMORY ASSOCIATED WITH ORIGINAL ARRAY IN ARRAYPOINTER */
    
    delete ArrayPointer;
    
    /* ASSIGN THE MEMORY LOCATION OF THEW NEW (LARGER) ARRAY TO ARRAYPOINTER */
    
    ArrayPointer = TempIntPointer;
    
    /* POINT TEMPINTPOINTER TO NULL */
    
    TempIntPointer = NULL;
}

void DynamicArray::PrintArray()
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

void DynamicArray::DeleteNumber(const int &X)
{
    int *TempIntPointer = NULL;
    
    /* MOVE ALL ELEMENTS LEFT ONE, OVERWRITING THE ELEMENT TO BE DELETED, STOPPING THERE */
    
    for (int i = (X - 1); i < ArraySize ; i++)
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








