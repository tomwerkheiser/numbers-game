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
int searchArray(const int[], int, int);
void gameArray(const int[], int);

int main()
{
    int size, *numbers, maxNum;
    
    cout << "What size array would you like to create? ";
    cin >> size;
    cout << "What is the max number for the array? ";
    cin >> maxNum;
    
    numbers = new int[size];
    
    seedArray(numbers, size, maxNum);
    //cout << "\nNow to show the array\n";
    //showArray(numbers, size);
    //cout << "\nNow to sort the array\n";
    sortArray(numbers, size);
    //cout << "\nNow the sorted array\n";
    //showArray(numbers, size);
    
    gameArray(numbers, size);
    
    
    
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



