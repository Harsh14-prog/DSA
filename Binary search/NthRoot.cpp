#include <iostream>
using namespace std ;

int root (int m , int n){

    if (n <= 0) return -1 ;
    if (m < 0 && n % 2 == 0) return -1 ;   // even root of -ve no. imaginary no , odd root exists but

    int s = 1 ;
    int e = abs(m) ;
    int ans = -1 ;

    while (s <= e) {
        long long mid = (s + e)/2 ;
        long long multi = 1 ;
        for (int i = 0 ; i < n ; i++){
           multi = multi * mid ;
           if (multi > abs(m)) break ;
        }
        
        if (multi <= abs(m)){
          ans = mid ;
          s = mid + 1 ;
        }
        else {
            e = mid - 1 ;
        }
    }
    return ans ;
}

int main () {

    int m = -1000 ;
    int n = 3 ;

    int nthRoot = root(m , n);

    cout << nthRoot ;

}