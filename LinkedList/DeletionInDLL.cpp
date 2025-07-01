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

void print(Node* head){
    Node* temp = head ;
    while(temp != NULL){
        cout << temp -> data  << "->" ;
        temp = temp -> next ;
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

void deleteFromPosition(int position ,  Node* &head , Node* &tail){
    // if LL is empty
    if (head  == NULL && tail == NULL){
        cout << "No Node to delete";
        return ;
    }

    // only 1 node is present
    else if (head == tail){
        Node* temp = head ;
        head = NULL ;
        tail = NULL ;
        delete temp ; // heap memory deleted
    }

    else if (position == 1){
        // want to delete head node
        Node* temp = head ;
        head = temp -> next ;
        head -> prev = NULL ;
        temp -> next = NULL ;
        delete temp ;
    }

    else {
        // multiple nodes inside LL
        Node* temp = head ;
        for (int i = 0 ; i < position - 2 ; i++){
            temp = temp -> next ;
        }

        Node* current = temp -> next ;
        Node* forward = current -> next ;
        if (forward != NULL) {
            forward->prev = temp; 
        } 
        else { 
           
            tail = temp;   // can be handled in seprate case of delete tail i.e position == length
        }
        temp -> next = forward ; 
        // forward -> prev = temp ;
        current -> prev = NULL ;
        current -> next = NULL ;
        delete current ;
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

    deleteFromPosition(4 , head , tail);
    print(head);

}