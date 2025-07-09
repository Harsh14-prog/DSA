// #include <iostream>
// using namespace std ;

// int main () {
//     int arr[] = {1,1,1,0,0,0,1,1,1,1,0} ;
//     int n = 11 ;
//     int k = 2 ;
//     int maxLength = 0 ;

//     for (int i = 0 ; i < n ; i++){
//         int zero = 0 ;
//         for (int j = i ; j < n ; j++){
//            if (arr[j] == 0){
//             zero++ ;
//            }
//            if (zero > k){
//             break ;
//            }
//            int length = j-i + 1 ;
//            maxLength = max(maxLength , length);
//         }
//     }
//     cout << maxLength;

// }


// two pointer-sliding window approch
#include <iostream>
using namespace std ;

int main () {
    int arr[] = {1,1,1,0,0,0,1,1,1,1,0} ;
    int n = 11 ;
    int k = 2 ;
    int maxLength = 0 ;

    int l = 0 ;
    int h = 0 ;

    int zeroCount = 0 ;

    while (h < n){
       
        if (arr[h] == 0){
            zeroCount ++ ;
        }

        while(zeroCount > k){
            if (arr[l] == 0){
                zeroCount -- ;
            }
            l++ ;
        }
        
        int length = h-l+1 ;
        maxLength = max(maxLength , length);
        h++ ;
    }
    cout << maxLength ;   
}