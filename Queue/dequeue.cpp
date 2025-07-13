#include <iostream>
using namespace std ;

class deque {

    private :

    int *arr ;
    int n ;
    int front ;
    int rear  ;

    public : 
    deque(int size) {

        arr = new int[size] ;
        this -> n = size ;
        front = -1 ;
        rear = -1 ;
    }

    void pushFront(int value) {
      if (front == 0) {
        // means left side la we do not have place for insertion of element
        cout << "overflow" << endl ;
      } 

      else if (front == -1 && rear == -1) {
        // initially queue is empty
        front ++ ;
        arr[front] = value ;
        rear ++ ;
      }

      else {
        // normal insertion from front
        front -- ;   // eg : 10 0 0 0 0 ata front la push mhanje 10 chya aadi push value so currently our front is on 10 so we will do front -- to go before 10 as we want to push val at before 10
        arr[front] = value ;
      }
    }

    void popFront() {
       // same as pop from front in normal queue 
       if (front == -1 && rear == -1) {
        cout << "underflow" ;
       }

       else if (front == rear) {
         arr[front] = 0 ;
         front = -1 ;
         rear = -1 ;
       }

       else {
        arr[front] = 0 ;
        front ++ ;
       }
    }

    void pushBack(int value) {
        // this is same as push from rear in normal queue
        if (rear == n-1){
            cout << "overflow" ;
        }
        else if (front == -1 && rear == -1){
            rear ++ ;
            arr[rear] = value ;
            front ++ ;
        }
        else {
            rear ++ ;
            arr[rear] = value ;
        }
    }

    void popBack() {
        if (front == -1 && rear == -1) {
            cout << "underflow" << endl ;
        }

        else if (front == rear){
            // single element
            arr[rear] = 0 ;
            front = -1 ;
            rear = -1 ;
        }

        else {
            // normal pop from back
            arr[rear] = 0 ;
            rear -- ;
        }
    }

    void print () {
        for (int i = 0 ; i < n ; i++) {
            cout << arr[i] << " " ;
        }
        cout << endl ;
    }
    
} ;

int main () {
    deque dq(6) ;

    dq.pushFront(10) ;  // on 0 index we have 10 now for again push from front we will do front -- it will go to -1 so for again push from front underflow will be there
    dq.print() ; // 10 0 0 0 0 0 aaplyakade evdi void space asun underflow will be here in push front so will use circular queue concept
    dq.pushFront(20) ;  // front madhun we can do only 1 time push
    dq.print() ;  // code is wasting memory

    dq.pushBack(13) ;
    dq.print() ;
    dq.pushBack(16) ;
    dq.print() ;

    // dq.popBack();
    // dq.print() ;
    // dq.popBack();
    // dq.print() ;

    // dq.popBack();
    // dq.print() ;

    // dq.popBack();
    // dq.print() ;

    // front popping

    dq.popFront();
    dq.print() ;
    dq.popFront();
    dq.print() ;

    dq.popFront();
    dq.print() ;

    dq.popFront();
    dq.print() ;
}