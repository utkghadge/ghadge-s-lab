#include<iostream>

using namespace std;

//recursive solution for fibb
int fibb(int a)
{
    if(a == 1 || a == 2)
    {
        return 1;
    }
    return fibb(a-1) + fibb(a-2);
}

int main()
{
    cout<<"6th in fibonacci series is ->"<<fibb(6)<<endl;
    return 0;

}