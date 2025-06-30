// #include <iostream>
// using namespace std ;

// int main (){

//     int n1 = 9 ;
//     int n2 = 11 ;
//     int gcd = 1 ;    // both no. will atleast have common divisor as 1

//     for (int i = 1 ; i <= min (n1 , n2) ; i++){
//         if (n1 % i == 0 && n2 % i == 0){
//            gcd = i ;
//         }
//     }
//     cout << gcd ;
// }

// somewhat optimal -------------

// #include <iostream>
// using namespace std ;

// int main (){

//     int n1 = 20 ;
//     int n2 = 40 ;
//     int gcd = 1 ;    // both no. will atleast have common divisor as 1

//     for (int i = min(n1 , n2) ; i >= 1 ; i--){
//         if (n1 % i == 0 && n2 % i == 0){
//            gcd = i ;
//            break ;
//         }
//     }
//     cout << gcd ;
// }

// Euclidien Algorithm
// GCD(a,b) = GCD(a%b , b)  where a > b do this process until one of no. becomes 0
// then other no. will be GCD
#include <iostream>
using namespace std;

int main()
{

    int a = 52;
    int b = 10;
    int gcd = 1 ;
    while (a > 0 && b > 0){
        if (a > b){
            a = a % b ;
        }
        else {
            b = b % a ;
        }
    }
    if (a == 0) {
        gcd = b ;
    }
    else{
        gcd = a ;
    }
    cout << gcd ;
    
}
