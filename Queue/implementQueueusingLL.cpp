#include <iostream>
using namespace std;

class Node {
public:
   int data ;
   Node* next ;

public:
    Node(int value) {
        data = value ;
        next = NULL ;
    }    
};

class Queue{

   public : 
   Node *front ;   // head
   Node *rear ;    // tail
   int size ;

   Queue(){
     front = NULL ;
     rear = NULL ;
     size = 0 ;   // array implementation madhe khalun size dyaycho aapan ti yaychi ithe , as LL is dynamic not restricted in size increase dynamicaaly no need to give size
   }

   void push (int val){
     if (front == NULL && rear == NULL){
        Node* newNode = new Node(val);
        front = newNode ;
        rear = newNode ;
        size++ ;
     }
     else {
        Node* newNode = new Node(val);
        rear -> next = newNode ;
        rear = newNode ;
        size++ ;
     }
     
   }

   void pop(){
     if (front == NULL && rear == NULL){
        cout << "underflow" ;
     }

     else if (front == rear){
        delete front ;
        front = NULL ;
        rear = NULL ;
        size -- ;
     }
     else {
        Node * temp = front ;
        front = front -> next ;
        delete temp;
        size-- ;
     }
   }

   Node* getFront(){
     if (front == NULL && rear == NULL){
        return NULL ;
     }
     else {
        return front ;
     }
   }

   int getSize(){
    if (front == NULL && rear == NULL){
        return 0 ;
     }
     else 
     {
        return size ;
     }
   }

   void display() {
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
  }

};


int main(){
   Queue q ;
   q.push(10);
   q.push(20);
   q.push(30);
   q.display();

   q.pop();
   q.display();

   cout << q.getFront() -> data << endl;
   cout << q.getSize();
   
}