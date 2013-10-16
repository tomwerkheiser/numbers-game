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
int *seedArray(int, int);
int searchArray(const int[], int, int);
void gameArray(const int[], int);
int *newArray(int[], int, int);
int *addToArray(int[], int, int, int);
void nearestNumber(const int[], int, int);

int main()
{
    int size, *numbers, maxNum, newSize;
    
    cout << "What size array would you like to create? ";
    cin >> size;
    cout << "What is the max number for the array? ";
    cin >> maxNum;
    
    numbers = seedArray(size, maxNum);
    cout << "\nNow to show the array\n";
    showArray(numbers, size);
    cout << "\nNow to sort the array\n";
    sortArray(numbers, size);
    cout << "\nNow the sorted array\n";
    showArray(numbers, size);
    //cout << "\nHow big would you like the new array? ";
    //cin >> newSize;
    
    gameArray(numbers, size);
    
    //numbers = addToArray(numbers, newSize, size, maxNum);
    //cout << endl;
    //showArray(numbers, newSize);
    
    return 0;
}

int *seedArray(int size, int maxNum)
{
    int *array;
    array = new int[size];
    
    int x;
    unsigned int seed = static_cast<unsigned int>(time(0));
    srand(seed);
    for (int i = 0; i < size; i++) {
        x = 1 + rand() % maxNum;
        array[i] = x;
    }
    
    return array;
}

void showArray(const int array[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

void sortArray(int array[], int size)
{
    int startScan, minIndex, minValue;
    
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

int searchArray(const int array[], int size, int value)
{
    int index = 0, position = -1;
    bool found = false;
    
    while (index < size && !found)
    {
        if (array[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    
    return position;
}

void gameArray(const int array[], int size)
{
    int value, correct = 0, result, incorrect = 0, total = 0;
    
    cout << "\nWelcome to the game to find out if a number is an array. ";
    cout << "When you get 3 correct in a row you win!\n";
    cout << "To quit the game early enter -1\n\n";
    
    while (correct < 3)
    {
        cout << "Enter a number: ";
        cin >> value;
        if (value == -1) {
            cout << "You couldn't handle the game and decided to quit. Better luck next time.\n";
            break;
        } else if(value < 0) {
            cout << "Please enter a positive number only\n";
            continue;
        } else {
            result = searchArray(array, size, value);
            
            if (result == -1)
            {
                cout << "That number is not in the array.\n";
                nearestNumber(array, size, value);
                incorrect++;
                correct = 0;
                total++;
            }
            else
            {
                cout << "That number is at index " << result << endl;
                correct++;
                total++;
                cout << "Correct: " << correct << endl;
            }
        }
    }
    if (correct == 3)
    {
        cout << "You win!" << endl;
        cout << "It took you " << total << " guesses.\n";
    }
}

int *newArray(int array[], int size, int maxNum)
{
    int *numbers;
    
    delete [] array;
    array = new int[size];
    
    numbers = seedArray(size, maxNum);
    
    return numbers;
}

int *addToArray(int array[], int size, int currentSize, int maxNum)
{
    int *newArray, x;
    newArray = new int[size];
    
    for (int i = 0; i < currentSize; i++) {
        newArray[i] = array[i];
    }
    
    unsigned int seed = static_cast<unsigned int>(time(0));
    srand(seed);
    for (int i = currentSize; i < size; i++) {
        x = 1 + rand() % maxNum;
        newArray[i] = x;
    }
    
    delete [] array;
    
    sortArray(newArray, size);
    
    return newArray;
}

void nearestNumber(const int array[], int size, int value)
{
    int diff = abs(array[0] - value), index;
    
    for (int i = 0; i < size; i++)
    {
        if (diff > abs(array[i] - value))
        {
            diff = abs(array[i] - value);
            index = i;
        }
    }
    
    if (diff < 2)
    {
        cout << "Oh man you were so close\n";
    }
    else if (diff < 3)
    {
        cout << "You were close but not close enough\n";
    }
    else if (diff < 10)
    {
        cout << "You were way off\n";
    }
    else
    {
        cout << "Are you even trying?\n";
    }
}

