#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr){}
};

class DoublyLinkedList{
    Node* head;
public:
    DoublyLinkedList(){
        head = nullptr;
    }
    void insertAtHead(int data);
    void insertAtTail(int data);
    void insertAtSpecificPosition(int position, int data);
    void reverse();
    void display();
};

void DoublyLinkedList :: insertAtTail(int data){
    Node* new_node = new Node(data);
    if(head == nullptr){
        head = new_node;
        return;
    }
    Node* current = head;
    while(current -> next!= nullptr){
        current = current -> next;
    }
    current -> next = new_node;
    new_node -> prev = current;
}
void DoublyLinkedList :: reverse(){
    // create three pointers
    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;

    while(current != nullptr){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void DoublyLinkedList :: display(){
    Node* current = head;
    while(current != nullptr){
        cout << current -> data << " <-> ";
        current = current -> next;
    }
    cout << endl;
}

int main(){
    DoublyLinkedList dll;
    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.display();
    dll.reverse();
    dll.display();

    return 0;
}