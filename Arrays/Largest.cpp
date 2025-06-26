#include <iostream>
#include <climits>
using namespace std ;

int findLargest(int arr[] , int n){
    int maxi = INT_MIN ;
    for (int i = 0 ; i < n ; i++){
        maxi = max (arr[i] , maxi) ;
    }
    return maxi ;
}

int main(){

    int arr[] = {2,5,1,3,10};
    int n = 5 ;

    int ans = findLargest(arr , n);
    cout << ans ;
}
