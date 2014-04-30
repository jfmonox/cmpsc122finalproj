//PROGRAMMERs: Ron Myers and Ayrton Trujillo
//SECTION:     2
//LAB:         18
//DATE:        4/23/2014
//DESCRIPTION: Implementation of merge sort

#include<iostream>
using namespace std;

void merge(int *,int, int , int ); //defining of merge for use in mergeSort

void mergeSort(int* A, int p, int q)
//PRE:  A[p..q] must be initialized. p <= q.
//POST: A[p..q] will be sorted in ascending order, containing the same values as it had at
//        time of invocation
{
    int m;     //floored midpoint of array A

    if(p < q)  //ensures that the passed in array size is larger than one
               //  otherwise, starts popping the call stack
    {
        m = (p + q) / 2;

        mergeSort(A,p,m);
        mergeSort(A,m+1,q);
        merge(A,p,m,q);
    }
    return;
}

void merge(int* A, int low, int mid, int high)
//PRE:  l_size > 0, r_size > 0, L[0..l_size-1] must be initialized and sorted in ascending order
//        R[0..r_size-1] must be initialized and sorted in ascending order. A must be allocated
//        to at least a size of (l_size + r_size)
//POST: A[0..l_size+r_size-1] contains all elements from L[0..l_size-1] and R[0..r_size-1]
//        sorted in ascending order
{
    int l_ctr;  //counter that keeps track of the lower half of the analyzed array
    int h_ctr;  //counter that keeps track of thi upper half of the analyzed array
    int o_size; //counter that keeps track of how many elements have been sorted
    int* O;     //dynamic output array where the sorted elements are kept

    l_ctr = low;
    h_ctr = mid+1;
    o_size = 0;
    O = new int[high - low + 1];

    //loop that runs until either the lower half or the upper half runs out of unsorted
    //  array elements.
    while (l_ctr <= mid && h_ctr <= high)
    {
        if (A[l_ctr] > A[h_ctr])   //if the upper half's array element is smaller, it is added
                                   //  to the output array
        {
            O[o_size] = A[h_ctr];
            h_ctr++;
        }
        else                       //otherwise, the lower half's array element is added to
                                   //  the output array
        {
            O[o_size] = A[l_ctr];
            l_ctr++;
        }
        o_size ++;
    }

    //if there are still elements left in the lower half, they are looped through and added
    //  to the output array
    while (l_ctr <= mid)
    {
        O[o_size] = A[l_ctr];
        l_ctr++;
        o_size++;
    }
    //if there are still elements left in the upper half, they are looped through and added
    //  to the output array
    while (h_ctr <= high)
    {
        O[o_size] = A[h_ctr];
        h_ctr++;
        o_size++;
    }

    //all of the elements in the output array are copied into the array passed into the method
    for (int j = low; j < low + o_size; j++)
    {
        A[j] = O[j-low];
    }

    delete [] O; //memory deallocation
}

void printArray(int A[], int n)
//PRE:  n > 0 and A[0..n] is initialized
//POST: A[0..n] will be printed on the screen on one line with spaces between elements
{
    //loops through entire array, printing every element on a single line with spaces separating
    //  the individual elements
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
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
    mergeSort(A1,0,14);
    printArray(A1,15);

    cout << endl << endl << "A2 unsorted:" << endl;
    printArray(A2,10);
    cout << endl << "A2 sorted:" << endl;
    mergeSort(A2,0,9);
    printArray(A2,10);

    cout << endl << endl << "A3 unsorted:" << endl;
    printArray(A3,20);
    cout << endl << "A3 sorted:" << endl;
    mergeSort(A3,0,19);
    printArray(A3,20);
}
