
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(const vector<int>& left,const vector<int>& right)
{
    vector<int> merged;
    int left_counter = 0;
    int right_counter = 0;
    
    while(left_counter < left.size() && right_counter < right.size())
    {
        if(left[left_counter] < right[right_counter])
        {
            merged.push_back(left[left_counter]);
            left_counter++;
        }
        else{
            merged.push_back(right[right_counter]);
            right_counter++;
        }
    }
    
    //add any leftover elements
    while(left_counter<left.size())
    {
        merged.push_back(left[left_counter]);
        left_counter++;
    }
    while(right_counter<right.size())
    {
        merged.push_back(right[right_counter]);
        right_counter++;
    }
    return merged;
}

vector<int> MergeSort(const vector<int>& arr)
{
    if(arr.size() <= 1)
    {
        return arr;
    }
    int mid = arr.size() / 2;

    vector<int> left(arr.begin(),arr.begin()+mid);
    vector<int> right(arr.begin()+mid,arr.end());

    vector<int> sorted_left = MergeSort(left);
    vector<int> sorted_right = MergeSort(right);

    vector<int> Merged = merge(sorted_left,sorted_right);
    return Merged;

}

int main()
{
    vector<int> a = {8,21,30,37,46,29,16,2,29,23};
    
    vector<int> res = MergeSort(a);
    
    for(int num : res)
    {
        cout<<num<<" , ";
    }

    return 0;
}