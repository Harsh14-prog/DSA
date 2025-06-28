// #include <iostream>
// using namespace std ;

// int main () {

//     int n = 36 ;

//     for (int i = 1 ; i <= n ; i++){
//         if (n % i == 0){
//             cout << i << endl; 
//         }
//     }
// }

//   optimal --------------

// #include <iostream>
// #include <cmath>
// using namespace std;

// int main() {
//     int n = 36;

//     for (int i = 1; i  <= sqrt(n); i++) {
//         if (n % i == 0) {
//             cout << i << endl ;
//             // as we know this i is divisible , then it's multiple is also divisible to n
//             // n have 2 factors i and n/i
//            if (i != n/i){
//             cout << n/i << endl ;
//            } 
//         }
//     }

//     return 0;
// }

// more otimal --------------------------------
#include <iostream>
using namespace std;

int main() {
    int n = 36;

    for (int i = 1; i*i <= n ; i++) {
        if (n % i == 0) {
            cout << i << endl ;
           if (i != n/i){
            cout << n/i << endl ;
           } 
        }
    }

    return 0;
}
