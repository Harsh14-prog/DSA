#include <iostream>
using namespace std ;

class cicular {
    private : 

    int *arr ;
    int n ;
    int front ;
    int rear ;

    public :

    cicular(int size){

        arr = new int[size] ;
        this -> n = size ;
        front = -1 ;
        rear = -1 ;
    }

    void push(int val){
      // in circular 4 case -->>> normal insertion , overflow , first(single) element , circular nature

      if (front == 0 && rear == n-1 || rear == front - 1){
        cout << "overflow" << endl ;
      }

      else if (front == -1 && rear == -1) {
        // first element push
        rear ++ ;
        arr[rear] = val ;
        front ++ ;
      }

      else if (rear == n-1 && front != 0 ) {
        // circular nature
        rear = 0 ;
        arr[rear] = val ;  // deu to this circular nature see in overflow condn rear = front - 1 will happen
      }

      else {
        // normal insertion
        rear ++ ;
        arr[rear] = val ;
      } // ya case mule rear ++ hot jatay tyat val push hot jatey shevti rear = n- 1 zal ki we check either front == 0 if yes then overflow will be there
      // as both front and end are at extreme boundry , if front is not at 0 then there is still left space at left end befor
      // front so 3rd else if block will execute and circular insertion takes place
      // at end rear will goes to front - 1 at queue will be full now
    }

    void pop(){
      // in circular 4 case -->>> normal insertion , underflow , first(single) element , circular nature
      if(front == -1 && rear == -1) {
        cout << "underflow" ;
      }

      else if (front == rear){
        // pop krt krt aapan jevha single element vr pochto tevha
        arr[front] = 0 ;
        front = -1 ;
        rear = -1 ;
      }

      else if (front == n-1){   // rear could be at start deu to circular nature
        // cicular nature
        arr[front] = 0 ;
        front = 0 ;    // to pop ele at back where rear is pointing

      }

      else {
        // normal pop
        arr[front] = 0 ;
        front ++ ;
      }
    }

    int getsize(){
       if (front == -1 && rear == -1) {
         return 0 ;
       }
       else if (rear > front) {
         // normal size no circular is there
         return rear - front + 1 ;
       }

       else {
         // front > rear , rear is at left before front due to circular
         return (n - front) + (rear + 1);
       }
    }

    int getFront(){
       
        if (front == -1) {
            cout << "queue is empty" <<endl ;
            return 0 ;
        }
        else {
            return arr[front] ;
        }
    }

    bool isEmpty(){

      if (front == -1 && rear == -1) {
        return true ;
      }

      else {
         return false ;
      }
    }

    void print () {
        for (int i = 0 ; i < n ; i++) {
            cout << arr[i] << " " ;
        }
        cout << endl ;
    }


};

//  First, remember — this is a circular queue.
// So even though array visually looks like a straight line:

// [0] [1] [2] [3] [4]
// In logic, it's like a circle:


// [0] ←→ [1] ←→ [2] ←→ [3] ←→ [4] ←→ back to [0]
// ✅ Real situation: Insert–Pop–Insert again
// Let’s go through a real example:

// Queue of size n = 5
// Initial:

// front = -1, rear = -1

// 🟢 Step 1: Push 5 items
// Push: 10, 20, 30, 40, 50

// Now:

// Index	Value
// 0	10
// 1	20
// 2	30
// 3	40
// 4	50
// front = 0, rear = 4

// 🔴 Step 2: Pop 3 items
// Now you pop 3 elements:

// front = 3, rear = 4

// Only 2 elements left in queue: 40, 50

// 🟢 Step 3: Push 2 more items
// You try to push new values

// Rear is at 4 → can't go further, so you wrap around to rear = 0 and insert

// Then rear = 1 and insert again

// Now your array looks like:

// Index	Value
// 0	60
// 1	70
// 2	0
// 3	40
// 4	50
// Now:

// front = 3

// rear = 1

// 🧠 Now when you pop, you’ll go:
// front = 3 → pop → front = 4

// front = 4 → pop → front = 0 ✅ ✅

// See? After reaching front == 4 (n-1), we know next element might be at index 0 — so we check:


// if (front == n - 1)
//     front = 0; // wrap around

int main (){
  cicular cq(5) ;

  cq.push(1) ;
  cq.print() ;
  cq.push(1) ;
  cq.print() ;
  cq.push(1) ;
  cq.print() ;
  cq.push(1) ;
  cq.print() ;
  cq.push(1) ;
  cq.print() ;
  cq.push(1) ;
  cq.print() ;

  cq.pop();
  cq.print();
  cq.pop();
  cq.print();
  cq.pop();
  cq.print();

  cq.push(10) ;
  cq.print() ;
  cq.push(20) ;
  cq.print() ;

  cq.pop();
  cq.print();
  cq.pop();
  cq.print();  // with this pop front has gone to front = 0 due to cicular queue so popping will again start from start

  cq.pop();  // this pop will remove ele from start cicular queue
  cq.print();
  
}