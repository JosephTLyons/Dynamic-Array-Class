//
//  DynamicArray.h
//  Dynamic Array Class
//
//  Created by Joseph Lyons on 8/28/16.
//  Copyright © 2016 Joseph Lyons. All rights reserved.
//

#include <iostream>
using namespace std;

#ifndef DynamicArray_h
#define DynamicArray_h

class DynamicArray
{
    int *ArrayPointer;
    int ArraySize;

public:

    // DEFAULT CONSTRUCTOR
    DynamicArray();
    
    // DESTRUCTOR
    ~DynamicArray();

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

#endif /* DynamicArray_h */
