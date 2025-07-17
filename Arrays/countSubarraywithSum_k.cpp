#include <iostream>
#include <unordered_map>
using namespace std ;

int main () {
    int arr[] = {1,2,3,-3,1,1,1,4,2,-3};
    int n = 10 ;
    int k = 3 ;
    int sum = 0 ;
    int count = 0 ;

    unordered_map <int , int> map ;

    for (int i = 0 ; i < n ; i++){

        sum = sum + arr[i];

        if (sum == k){
            count++ ;
        }

        if (map.find(sum - k) != map.end()){
            count = count + map[sum-k] ;
            // if we only do count++ , then we always increment count by 1
            // even if we have more than more subarr of sum = k
            // so store count of sum 
        }
        
        // not put in condn bez we always storing count of each sum , not watching 
        // if that sum exists in map or not like max length
        // here no need of this
        map[sum]++ ;    // store count in map
      
    }
    cout << count ;
}