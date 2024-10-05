//stack using LinkedList
#include<iostream>
const int MAX_SIZE = 5;

using namespace std;

class Node{
    public:
    int data;
    Node * next;

};

class StackLL{
    private:
    Node * top;
    public:

    StackLL()
    {
        top == NULL;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void push(int x)
    {
        Node * node_new = new Node;
        node_new->data = x; 
        //if(!isEmpty())
        //{
            node_new->next = top;
            top = node_new;
            cout<<"Pushed element: " << x << " on to the stack."<<endl;
        //}
        /*else{
            node_new->next = NULL;
            top = node_new;
            cout<<"Pushed element: " << x << " on to the stack as the first node."<<endl;
        }*/
    }

    int pop()
    {
        
        if(!isEmpty())
        {
            int num = top->data;
            top = top->next;
            cout<<"Popped element: " << num <<"from the stack"<<endl;
            return num;
        }
        else{
            cout<<"cant pop . stack is empty"<<endl;
        }
    }

    void display()
    {
        Node * node_new = top;
        
        while(node_new != NULL)
        {
            cout<<" data at current node is : "<<node_new->data<<endl;
            node_new = node_new->next;
        }
    }    


};

int main()
{
    StackLL * lstack = new StackLL;
    lstack->push(1);
    lstack->push(4);
    lstack->push(9);
    lstack->push(16);
    lstack->push(25);
    lstack->push(36);

    lstack->display();

    lstack->pop();
    lstack->pop();

    return 0;
}