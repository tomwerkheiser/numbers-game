//
//  main.cpp
//  arraysPointers
//
//  Created by Tom Werkheiser on 10/11/13.
//  Copyright (c) 2013 Tom Werkheiser. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void showArray(const int[], int);
void sortArray(int[], int);
void seedArray(int[], int, int);

int main()
{
    int size, *numbers, maxNum;
    
    cout << "What size array would you like to create? ";
    cin >> size;
    cout << "What is the max number for the array? ";
    cin >> maxNum;

    numbers = new int[size];
    
    seedArray(numbers, size, maxNum);
    cout << "\nNow to show the array\n";
    showArray(numbers, size);
    cout << "\nNow to sort the array\n";
    sortArray(numbers, size);
    cout << "\nNow the sorted array\n";
    showArray(numbers, size);
    
    return 0;
}

void seedArray(int array[], int size, int maxNum)
{
    int x;
    unsigned int seed = static_cast<unsigned int>(time(0));
    srand(seed);
    for (int i = 0; i < size; i++) {
        x = 1 + rand() % maxNum;
        array[i] = x;
    }
}

void showArray(const int array[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

void sortArray(int array[], int size)
{
    bool swap;
    int temp;
    
    do
    {
        swap = false;
        for (int i = 0; i < (size -1); i++)
        {
            if(array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}





