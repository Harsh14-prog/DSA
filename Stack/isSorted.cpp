#include <iostream>
#include <climits>
#include <stack>
using namespace std ;

bool isSorted(stack <int> s , int elem1){

    if (s.empty()){
        return true ;
    }

    int elem2 = s.top();  // stored top of stack (50)
    
    if (elem2 <= elem1){   // initially compared with INT_MAX
        s.pop();
        bool aagekaAns = isSorted(s , elem2);  
        s.push(elem2);    // backtracking to get whole stack as it is
        return aagekaAns ;   
        
    }
    else {  // if elem2 > elem1  nosorted stack
        return false ;
    }
}

int main(){
    stack <int> s ;
    s.push(10);
    s.push(30);
    s.push(30);
    s.push(40);
    s.push(50);

    int elem1 = INT_MAX ;

    cout <<  isSorted(s , elem1);
}
