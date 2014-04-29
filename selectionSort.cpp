//PROGRAMMERS: Ron Myers and Ayrton Trujillo
//SECTION:     2
//LAB:         Final
//DATE:        4/28/2014
//DESCRIPTION: Implementation of selection sort

#include <iostream>
using namespace std;

void selectionSort(int A[], int size)
//PRE:  size >= 1, and A[0..size-1] is initialized
//POST: A[0..size-1] is sorted in ascending order and contains the same values as A[1..n]
//        at the time of invocation
{
    int maxIndex;

    for (int bottom = size; bottom >= 1; bottom--)
    //Loops through the array in from the end to the second element
    //INVARIANT: A[bottom..size-1] is sorted
    {
        maxIndex = 0;  //maxIndex initialized to the first array index

        for (int i = 1; i <= bottom; i++)
        //Loops through unsorted array elements
        {
            if (A[i] > A[maxIndex])
            //changes maxIndex if a larger element is found
            {
                maxIndex = i;
            }
        }
        swap(A[bottom], A[maxIndex]);
    }
}

void printArray(int A[], int size)
//PRE:  size >= 1, and A[0..size-1] is initialized
//POST: all values in A will be printed to screen in order from 0..size-1
{
    for (int i = 0; i < size; i++)
    //loops through entire array, printing it and adding a new line
    {
        cout << A[i] << endl;
    }
}

int main()
{
    int A1[15] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    int A2[10] = {21,57,56,298,23,35,54,654,98,77};
    int A3[20] = {984,654,32,357,123,456,789,687,32,687,12,546,7,56,6,7,65,132,879,6};

    cout << "A1 unsorted:" << endl;
    printArray(A1,15);
    cout << endl << "A1 sorted:" << endl;
    selectionSort(A1,15);
    printArray(A1,15);

    cout << endl << endl << "A2 unsorted:" << endl;
    printArray(A2,10);
    cout << endl << "A2 sorted:" << endl;
    selectionSort(A2,10);
    printArray(A2,10);

    cout << endl << endl << "A3 unsorted:" << endl;
    printArray(A3,20);
    cout << endl << "A3 sorted:" << endl;
    selectionSort(A3,20);
    printArray(A3,20);
}
