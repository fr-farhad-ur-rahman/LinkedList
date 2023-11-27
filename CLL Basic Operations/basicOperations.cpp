#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr){}
};

class CircularLinkedList{
    Node* head;
public:
    CircularLinkedList() : head(nullptr){}

    void insertAtTail(int data);
    void insertAtHead(int data);
    void display();
};

void CircularLinkedList :: insertAtHead(int data){
    Node* new_node = new Node(data);
    
    if(head == nullptr){
        new_node -> next = new_node;
        head = new_node;
    }
    else{
        Node* current = head;
        while(current -> next != head){
            current = current -> next;
        }
        current -> next = new_node;
        new_node -> next = head;
        head = new_node;
    }
}

void CircularLinkedList :: insertAtTail(int data){
    Node* new_node = new Node(data);

    if(head == nullptr){
        insertAtHead(data);
        return;
    }

    Node* current = head;
    while(current -> next != head){
        current = current -> next;
    }
    current -> next = new_node;
    new_node -> next = head;
}

void CircularLinkedList :: display(){
    Node* current = head;

    do{
        cout << current -> data << " ";
        current = current -> next;
    } while(current != head);

    cout << endl;
}

int main(){
    CircularLinkedList cll;

    cll.insertAtTail(10);
    cll.insertAtTail(20);
    cll.insertAtTail(30);
    cll.insertAtTail(40);
    cll.insertAtTail(50);
    cll.insertAtHead(5);
    cll.display();
    return 0;
}
