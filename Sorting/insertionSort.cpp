#include <iostream>
#include <climits>
using namespace std ;

void sort(int arr[] , int n){
  
    for (int i = 1 ; i < n ; i++) {

        int j = i ;   
        // if we do operation with i , then we will continuosly swap same 
        // 2 numbers as we are not moving left after 1st swap

        while ( arr[j-1] > arr[j]){
            swap(arr[j-1] , arr[j]);
            j-- ;
        }
    }
}

int main () {

    int arr[] = {14,9,15,12,6,8,13};
    int n = 7 ;

    sort(arr , n);

    cout << "sorted array is : " << endl ;
    for (auto ele : arr){
        cout << ele << " " ;
    }
}