#include <iostream>
using namespace std; 

int main() {
    int n = 13 ;  // binary - 1101
    int i = 1 ;
    // set ith bit here 1th to 1

    n = (n | (1 << i)) ;
    cout << n ;   // 15 ->  1111 , ith bit set to 1
}
