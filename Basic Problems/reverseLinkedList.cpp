#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;

    }
};

class LinkedList{
public:
    Node *head; // Pointer to the head of the list.

    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}

    void insertAtTail(int data)
    {
        // creation of new node.
        Node *newNode = new Node(data);
        // if there is no node make newNode to head
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        // iterator
        Node *current = head;
        // iterating from head to nullptr
        while (current->next != nullptr)
        {
            current = current->next;
        }
        // adding newNode at the end of list.
        current->next = newNode;
    }
    void display(){
        Node* current = head;

        // Traverse the list and print each element.
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        // Print "NULL" to indicate the end of the list.
        cout << "NULL" << endl;
        cout << "\n\n\n";
    }

    void reverse(){
        // create three pointers
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while(current != nullptr){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main(){
    LinkedList ll;

    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);

    ll.display();
    ll.reverse();
    ll.display();

    return 0;
}
