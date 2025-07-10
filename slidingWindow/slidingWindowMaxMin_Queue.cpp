#include <iostream>
#include <vector>
#include <deque>
using namespace std ;

int sumOfMaxAndMin (int arr[] , int n , int k){

    deque <int> dq1 ;
    deque <int> dq2 ;
    int sum = 0 ;

    for (int i = 0 ; i < n ; i++){
        if (!dq1.empty() && dq1.front() < i-k+1){
           dq1.pop_front();
        }
        if (!dq2.empty() && dq2.front() < i-k+1){
           dq2.pop_front();
        }

        while (!dq1.empty() && arr[dq1.back()] <= arr[i]){
            dq1.pop_back();
        }
        dq1.push_back(i);

        while (!dq2.empty() && arr[dq2.back()] >= arr[i]){
            dq2.pop_back();
        }
        dq2.push_back(i);

        if (i >= k-1){
            sum = sum + arr[dq1.front()] + arr[dq2.front()];
        }
    }
    return sum ;
}

int main() {
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = 7, k = 4;

    cout << "Sum of max and min in each window: " << sumOfMaxAndMin(arr, n, k) << endl;
    return 0;
}