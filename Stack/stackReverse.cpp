#include <iostream>
#include <stack>
using namespace std ;

void printStack(stack <int> s){
    while (!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << endl ;
}

void insertatBottom(stack <int>& s , int value){
    // base case 
    if (s.empty()){
        s.push(value) ;
        return ;
    }

    int topH = s.top();
    s.pop() ;

    insertatBottom(s , value);

    // backtrack
    s.push(topH);
}

void ReverseStack(stack <int> &s){

    // base case
    if (s.empty()){
        return ;
    }

    int initialTop = s.top() ;
    s.pop() ;

    ReverseStack(s);

    insertatBottom(s , initialTop);

}

int main (){
    stack <int> s ;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    printStack(s);

    ReverseStack(s);
    printStack(s);

}