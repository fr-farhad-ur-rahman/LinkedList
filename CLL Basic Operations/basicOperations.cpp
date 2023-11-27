#include <iostream>
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
    void insertAtSpecificPosition(int pos, int data);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtSpecificPosition(int pos);
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

void CircularLinkedList :: insertAtSpecificPosition(int position, int data){
    Node* new_node = new Node(data);

    if(position == 0){
        insertAtHead(data);
        return;
    }

    int current_pos = 0;
    Node* current = head;
    while(current_pos != position - 1 and current != nullptr){
        current = current -> next;
        current_pos++;
    }
    new_node -> next = current -> next;
    current -> next = new_node;
}

void CircularLinkedList :: deleteAtHead(){
    Node* current = head;
    while(current -> next != head){
        current = current -> next;
    }
    Node* toDelete = head;
    current -> next = head -> next;
    head = head -> next;

    delete toDelete;
}

void CircularLinkedList :: deleteAtTail(){
    Node* current = head;

    Node* prev = nullptr;
    while(current -> next != head){
        prev = current;
        current = current -> next;
    }
    Node* temp = current;
    prev -> next = head;;
    delete temp;
}

void CircularLinkedList :: deleteAtSpecificPosition(int position){
    if(position == 0){
        deleteAtHead();
    }
    Node* current = head;
    int current_pos = 0;
    while(current_pos != position - 1){
        current = current -> next;
        current_pos++;
    }
    Node *temp = current -> next;
    current -> next = current -> next -> next;
    delete temp;
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
    cll.insertAtSpecificPosition(2, 100);   
    cll.deleteAtSpecificPosition(2);
    cll.deleteAtHead();
    cll.deleteAtTail();
    cll.display();
    return 0;
}
