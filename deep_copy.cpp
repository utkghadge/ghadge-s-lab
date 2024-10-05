#include<iostream>

using namespace std;

class myClass{
    public:
    int *x;
    myClass(int val)
    {
        x = new int(val);
    }
    myClass(myClass &obj)
    {
        x = new int(*(obj.x));
    }

    ~myClass()
    {
        delete x;
    }
};

int main()
{
    myClass obj1(10);
    myClass obj2 = obj1;
    cout<<"value of x (obj2)"<<*(obj2.x)<<endl;
    *obj2.x = 20;
    cout<<"value of x (obj2)"<<*(obj2.x)<<endl;
    return 0;

}