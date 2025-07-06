#include <iostream>
using namespace std ;

class Node{
  public:
     int data ;
     Node * next ;
     Node* prev ;

     Node(int value){
        data = value ;
        next = NULL ;
        prev = NULL ;
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
        head -> prev = newNode ;
        head = newNode ;
    }
}

// Node* reverse(Node* head){
//     Node* temp = NULL ;
//     Node* current = head ;
//     Node* forward = current -> next ;

//    while (){
//       current -> next = temp ;
//       current -> prev = forward ;
//       forward -> next = current ;

//       current = current -> next ;

//    }
// }


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

    print(head);

}