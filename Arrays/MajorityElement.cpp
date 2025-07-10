#include <iostream>
using namespace std ;

int element(int arr[] , int n){
    int count = 0 ;
    int ele ;
    for (int i = 0 ; i < n ; i++){
        if (count == 0){
          ele = arr[i];
        }

        if (arr[i] == ele){
            count++ ;
        }
        else{
            count-- ;
        }
    }
    return ele ;
}

int main () {
    int arr[] = {2,1,1,1,1,2,2} ;
    int n = 7 ;

    int ans = element(arr , n);
    cout << ans; 

}
