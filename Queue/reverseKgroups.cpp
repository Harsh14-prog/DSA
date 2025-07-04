#include <iostream>
#include <queue>
#include <stack>
using namespace std ;

void reverse(queue <int> &q , int k , int count){

    // base case
    if (count < k){
        for(int i = 0 ; i < count ; i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        return;    // always make return from base case , o/w fun will run infinitely
    }

    stack <int> st ;

    for (int i = 0 ; i < k ; i++){
        int front = q.front();
        q.pop();
        st.push(front);
    }

    while (!st.empty()){
        int top = st.top();
        st.pop();
        q.push(top);
    }

    reverse(q , k , count - k);

}

int main () {
    queue <int> q ;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);

    int k = 3 ;
    int count = q.size() ;

    reverse(q , k , count);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
