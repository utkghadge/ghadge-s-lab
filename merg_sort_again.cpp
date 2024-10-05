#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(const vector<int>& left,const vector<int>& right)
{
    vector<int> merged;
    int left_index = 0;
    int right_index = 0;

    while(left_index < left.size() && right_index < right.size())
    {
        if(left[left_index]<right[right_index])
        {
            merged.push_back(left[left_index]);
            left_index++;
        }
        else{
            merged.push_back(right[right_index]);
            right_index++;
        }
    }

        while(left_index < left.size())
        {
            merged.push_back(left[left_index]);
            left_index++;
        }
    
        while(right_index < right.size())
        {
            merged.push_back(right[right_index]);
            right_index++;
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
    vector<int> arr = {2,3,1,5,4};

    vector<int> res = MergeSort(arr);

    for(int num : res)
    {
        cout<<num<<endl;
    }

    return 0;

}