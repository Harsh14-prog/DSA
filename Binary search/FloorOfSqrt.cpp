#include <iostream>
using namespace std;

int mySqrt(int n) {

    // as we know search-space , sqrt will lie betwn 1 to n here 28 so used B.S on them
    int s = 1;
    int e = n;
    int ans = 0;

    while (s <= e) {

        // int mid = s + (e - s) / 2;
        // long long sq = 1LL * mid * mid;  // prevent overflow

        // in upper we can't store result of multi directly in long long rather than 
        // multiplying with 1LL bez multiplication happens 1st and mid is still int
        // so overflow will happen 
        // so if we have to skip 1LL* make mid long long
        // upper method is correct also as we are using 1LL*

        long long mid = s + (e - s) / 2 ;
        long long sq = mid * mid ;

        if (sq == n) {
            return mid;
        }
        else if (sq < n) {
            ans = mid;      
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n = 28;
    int ans = mySqrt(n);
    cout << ans << endl;  
    return 0;
}
