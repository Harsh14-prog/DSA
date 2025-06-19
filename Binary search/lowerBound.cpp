#include <iostream>
using namespace std ;

int lowerBound (int arr[] , int n , int target){

    // some what similar like 1st and last occurance
    // eg: lower bound of 8 means "1st ele" which is "greater than equal to" 8
    // upper bound of 8 is  "1st ele" which is "strictly greater than" 8

    int s = 0 ;
    int e = n-1;
    int ans = n ;   // if target is not present in arr , give position where we can insert it

    while (s <= e){
        int mid = (s + e)/2 ;

        if (arr[mid] >= target){   // lower bound greater than equal to
           ans = mid ;
           e = mid - 1 ;   // we want more nearest greater ele , than we get in ans
        }

        else if (arr[mid] < target){
            s = mid + 1 ;
        }
    }
    return ans ;
}

int upperBound (int arr[] , int n , int target){

    int s = 0 ;
    int e = n-1;
    int ans = n ;

    while (s <= e){
        int mid = (s + e)/2 ;

        if (arr[mid] > target){   // in upper bound strictly greater
           ans = mid ;
           e = mid -1 ;  // in both cases lower nd upper condn is same
        }

        else if (arr[mid] < target){
            s = mid + 1 ;
        }
    }
    return ans ;
}

int main () {
    int arr[] = {3,5,8,15,19};
    int n = 5 ;
    int target = 8 ;

    int ans1 =  lowerBound(arr , n , target);
    int ans2 = upperBound(arr , n , target);
    cout << "lower bound is : " << ans1 << endl ;
    cout << "upper bound is : " << ans2 << endl ;
}