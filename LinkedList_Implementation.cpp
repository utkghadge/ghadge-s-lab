#include<iostream>

using namespace std;

struct node {
    int data;
    node* next;

    node() : data(0) , next(nullptr) {}
    node(int value) : data(value) , next(nullptr) {}

};

class LinkedList {
    private:
    node* head;

    public:
    LinkedList() : head(nullptr){}

    //insert at the end
    void insertAtEnd(int value){
        node* newNode = new node(value);
        if(head == nullptr)
        {
            head = newNode;
        }
        else{
            node* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    //insert at head
    void insertAtHead(int value)
    {
        node * newNode = new node(value);
        newNode->next = head;
        head = newNode;
    }

    //insert at a position
    void insertAtPosition(int value, int pos){
        if(pos <= 0)
        {
            cout<<"invalid position"<<endl;
            return ;
        }

        if(pos == 1){
            insertAtHead(value);
            return;
        }

        node * newNode = new node(value);
        node * temp = head;
        int traverse = pos - 1;
        while(traverse != 1 && temp->next != nullptr)
        {
            temp = temp->next;
            --traverse;
        }
        if(temp->next == nullptr){
            temp->next = newNode;
        }
        else{
            newNode->next = temp->next;
            temp->next = newNode;
        }

    }

    // Find a node by value
    bool find(int value) {
        node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Print the linked list
    void printList() const {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Delete a node by value
    void deleteValue(int value) {
        if (head == nullptr) return;

        // If head is the node to be deleted
        if (head->data == value) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse the list to find the node to delete
        node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        // If the node was found
        if (temp->next != nullptr) {
            node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Destructor to free memory
    ~LinkedList() {
        node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to demonstrate the linked list
int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtHead(5);
    list.insertAtPosition(25, 4);
    cout << "Linked List: ";
    list.printList();

    cout << "Find 25: " << (list.find(25) ? "Found" : "Not Found") << endl;
    list.deleteValue(20);
    cout << "After deleting 20: ";
    list.printList();
    list.insertAtPosition(100, 3);
    cout << "Linked List: ";
    list.printList();

    return 0;
}