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
    void display();
};

void DoublyLinkedList :: insertAtHead(int data){
    Node* new_node = new Node(data);
    new_node -> next = head;
    if(head != nullptr){
        head -> prev = new_node;
    }
    head = new_node;
}

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

void DoublyLinkedList :: insertAtSpecificPosition(int position, int data){
    Node* new_node = new Node(data);
    if(position == 0){
        head = new_node;
    }
    Node* current = head;
    int current_pos = 0;
    while(current_pos != position - 1 && current != nullptr){
        current = current -> next;
        current_pos++;
    }
    new_node -> next = current -> next;
    current -> next = new_node;
    if(current -> next != nullptr){
        new_node -> prev = current;
    }
}

void DoublyLinkedList :: display(){
    Node* current = head;
    while(current != nullptr){
        cout << current -> data << " <-> ";
        current = current -> next;
    }
    
}

int main(){
    DoublyLinkedList dll;
    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtSpecificPosition(2, 25);
    dll.display();
    return 0;
}
