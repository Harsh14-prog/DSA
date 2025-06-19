#include <iostream>
using namespace std ;

int Find1stIndex(int arr[] , int n , int target){
   
    int s = 0;
    int e = n-1;
    int ans = -1 ;

    while (s <=e){
        
        int mid = (s + e)/2 ;

        if (arr[mid] == target){
              ans = mid ;
              e = mid - 1 ;
        }

        else if (arr[mid] < target){
            s = mid + 1 ;
        }

        else if (arr[mid] > target){
            e = mid - 1 ;
        }
    }
    return ans ;
}

int FindlastIndex(int arr[] , int n , int target){
   
    int s = 0;
    int e = n-1;
    int ans = -1 ;

    while (s <=e){
        
        int mid = (s + e)/2 ;

        if (arr[mid] == target){
              ans = mid ;
              s = mid + 1 ;
        }

        else if (arr[mid] < target){
            s = mid + 1 ;
        }

        else if (arr[mid] > target){
            e = mid - 1 ;
        }
    }
    return ans ;
}

int main(){
   
    int nums[] = {3,7,7,8,8,8,10};
    int n = 7 ;
    int target = 10 ;

    int ans1 = Find1stIndex(nums , n,  target);
    int ans2 = FindlastIndex(nums , n,  target);
    
    int totalOccurance = (ans1 == -1 && ans2 == 0) ? 0 :  (ans2 - ans1 + 1) ;
    cout << totalOccurance ;

}