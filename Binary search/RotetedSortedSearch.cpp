#include <iostream>
using namespace std ;

int search(int arr[] , int n , int k){

    int s = 0 ;
    int e = n-1 ;

    while(s <=e){

        int mid = (s + e)/2 ;

        if (arr[mid] == k){
            return mid ;
        }

        if (arr[mid] >= arr[s]){
           // left half is sorted , search k there if not eliminate it , if yss eliminate right pArt
           if (k >= arr[s] && k <= arr[mid]){
            e = mid - 1 ;  // right half eliminated , as k is there in lrft part
           }
           else{
            s = mid + 1;   // k is not there in left part so eliminated it
           }
        }

        else {
            // right half is sorted , search k there if yss then eliminate left part
            if (k >= arr[mid] && k <= arr[e]){
                s = mid + 1 ;  // left part eliminated
            }
            else{
                e = mid - 1 ;
            }
        }
    }
    return -1 ;
}

int main(){

    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9; 
    int k = 8;

    int index = search(arr , n , k);
    cout << index ;
}