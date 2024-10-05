#include<iostream>

using namespace std;

class A{
    public:
    void f1()
    {
        cout<<"class A -> Func 1"<<endl;
    }
    void f2()
    {
        cout<<"class A -> Func 2"<<endl;
    }
};

class B : public A{
    public:
    void f1()
    {
        cout<<"class B -> Func 1"<<endl;
    }
    void f2(int x)
    {
        cout<<"class B -> Func 2"<<endl;
    }
};

int main()
{
    B obj;
    obj.f1();
    obj.f2();
    return 0;

}