#include <iostream>
#include <climits>
using namespace std ;

void sort(int arr[] , int n){
    // in 1st pass last ele (n-1)th get sorted or max no goes to last index n-1
    // to it's place so in 2nd pass we will do swapping only till n-2
  for (int i = n-1 ; i >= 0 ; i--){
    int didswap = 0 ;  
    for (int j = 0 ; j <= i-1 ; j++){
        if (arr[j] > arr[j+1]){
            swap(arr[j] , arr[j+1]);
            didswap = 1 ;
        }
    }
    if (didswap == 0){
        break ;
    }
  }
}

int main () {

    int arr[] = {13 , 46 , 24 , 52 , 20 , 9};
    int n = 6 ;

    sort(arr , n);

    cout << "sorted array is : " << endl ;
    for (auto ele : arr){
        cout << ele << " " ;
    }
}