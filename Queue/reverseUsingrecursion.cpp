#include <iostream>
#include <queue>
using namespace std ;

void reverse (queue<int>&q){
    if (q.empty()){
        return ;
    }

    int front = q.front();
    q.pop();

    reverse(q) ;
    q.push(front);
}

int main () {
    queue <int> q ;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverse(q) ;

    while (!q.empty()){
        cout << q.front() << endl ;
        q.pop();
    }
}

