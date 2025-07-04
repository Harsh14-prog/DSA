#include <iostream>
using namespace std ;

class queue {
    private :
    int *arr ;
    int size ;
    int front ;
    int rear ;

    public  :
    // constructor
     queue(int size){
      arr = new int[size];
      size = size ;
      front = -1 ;
      rear = -1;
    }

    void push(int value){
        // insertion case
        if (rear == size - 1){
            cout << "queue overflow" ;
        }

        else if (rear == -1 && front == -1){
            // initially queue is empty , we inserted first single element here
            rear ++ ;
            arr[rear] = value ;
            front ++ ;  // front la start la ++ nahi kel tr we can not give front of queue as to -1 vrch rahil always
        }

        else {
            // normal insertion , single element placement zaliye ata don't move front , only move rear and do placement
            rear ++ ;
            arr[rear] = value ;
        }
    }

    void pop(){
        // if queue is empty
        if (front == -1 && rear == -1) {
            cout << "queue underflow";
        }

        // pop a single element
        else if (front == rear){
            arr[front] = 0 ;
            front = -1 ;   // queue empty zali aahe so front and rear -1 jayla pahijet
            rear = -1 ;
        }

        // normal pop 
        else {
            arr[front] = 0 ;
            front ++ ;
        }
    }

    int getfront(){
        
        // jr front exist ch krt nasel tr , hence first checked either front is there or not
        if (front == -1){
            cout << "front does not exist" ;
        }

        else {
            return arr[front] ;
        }
    }

    int getrear(){

        if (front == -1){
            cout << "front does not exist" ;
        }

        else {
            return arr[rear];
        }
    }

    int getsize(){
        // number of elements in queue

        if (front == -1 && rear == -1) {
            return 0 ;  // size is 0
        }

        else {
            return rear - front + 1 ;
        }
        
    }

    bool isEmpty(){

        if (front == -1 && rear == -1) {
            cout << "queue is empty";
            return true ;
        }
        else {
            return false ;
        }
    }


};

int main (){
  
    queue q(10);

    q.push(10) ;
    q.push(20) ;
    q.push(30) ;
    q.push(40) ;
    q.push(50) ;
    
   cout << q.getsize() << endl ;

   q.pop();
   q.pop();
   q.pop();

   cout << q.getfront() << endl ;

   q.pop();
   q.pop();
  

   cout << q.getsize() << endl ;

   
}