#include <iostream>
using namespace std ;

class Node 
{
    public:
    int data ;
    Node* next ;

    Node(int value){
        this -> data = value ;
        this -> next = NULL ;
    }
};

void insertAtTail(int value , Node* &head , Node* &tail){
    if (head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode ;
        tail = newNode ;
    }

    else {
        Node* newNode = new Node(value);
        tail->next = newNode ;
        tail = newNode ;
    }
   
}

int getLength(Node* head){

    Node* temp = head ;
    int length = 0 ;
    while(temp != NULL){

        temp = temp -> next ;
        length ++ ;

    }
    return length ;
}

void print(Node* head){

    Node* temp = head ;
    while(temp != NULL){

        cout << temp-> data << "->";
        temp = temp->next ;
    }
    cout << "NULL" << endl ;
}

int search(int target , Node* head){
    Node* temp = head ;
    int position = 1 ;
    while(temp != NULL){
        
        if (temp -> data == target){
            return position ;
        }
        else {
            temp = temp -> next ;
            position ++ ;
        }
    }
    
    return -1 ;
}



int main(){
  
    Node* head = NULL ;
    Node* tail = NULL ;
   
    insertAtTail(110, head , tail);
    insertAtTail(210, head , tail);
    insertAtTail(310, head , tail);
    insertAtTail(410, head , tail);
    print(head);

    int ans =  search(310 , head);
    cout << "target found at position : "<< ans ;
    
}