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

void BubbleSort(int arr[],int size)
{
    int count = size;
    for(int i=0;i< count-1 ; i++)
    {
        for(int j = i+1 ; j < count ; j++ )
        {
            if(arr[i]>arr[j])
            {
                int x = arr[j];
                arr[j] = arr[i];
                arr[i] = x;
            }
        }
        //count--;
    }
}

int main()
{
    int a[] = {8,21,30,37,46,29,16,2,29,23};
    int size = sizeof(a) / sizeof(a[0]);
    BubbleSort(a,size);
    printArray(a,size);

    return 0;
}