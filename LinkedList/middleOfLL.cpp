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

Node* middleOfLL (Node* head){

    Node* slow = head ;
    Node* fast = head ;

    while (fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next ;
        slow = slow -> next ;
    }
    return slow ;
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

    Node* mid = middleOfLL(head);

    cout << mid -> data ;

}