#include <iostream>
using namespace std ;

bool isOdd(int n){
    if (n & 1 != 0){
        // 1st bit(from right 0th bit) of odd no is 1 so with &1 it will become 1 , if become 0 then no. is even
        return true ;
    }
    else {
        return false ;
    }
}

int main (){
    int n = 13 ;
    bool ans = isOdd(n);
    cout << ans ;
    
}