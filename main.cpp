// Title: Removing and shifting element in array
// Purpose: Set array and its element/s, then remove an element based on user input which cause the element should be shifted to
//          the left and decrease the size
// Author: Fransiskus Agapa
// Have fun - enjoy the process - Practices make improvement
// Set array and its element/s, then remove an element based on user input which cause the element should be shifted to  the left and decrease the size
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int main() {
    int size = 0;
    int numToRemove = 0;
    char userChoice;

    cout << "Set size of array: ";
    cin >> size;
    cout << endl;

    int number[size];
    if (size <= 0)
    {
        cerr << " Size can't be " << size << endl;
        return -1;
    }
    cout << "Set " << size;
    if (size > 1)
    {
        cout << " elements in array " << endl;
    } else if (size == 1)
    {
        cout << " element in array " << endl;
    }

    for (size_t i = 0; i < size; ++i)
    {
        cout << i + 1 << ") = ";
        cin >> number[i];
    }

    cout << "The element/s in array:" << endl;
    for (size_t i = 0; i < size; ++i) {
        cout << i + 1 << ") " << number[i] << endl;
    }

    cout << "Would you like to remove a number Y/N  ?";
    cin >> userChoice;
    cout << endl;

    if (userChoice == 'Y')
    {
        cout << "Input at what index you'd like to remove (1st element is at index 0): ";
        cin >> numToRemove;
        cout << endl;
        if(numToRemove > size || numToRemove < 0)        // if position can't be > size || position can't be negative
        {
            cerr << "Invalid Index!" << endl;
            return -1;
        } else                                          // position is within range
        {
            for(size_t i = 0; i < size; ++i)
            {
                if(i == numToRemove)
                {
                    if(numToRemove == size-1)                 // if the numToRemove is at last index
                    {
                        int tempSize = size - 1;
                        int temp[tempSize];                    // locate new and temp numbers
                        for(size_t j = 0; j < tempSize; ++j)
                        {
                            temp[j] = number[j];
                        }

                        for(size_t k = 0; k < tempSize; ++k)
                        {
                            number[k] = temp[k];
                        }
                        size = tempSize;
                    } else                                // if the index is not at the last index then shift the  elements and decrease the size by one
                    {
                        number[numToRemove] = number[numToRemove + 1];
                        size--;
                    }
                }
            }
        }

        cout << "The update element/s in array: " << endl;
        for(size_t i = 0; i < size; ++i)
        {
            cout << " at index (" << i << ") is (" << number[i] << ")" << endl;
        }

    } else if (userChoice == 'N')                       // if user doesn't want to continue then exit
    {
        cout << "Exit program..." << endl;
    } else                                              // other than Y or N is invalid input
    {
        cerr << "Invalid Input!" << endl;
        return -1;
    }
    return 0;
}
