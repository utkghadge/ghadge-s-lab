/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int arr[],int n)
{
    int minIndex,index;
    int i,j;
    for( i = 0 ; i < n-1 ; i++)
    {
        minIndex = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                //min = arr[j];
                minIndex = j;
            }
        }
        if(i!=minIndex)
        {
            int x = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = x;
        }

    }

}

int main()
{
    int a[] = {8,21,30,37,46,29,16,2,29,23};
    int size = sizeof(a) / sizeof(a[0]);
    InsertionSort(a,size);
    printArray(a,size);

    return 0;
}