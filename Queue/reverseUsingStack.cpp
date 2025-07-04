#include <iostream>
#include <queue>
#include <stack>
using namespace std ;

void print(queue <int> q) {
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop() ;
    }
}

void reverse(queue <int> &q){

    // create stack to reverse queue , as we use stack to reverse anything
    stack <int> st ;
    // put all elements from queue to stack
    while(!q.empty()){
        st.push(q.front());
        q.pop() ;
    }
    // now stack has all elements from queue
    // while retriving elements from stack we will get it in reverse order
    while (!st.empty()){
        int top = st.top() ;
        st.pop() ;
        q.push(top);  
    }

}

int main () {
    queue <int> q ;
    q.push(10) ;
    q.push(20) ;
    q.push(30) ;
    q.push(40) ;
    q.push(50) ;
    q.push(60) ;

    reverse(q);

    print(q) ;

}
