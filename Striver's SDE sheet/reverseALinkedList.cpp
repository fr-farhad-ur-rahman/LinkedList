#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

int main(){
    Node* head = new Node();
    head -> data = 10;
    cout << head -> data << endl;
    return 0;
}