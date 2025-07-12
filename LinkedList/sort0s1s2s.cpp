#include <iostream>
using namespace std ;

class Node 
{
    public :
    int data ;
    Node* next ;

    Node(int value){
        this -> data = value ;
        this -> next = NULL ;
    }
};


Node* sortLL(Node* &head) {
    Node* zeroHead = new Node(-1) ;
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead ;
    Node* one = oneHead ;
    Node* two = twoHead ;

    Node* temp = head ;

    while (temp != NULL) {

        if (temp -> data == 0) {
           zero -> next = temp ;
           zero = temp ;
        }

        else if (temp -> data == 1) {
            one -> next = temp ;
            one = temp ;
        }
        else {
            two -> next = temp ;
            two = temp ;
        }
        temp = temp -> next ;
    }

    zero -> next = oneHead -> next ? oneHead -> next : twoHead -> next ;
    one -> next = twoHead -> next ;
    two -> next = NULL ;

    Node * newHead = zeroHead -> next ;

    delete zeroHead ;
    delete oneHead ;
    delete twoHead ;

    return newHead ;

}


// Function to print Linked List
void print(Node* head){
    Node* temp = head ;
    while(temp != NULL){
       cout << temp -> data << " -> " ;
       temp = temp -> next ;
    }
    cout << "NULL" << endl ;
}

int main () {
   
    // Original unsorted Linked List
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(0);

    cout << "Original Linked List: ";
    print(head);

    Node* ans = sortLL(head);
    print(ans);
}