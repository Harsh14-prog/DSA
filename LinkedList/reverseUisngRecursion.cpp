#include <iostream>
using namespace std ;

class Node{
  public:
     int data ;
     Node * next ;

     Node(int value){
        data = value ;
        next = NULL ;
     }
};

void insertAtHead(int value , Node* &head , Node* &tail){
  
    if (head == NULL && tail == NULL){
        Node* newNode = new Node(value) ;
        head = newNode ;
        tail = newNode ;
    }
    else{
        Node* newNode = new Node(value);
        newNode -> next = head ;
        head = newNode ;
    }
}

Node* reverseLL (Node* current , Node* prev){

    if (current == NULL){
        return prev ;
    }
    
    Node* forward = current -> next ;
    current -> next = prev ;

    prev = current ;
    current = forward ;

    Node* reverseHead = reverseLL(current , prev);  
    return reverseHead ; 
}

void print(Node* head){
    Node* temp = head ;
    while (temp != NULL){
        cout << temp -> data << "->" ;
        temp = temp -> next ;
    }
    cout << "NULL";
}

int main (){
    Node* head = NULL ;
    Node* tail = NULL ;
    insertAtHead(10 , head , tail);
    insertAtHead(20 , head , tail);
    insertAtHead(30 , head , tail);
    insertAtHead(40 , head , tail);
    insertAtHead(50 , head , tail);
    insertAtHead(60 , head , tail);

    cout << "previous head : " << head -> data << endl ;

    Node* prev = NULL ;
    Node* current = head ;

    Node* reversedHead = reverseLL(head , prev);
    cout << "head after reverse : " <<  reversedHead -> data << endl ;

    cout << "reversed list is : " << endl ;
    print(reversedHead);

}