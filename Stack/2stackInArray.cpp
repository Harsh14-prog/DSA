#include <iostream>
#include <stack>
using namespace std ;

class Stack {

public :
    int* arr ;
    int size ;
    int top1 ;
    int top2 ;

    Stack(int capacity){
        arr = new int[capacity] ;
        size = capacity ;
        top1 = -1 ;
        top2 = size ;   // size-1 i.e last ele of array chya pn 1 index baher initially
    }

    void push1(int value){
        // first check either we have space to push the element or not 
        // else stack will be overflow
        if (top2 - top1 == 1){
            // means stack is full
            cout << "stack is full , stack overflow will be happen";
        }
        else {
            // stack madhe ajun jaga aahe for push
            top1++ ;
            arr[top1] = value ;
        }
    }

    void push2(int value){
       if (top2 - top1 == 1){
         cout << "stack overflow" ;
       }

       else {
         top2 -- ;
         arr[top2] = value ;
       }
    }

    void pop1(){
      // if stack is empty stack underflow will be there
      // if elem is there inn stack then only we can pop
      if (top1 == -1){
        cout << "stack underflow" ;
      }
      else {
        arr[top1] = 0 ;
        top1 -- ;
      }
    }

    void pop2(){
       if (top2 == size){  // means stack2 is empty no element to pop
          // means stack2 is empty
          // top2 jas jas khali move hot jato tas tas stack2 fill hot jat
          cout << "stack underflow" ;
       }

       else{
        arr[top2] = 0 ;
        top2 ++ ;
       }
    }

    void printStack(){
        cout << "top1 is : " << top1 << endl;
        cout << "top2 is : " << top2 << endl ;

        for (int i = 0 ; i < size ; i++){
            cout << arr[i] << " " ;
        }
        cout << endl ;
    }

};

int main (){

  Stack s(8) ;
  s.printStack();   

  s.push1(10) ;
  s.printStack();

  s.push2(20);
  s.printStack();  

  s.push2(30);
  s.printStack();
  s.push2(50);
  s.printStack();

  s.push1(60) ;
  s.printStack();
  s.push1(70) ;
  s.printStack();
  s.push1(80) ;
  s.printStack();

//   s.pop2() ; // 80 will be popped

  s.pop1() ;
  s.printStack();

}