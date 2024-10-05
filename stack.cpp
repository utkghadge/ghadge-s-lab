#include<iostream>
const int MAX_SIZE = 5;

using namespace std;

class stack{
    private:
    int top;
    int arr[MAX_SIZE];

    public:
    stack()
    {
        top = -1;
    }

    bool isEmpty(){
        return (top == -1);
    }

    bool isFull(){
        return(top == MAX_SIZE-1);
    }

    void push(int element)
    {
        if(!isFull())
        {
            top++;
            arr[top] = element;
            cout<<"Pushed element: " << element << " on to the stack."<<endl;
        }
        else{
            cout<<" Stack is full. Cannot push the element" << element << endl;
        }
    }
    int pop()
    {
        if(!isEmpty())
        {
            int poppedelement = arr[top];
            top--;
            cout<<"Popped element: " << poppedelement<<"from the stack"<<endl;
            return poppedelement;
        }
        else{
            cout<<"cant pop . stack is empty"<<endl;
            return -1;
        }
        
    }
    int topElement()
    {
        if(!isEmpty())
        {
            return arr[top];
        }
        else{
            cout<<"No Element . stack is empty"<<endl;
        }
        return -1;
    }

    int peek(int pos)
    {
        if(!isEmpty())
        {
            int index = top - pos + 1;
            return arr[index];
        }
        else{
            cout<<"Stack is empty."<<endl;
            return -1;
        }
    }

};

int main()
{
    stack * myStack = new stack;
    // Push elements until the stack becomes full
    for (int i = 1; i <= 5; ++i) {
        myStack->push(i);
    }
    // Attempt to push more elements into the full stack
    myStack->push(6);
    // Pop all elements until the stack becomes empty
    cout<<" peeking at 3rd position : "<<myStack->peek(3)<<endl;
    cout<<" peeking at 4th position : "<<myStack->peek(4)<<endl;
    while (!myStack->isEmpty()) {
        myStack->pop();
    }

}