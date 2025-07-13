#include <iostream>
#include <deque>
#include <vector>
using namespace std ;

vector <int> slidingWindowMax(int arr[] , int n , int k){
    deque <int> dq ;
    vector <int> ans ;

    for (int i = 0 ; i < n ; i++){
        
        // in dq index are stored in order to remove max of prev window , if we are in 2nd window
        if (!dq.empty() && dq.front() < i-k+1){
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();   // hence dq used
        }
        // any way we are pop_front if go to 2nd window , so automatically prev back will become front so we have to pop that back if it is smaller

        dq.push_back(i);

        if (i >= k-1){    // after 1st window complete i.e from i = 2 every time i.e on every i there will be new window so store result every time
            ans.push_back(arr[dq.front()]);
        }

    }
    return ans ;
}

int main() {

 int arr[] = {1,3,-1,-3,5,3,7,1,6};
 int n = 9 ;
 int k = 3;

 vector <int> ans = slidingWindowMax(arr , n , k);

 for(auto it : ans){
    cout << it << " " ;
 }

}