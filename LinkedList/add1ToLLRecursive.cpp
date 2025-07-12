#include <iostream>
using namespace std ;

class Node {
  
    public :
    int data ;
    Node* next ;

    Node(int value) {
       this -> data = value ;
       this -> next = NULL ;
    }
};

// Function to print Linked List
void print(Node* head){
    Node* temp = head ;
    while(temp != NULL){
       cout << temp -> data << " -> " ;
       temp = temp -> next ;
    }
    cout << "NULL" << endl ;
}

int solve (Node* head , int carry) {

    // base case --
    if (head == NULL) {
        return carry ;
    }

    int newCarry = solve(head -> next , carry);  

    // backtracking
    int sum = head -> data + newCarry ;
    head -> data = sum % 10 ;
    return sum / 10 ;   
}

int main () {
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    cout << "Original Linked List: ";
    print(head);

    int carry = 1 ;

    int finalCarry = solve(head , carry);

    if (finalCarry > 0) {
        Node* newNode = new Node(carry) ;
        newNode -> next = head ;
        head = newNode ;
    }

    cout << "ans of addition is :" ;
    print(head);
}