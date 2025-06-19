#include <iostream>
using namespace std ;

int findFloor(int arr[] , int n , int target){
  
    // floor is largest no.which is <= target
    int s = 0 ;
    int e = n-1 ;
    int ans = -1 ;   // not taken n bez we have to return actual no. not index

       while (s <= e){

        int mid = (s+e)/2 ;
        if (arr[mid] <= target){    // eg: we are finding floor of target = 25 , and 25 is also present in array so floor is 25 itself as it is larget no
            ans = arr[mid];
            s = mid + 1 ;   // for largest smaller no. than stored no in ans
        }
        else {
            e = mid - 1 ;  // as we want no. smaller than target , so we moved to left
        }
       }
       return ans ;
}

int findCeil(int arr[] , int n , int target){

    // same as lower bound i.e 1st ele which is >= target ele
    int s = 0 ;
    int e = n-1 ;
    int ans = -1;

    while (s <= e){
       
        int mid = (s+e)/2 ;
        if (arr[mid] >= target){
            ans = arr[mid];
            e = mid-1 ;
        }
        else {
            s = mid + 1 ;
        }
    }
    return ans ;
}

// Floor: largest number ≤ target.
// Ceil: smallest number ≥ target.

int main () {

    int arr[] = {10 , 20 , 30 , 40 , 50};
    int n = 5 ;
    int target = 25 ;

    int ans1 =  findFloor(arr , n , target);
    int ans2 =  findCeil(arr , n , target);
    cout << "floor is : " << ans1 << endl;
    cout << "Ceil is : " << ans2 << endl;
}