#include <iostream>
using namespace std ;

int main(){

    // int a = 6 ;
    // int b = 5 ;

    // cout << "Before swapping: " << a << " " << b << endl ;

    // int temp = a ;
    // a = b ;
    // b = temp ;

    // cout << a << " " << b ;

    // using xor --

    int a = 6 ;
    int b = 5 ;

    a = a ^ b ;
    b = a ^ b ;
    a = a ^ b ;

    cout << a << " " << b ;
}