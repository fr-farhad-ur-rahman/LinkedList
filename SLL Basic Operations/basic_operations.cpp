#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list.
template <typename T>
class Node{
public:
    T data;     // Data stored in the node
    Node *next; // Pointer to the next node in the list.

    // Constructor to initialize data and next.
    Node(T data) : data(data), next(nullptr) {}
};

// LinkedList class manages the linked list.
template <typename T>
class LinkedList{
public:
    Node<T> *head; // Pointer to the head of the list.

    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}

    // Method to insert a new node at the head of the list
    void insertAtHead(T data){
        // Create a new node with given data
        Node<T> *new_node = new Node<T>(data);
        // Update pointers to insert the new node at the head.
        new_node->next = head;
        head = new_node;
        display();
    }

    // Method to insert a new node at the tail of the list
    void insertAtTail(T data){
        // Creation of a new node.
        Node<T> *newNode = new Node<T>(data);
        // If there is no node, make newNode the head.
        if (head == nullptr){
            head = newNode;
            return;
        }
        // Iterator
        Node<T> *current = head;
        // Iterate from head to nullptr
        while (current->next != nullptr){
            current = current->next;
        }
        // Add newNode at the end of the list.
        current->next = newNode;
        display();
    }

    // Method to insert a new node at a specific position in the list
    void insertAtSpecificPosition(T data, int position){
        // Create a new node.
        Node<T> *newNode = new Node<T>(data);
        // If the head is nullptr, make the new node the head.
        if (position == 0){
            head = newNode;
        }
        // Iterator
        Node<T> *current = head;

        // 0-index based linked list.
        int current_pos = 0;
        // Iterate until we come across our specific node.
        while (current_pos != position - 1){
            current = current->next;
            current_pos++;
        }
        // Make the new node point to the next node.
        newNode->next = current->next;
        // Make the current node point to the new node.
        current->next = newNode;
        display();
    }

    // Method to update the data at a specific position in the list
    void updateAtPosition(T data, int position){
        Node<T> *current = head;
        int current_pos = 0;

        // Iterate until the specified position.
        while (current_pos != position){
            current = current->next;
            current_pos++;
        }
        // Update the data at the specified position.
        current->data = data;
        display();
    }

    // Method to delete the node at the head of the list
    void deleteAtHead(){
        Node<T> *current = head;
        head = head->next;
        delete current;
        display();
    }

    // Method to delete the node at the tail of the list
    void deleteAtTail(){
        // If there is no node.
        if (head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        // If we have only one node.
        else if (head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node<T> *prev = nullptr;
        Node<T> *current = head;
        

        // Iterate until null pointer.
        while (current->next != nullptr){
            // Store the current node in the prev node.
            prev = current;
            // Update the current node.
            current = current->next;
        }
        if (prev != nullptr){
            prev->next = nullptr;
            delete current;
        }
    }

    // Method to delete the node at a specific position in the list
    void deleteAtPosition(int pos){
        if (head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        else if (pos == 0){
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Two pointers
        Node<T> *current = head;
        Node<T> *prev = nullptr;

        int current_pos = 0;

        // Iterate until the specified position or the end of the list.
        while (current_pos < pos && current != nullptr){
            prev = current;
            current = current->next;
            current_pos++;
        }

        // Check if the specified position is out of bounds.
        if (current_pos < pos){
            cout << "Position out of bounds." << endl;
            return;
        }

        // Delete the node at the specified position.
        if (prev != nullptr){
            prev->next = current->next;
            delete current;
        }
        else{
            // If prev is nullptr, it means we are deleting the head node.
            head = current->next;
            delete current;
        }
    }

    // Method to search for an element in the list
    int search(T data){
        Node<T> *current = head;

        int current_pos = 0;
        // Iterate through the list.
        while (current != nullptr){
            // If the data is found, return the position.
            if (current->data == data){
                return current_pos;
            }
            current = current->next;
            current_pos++;
        }
        // If data is not found, return -1.
        return -1;
    }

    // Method to get the length of the linked list
    int length(){
        Node<T> *current = head;
        int count = 0;
        // Iterate through the list and count nodes.
        while (current != nullptr){
            current = current->next;
            count++;
        }
        return count;
    }

    // Method to reverse the linked list
    void reverse(){
        Node<T> *current = head;
        Node<T> *prev = nullptr;
        Node<T> *next = nullptr;

        // Iterate through the list and reverse pointers.
        while (current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        // Update the head pointer.
        head = prev;
        display();
    }

    // Method to display the elements of the list.
    void display(){
        Node<T> *current = head;

        // Traverse the list and print each element.
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        // Print "NULL" to indicate the end of the list.
        cout << "NULL" << endl;
    }
};

// Function to display options for data types
void displayDataTypeOptions(){
    cout << "Choose Data Type for Linked List:" << endl;
    cout << "1. Integer" << endl;
    cout << "2. Double" << endl;
    cout << "3. Character" << endl;
    cout << "4. String" << endl;
    // Add more data types as needed
}

void displayOptions(){
    cout << "\nLinked List Operations:" << endl;
    cout << "1. Insert at the Beginning" << endl;
    cout << "2. Insert at the End" << endl;
    cout << "3. Insert at Specific Position" << endl;
    cout << "4. Update Element at Position" << endl;
    cout << "5. Delete from the Beginning" << endl;
    cout << "6. Delete from the End" << endl;
    cout << "7. Delete at Specific Position" << endl;
    cout << "8. Search for an Element" << endl;
    cout << "9. Display Linked List" << endl;
    cout << "10. Get Length of Linked List" << endl;
    cout << "11. Reverse Linked List" << endl;
    cout << "0. Exit" << endl;
}

// Main application
int main(){
    int dataTypeChoice;
    cout << "Welcome to the linked list program!" << endl;

    // Options for data types
    displayDataTypeOptions();
    cout << "Enter your choice for data type: ";
    cin >> dataTypeChoice;

    switch (dataTypeChoice){
    case 1:{
        LinkedList<int> intList;
        int choice, data, position;

        do{
            displayOptions();

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice){
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                intList.insertAtHead(data);
                cout << "Element " << data << " inserted at the beginning." << endl;
                break;

            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                intList.insertAtTail(data);
                cout << "Element " << data << " inserted at the end." << endl;
                break;

            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                intList.insertAtSpecificPosition(data, position);
                cout << "Element " << data << " inserted at position " << position << "." << endl;
                break;

            case 4:
                cout << "Enter new data: ";
                cin >> data;
                cout << "Enter position to update: ";
                cin >> position;
                intList.updateAtPosition(data, position);
                cout << "Element at position " << position << " updated to " << data << "." << endl;
                break;

            case 5:
                intList.deleteAtHead();
                cout << "Element at the beginning deleted." << endl;
                break;

            case 6:
                intList.deleteAtTail();
                cout << "Element at the end deleted." << endl;
                break;

            case 7:
                cout << "Enter position to delete: ";
                cin >> position;
                intList.deleteAtPosition(position);
                cout << "Element at position " << position << " deleted." << endl;
                break;

            case 8:
                cout << "Enter data to search: ";
                cin >> data;
                position = intList.search(data);
                if (position != -1){
                    cout << "Element " << data << " found at position " << position << "." << endl;
                }
                else{
                    cout << "Element " << data << " not found in the list." << endl;
                }
                break;

            case 9:
                cout << "Linked List: ";
                intList.display();
                break;

            case 10:
                cout << "Length of the linked list: " << intList.length() << endl;
                break;

            case 11:
                intList.reverse();
                cout << "Linked List reversed." << endl;
                break;

            case 0:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 0);

        break;
    }
    case 2:{
        LinkedList<double> intList;
        double data;
        int choice, position;

        do{
            displayOptions();

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice){
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                intList.insertAtHead(data);
                cout << "Element " << data << " inserted at the beginning." << endl;
                break;

            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                intList.insertAtTail(data);
                cout << "Element " << data << " inserted at the end." << endl;
                break;

            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                intList.insertAtSpecificPosition(data, position);
                cout << "Element " << data << " inserted at position " << position << "." << endl;
                break;

            case 4:
                cout << "Enter new data: ";
                cin >> data;
                cout << "Enter position to update: ";
                cin >> position;
                intList.updateAtPosition(data, position);
                cout << "Element at position " << position << " updated to " << data << "." << endl;
                break;

            case 5:
                intList.deleteAtHead();
                cout << "Element at the beginning deleted." << endl;
                break;

            case 6:
                intList.deleteAtTail();
                cout << "Element at the end deleted." << endl;
                break;

            case 7:
                cout << "Enter position to delete: ";
                cin >> position;
                intList.deleteAtPosition(position);
                cout << "Element at position " << position << " deleted." << endl;
                break;

            case 8:
                cout << "Enter data to search: ";
                cin >> data;
                position = intList.search(data);
                if (position != -1){
                    cout << "Element " << data << " found at position " << position << "." << endl;
                }
                else{
                    cout << "Element " << data << " not found in the list." << endl;
                }
                break;

            case 9:
                cout << "Linked List: ";
                intList.display();
                break;

            case 10:
                cout << "Length of the linked list: " << intList.length() << endl;
                break;

            case 11:
                intList.reverse();
                cout << "Linked List reversed." << endl;
                break;

            case 0:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 0);

        break;
    }
    case 3:{
        LinkedList<char> intList;
        char data;
        int choice, position;

        do{
            displayOptions();

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice){
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                intList.insertAtHead(data);
                cout << "Element " << data << " inserted at the beginning." << endl;
                break;

            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                intList.insertAtTail(data);
                cout << "Element " << data << " inserted at the end." << endl;
                break;

            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                intList.insertAtSpecificPosition(data, position);
                cout << "Element " << data << " inserted at position " << position << "." << endl;
                break;

            case 4:
                cout << "Enter new data: ";
                cin >> data;
                cout << "Enter position to update: ";
                cin >> position;
                intList.updateAtPosition(data, position);
                cout << "Element at position " << position << " updated to " << data << "." << endl;
                break;

            case 5:
                intList.deleteAtHead();
                cout << "Element at the beginning deleted." << endl;
                break;

            case 6:
                intList.deleteAtTail();
                cout << "Element at the end deleted." << endl;
                break;

            case 7:
                cout << "Enter position to delete: ";
                cin >> position;
                intList.deleteAtPosition(position);
                cout << "Element at position " << position << " deleted." << endl;
                break;

            case 8:
                cout << "Enter data to search: ";
                cin >> data;
                position = intList.search(data);
                if (position != -1){
                    cout << "Element " << data << " found at position " << position << "." << endl;
                }
                else{
                    cout << "Element " << data << " not found in the list." << endl;
                }
                break;

            case 9:
                cout << "Linked List: ";
                intList.display();
                break;

            case 10:
                cout << "Length of the linked list: " << intList.length() << endl;
                break;

            case 11:
                intList.reverse();
                cout << "Linked List reversed." << endl;
                break;

            case 0:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 0);

        break;
    }
    case 4:{
        LinkedList<string> intList;
        string data;
        int choice, position;
        do{
            displayOptions();

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice){
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                intList.insertAtHead(data);
                cout << "Element " << data << " inserted at the beginning." << endl;
                break;

            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                intList.insertAtTail(data);
                cout << "Element " << data << " inserted at the end." << endl;
                break;

            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                intList.insertAtSpecificPosition(data, position);
                cout << "Element " << data << " inserted at position " << position << "." << endl;
                break;

            case 4:
                cout << "Enter new data: ";
                cin >> data;
                cout << "Enter position to update: ";
                cin >> position;
                intList.updateAtPosition(data, position);
                cout << "Element at position " << position << " updated to " << data << "." << endl;
                break;

            case 5:
                intList.deleteAtHead();
                cout << "Element at the beginning deleted." << endl;
                break;

            case 6:
                intList.deleteAtTail();
                cout << "Element at the end deleted." << endl;
                break;

            case 7:
                cout << "Enter position to delete: ";
                cin >> position;
                intList.deleteAtPosition(position);
                cout << "Element at position " << position << " deleted." << endl;
                break;

            case 8:
                cout << "Enter data to search: ";
                cin >> data;
                position = intList.search(data);
                if (position != -1){
                    cout << "Element " << data << " found at position " << position << "." << endl;
                }
                else{
                    cout << "Element " << data << " not found in the list." << endl;
                }
                break;

            case 9:
                cout << "Linked List: ";
                intList.display();
                break;

            case 10:
                cout << "Length of the linked list: " << intList.length() << endl;
                break;

            case 11:
                intList.reverse();
                cout << "Linked List reversed." << endl;
                break;

            case 0:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 0);

        break;
    }

    default:
        cout << "Invalid data type choice. Exiting the program." << endl;
        break;
    }

    return 0;
}
