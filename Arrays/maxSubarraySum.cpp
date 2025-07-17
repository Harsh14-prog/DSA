#include <iostream>
#include <climits>
using namespace std ;

int main () {
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = 8;
    int maxi = INT_MIN ;

    // brute-force --- all possible subarray
    // for (int i = 0 ; i < n ; i++){
    //     int sum = 0 ;
    //     for (int j = i ; j < n ; j++){
    //       sum = sum + arr[j];
    //       maxi = max(maxi , sum);
    //     }
    // }
    // cout << maxi ;


    // kadane's algorithm --- if (arr[i] < 0) sum = 0
    int sum = 0 ;
    int start = 0 ;
    int end = 0 ;
    int tempstart = 0 ;
    for (int i = 0 ; i < n ; i++){
       sum = sum + arr[i] ;

       if (sum > maxi){
         maxi = sum ;
         start = tempstart ;
         end = i ;
       }

        if (sum < 0) {
         sum = 0 ;
         tempstart = i+1 ;
       } 
    } 
    for (int i = start ; i <= end ; i++){
        cout << arr[i] << " "  ;
    }
    // cout << maxi;

}