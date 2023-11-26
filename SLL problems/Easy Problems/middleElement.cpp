#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

public:
    // constructor
    Node(int data) : data(data), next(nullptr){}
};

class LinkedList{
    Node* head;

public:
    // constructor
    LinkedList() : head(nullptr){}

    // function definition
    void insertAtEnd(int data);
    int getLength();
    int middleElement();
    void display();

};
// function implementation
void LinkedList :: insertAtEnd(int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    
    Node* current = head;
    while(current -> next != nullptr){
        current = current -> next;
    }
    current -> next = newNode;
}

int LinkedList :: getLength(){
    Node* current = head;
    int len = 0;
    while(current != nullptr){
        current = current -> next;
        len++;
    }
    return len;
}

int LinkedList :: middleElement(){
    int mid = getLength() / 2;

    Node* current = head;
    if(current == nullptr){
        return -1;
    }

    int current_pos = 0;
    while(current_pos != mid && current -> next != nullptr){
        current = current -> next;
        current_pos++;
    }
    return current -> data;
}

void LinkedList :: display(){
    Node* current = head;
    while(current != nullptr){
        cout << current -> data << " -> ";
        current = current -> next;
    }
    cout << "NULL" << endl;
}

int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);

    ll.display();

    cout << "Length is: " << ll.getLength() << endl;
    cout << "Middle element is: " << ll.middleElement() << endl;
    return 0;
}
