#include <iostream>
using namespace std ;

int main (){
    int n = 13 ;
    int count = 0 ;

    // while (n > 0){   // T.C --->> O(logn) base 2

    //     // decimal to binary conversion like code

    //     // for "%" use &1 and for "/" use >>
    //     // eg : l + h / 2 -->> (l+h) >> 2

    //     if (n % 2 == 1){  // if (n & 1) n jr odd then it have result 1
    //       count++ ;
    //     }
    //     n = n/2 ;   // n >> 2
    // }
    // cout << count ;

    while (n != 0){   // t.c --->>> O(no.of set bits)
        n = n & n-1 ;
        count++ ;
    }
}