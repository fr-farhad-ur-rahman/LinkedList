#include <iostream>
using namespace std;

// Node class represents a node in the linked list.
class Node{
public:
    int data; // data stored in the node
    Node* next; // pointer to the next node in the list.

    // Constructor to initialize data and next.
    Node(int data) : data(data), next(nullptr){}
};

// LinkedList class manages the linked list.
class LinkedList{
public:
    Node* head; // Pointer to the head of the list.

    // Constructor to initialize the linked list
    LinkedList() : head(nullptr){}

    // Method to insert a new node at the head of the list
    void insertAtHead(int data){
        // create a new node with given data
        Node* new_node = new Node(data);
        // check if node is empty.
        // Update pointers to insert new node at the head.
        new_node -> next = head;
        head = new_node;
    }

    void insertAtTail(int data){
        // creation of new node.
        Node* newNode = new Node(data);
        // if there is no node make newNode to head
        if(head == nullptr){
            head = newNode;
            return;
        }
        // iterator
        Node* current = head;
        // iterating from head to nullptr
        while(current -> next != nullptr){
            current = current -> next;
        }
        //adding newNode at the end of list.
        current -> next = newNode;
    }

    void insertAtSpecificPosition(int data, int position){
        //making a new node.
        Node* newNode = new Node(data);
        // if head is nullptr then make new node to head.
        if(position == 0){
            head = newNode;
        }
        // keeping a iterator.
        Node* current = head;

        // 0 index based linked list.
        int current_pos = 0;
        // iterating untill we do not come across our specific node.
        while(current_pos != position - 1){
            current = current -> next;
            current_pos++;
        }
        // making new node points to next node
        newNode -> next = current -> next;
        // current node points to new node.
        current -> next = newNode;
    }

    void updateAtPosition(int data, int position){
        Node* current = head;
        int current_pos = 0;

        while(current_pos != position){
            current = current -> next;
            current_pos++;
        }
        current -> data = data;
    }

    void deleteAtHead(){
        Node* current = head;
        head = head -> next;
        delete(current);
    }

    void deleteAtTail(){
        // if there is no node
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        // if we have only one node
        else if(head -> next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* prev = nullptr;
        Node* current = head;;

        // iterate till null pointer.
        while(current -> next != nullptr){
            // store current node into prev node
            prev = current;
            // update current node
            current = current -> next;
        }
        if(prev != nullptr){
            prev -> next = nullptr;
            delete current;
        }
    }
    
    void deleteAtPosition(int pos){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        else if(pos == 0){
            Node* temp = head;
            head = head -> next;
            delete temp;
            return;
        }

        // taking two pointers
        Node* current = head;
        Node* prev = nullptr;

        int current_pos = 0;

        while(current_pos < pos && current != nullptr){
            prev = current;
            current = current -> next;
            current_pos++;
        }

        // check if the specified position is out of bounds
        if(current_pos < pos){
            cout << "Position out of bounds." << endl;
            return;
        }

        // delete the node at the specified position
        if(prev != nullptr){
            prev -> next = current -> next;
            delete current;
        }
        else{
            // if prev is nullptr, it means we are deleting the head node.
            head = current -> next;
            delete current;
        }
    }

    int search(int data){
        Node* current = head;

        int current_pos = 0;
        while(current != nullptr){
            if(current -> data == data){
                return current_pos;
            }
            current = current -> next;
            current_pos++;
        }
        return -1;
    }

    int length(){
        Node* current = head;
        int count = 0;
        while(current != nullptr){
            current = current -> next;
            count++;
        }
        return count;
    }

    // Method to display the elements of the list.
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
};

int main(){
    LinkedList ll;
    
    while(true){
        cout << "Enter your choice: " << endl;
        cout << "Enter 0 to display current nodes: " << endl;
        cout << "Enter 1 for insert: " << endl;
        cout << "Enter 2 for update a node: " << endl;
        cout << "Enter 3 for delete: " << endl;
        cout << "Enter 4 for search a data: " << endl;
        cout << "Enter 5 for find the length of the linked list: " << endl;
        cout << "Enter -1 to exit: " << endl;
        cout << "\n\n\n";

        int choice; 
        cin >> choice;
        if(choice >= -1 && choice <= 6){
            if(choice == 0){
                ll.display();
            }

            if(choice == 1){
                cout << "At which position you want to insert: " << endl;
                cout << "Enter 1 for insert at beginning: " << endl;
                cout << "Enter 2 for insert at tail: " << endl;
                cout << "Enter 3 for insert at specific position: " << endl;

                int choice; cin >> choice;
                if(choice == 1){
                    cout << "Enter data to insert: " << endl;
                    int data; cin >> data;
                    ll.insertAtHead(data);
                }
                if(choice == 2){
                    cout << "Enter data to insert: " << endl;
                    int data; cin >> data;
                    ll.insertAtTail(data);   
                }
                if(choice == 3){
                    cout << "Enter the position at which you want to insert: ";
                    int pos; cin >> pos;
                    cout << "Enter the data to insert: " << endl;
                    int data; cin >> data;
                    ll.insertAtSpecificPosition(data, pos);
                }
            }

            if(choice == 2){
                cout << "Enter which positon you want to update: " << endl;
                int pos; cin >> pos;
                cout << "Enter new data: " << endl;
                int data; cin >> data;
                ll.updateAtPosition(data, pos);
            }

            if(choice == 3){
                cout << "At which position you want to delete: " << endl;
                cout << "Enter 1 for delete at beginning: " << endl;
                cout << "Enter 2 for delete at tail: " << endl;
                cout << "Enter 3 for delete at specific position: " << endl;

                int choice; cin >> choice;
                if(choice == 1){
                    ll.deleteAtHead();
                    cout << "data deleted from head." << endl;
                    cout << "\n\n";
                }
                if(choice == 2){
                    ll.deleteAtTail();
                    cout << "data deleted from tail." << endl;
                    cout << "\n\n";
                }
                if(choice == 3){
                    cout << "Enter the position at which you want to delete: ";
                    int pos; cin >> pos;
                    ll.deleteAtPosition(pos);
                    cout << "data deleted from position " << pos << endl;
                    cout << "\n\n";
                }
            }

            if(choice == 4){
                cout << "Enter data to be searched for: " << endl;
                int data; cin >> data;
                if(ll.search(data) != -1){
                    cout << "Data found at index: " << ll.search(data) << endl;
                }
                else{
                    cout << "data not found." << endl;
                }
            }
            
            if(choice == 5){
                cout << "Length of current linked list is: " << ll.length() << endl;
                cout << "\n\n";
            }

            if(choice == -1){
                break;
            }
        }
        else{
            cout << "Enter a valid digit: " << endl;
        }
    }
    
    return 0;
}
