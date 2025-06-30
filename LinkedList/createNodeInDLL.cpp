#include <iostream>
using namespace std ;

class Node 
{
    public:
    int data ;
    Node* prev ;
    Node* next ;

    Node(int value){
        this -> data = value ;
        this -> prev = NULL ;
        this -> next = NULL ;
    }
};

void insertAtHead(int value , Node* &head , Node* &tail){
    // LL is empty
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode ;
        tail = newNode ;
    }
    // if node is already present
    else {
        Node* newNode = new Node(value);
        newNode ->next = head ;
        head ->prev = newNode ;
        head = newNode ;
    }
}

void print(Node* head){
    Node* temp = head ;
    while(temp != NULL){
        cout << temp -> data  << "->" ;
        temp = temp -> next ;
    }
    cout << "NULL" << endl ;
}

void printReverse(Node* tail){
  Node* temp = tail ;

  while(temp != NULL){
    cout << temp -> data << "->";
    temp = temp -> prev ;
  }
  cout << "NULL" << endl ;
}

void insertAtTail(int value , Node* &head , Node* &tail ){
    // LL is empty
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode ;
        tail = newNode ;
    }

    // LL is not empty
    else {
        Node* newNode = new Node(value);
        tail -> next = newNode ;    
        newNode -> prev = tail ;    
        tail = newNode ;
    }
}

int getLength(Node* head){
    Node* temp = head ;
    int count = 0 ;

    while(temp != NULL){
        temp = temp -> next ;
        count ++ ;
    }
    return count ;
}

void insertAtPosition(int position , int value , Node* &head , Node* &tail){
    // 3 case ->> rightmost end , leftmost end , center
    int len = getLength(head);

    if (position == 1){
        insertAtHead(value , head , tail);
    }

    else if(position == len + 1){
       insertAtTail(value , head , tail);
    }

    else {
        // in between , other than head and tail position
        Node* temp = head ;
        for (int i = 0 ; i < position - 2 ; i++){  
            temp = temp -> next ;
        }
        Node* newNode = new Node(value);
        Node* forward = temp -> next ;
        temp -> next = newNode ;   
        newNode -> prev = temp ;
        newNode -> next = forward ;
        forward -> prev = newNode ;

    }
}


int main (){

    Node* head  = NULL ;
    Node* tail = NULL ;

    insertAtTail(10 , head , tail) ;
    insertAtTail(20 , head , tail) ;
    insertAtTail(30 , head , tail) ;
    insertAtTail(40 , head , tail) ;
    print(head);

    insertAtPosition(4 , 404 , head , tail);
    print(head);
}