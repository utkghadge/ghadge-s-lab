#include<iostream>
#include<vector>

using namespace std;

// Function to swap two elements
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition( vector<int>& arr, int low , int high){
    int pivot = arr[high]; //choose last element as pivot
    int i = low-1;         // Index of smaller element
    
    for(int j=low;j<high;j++){
        if(arr[j]<pivot)
        {
            i++;
            Swap(arr[i],arr[j]);
        }
    }
    Swap(arr[i+1],arr[high]); //place pivot in its correct position
    return i+1;
}

void QuickSort( vector<int>& arr, int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);

        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);

    }
}

int main(){

    vector<int> arr = {8, 7, 6, 1, 0, 9, 2};

    QuickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}