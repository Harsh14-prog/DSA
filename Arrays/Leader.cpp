#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int arr[] = {10 , 22 , 12 , 3 , 0 , 6};
    int n = 6 ;
    int maxi = INT_MIN ;
    vector <int> leader ;

    for (int i = n-1 ; i >= 0 ; i--){
        if(arr[i] > maxi){
            maxi = arr[i];
            leader.push_back(maxi);
        }
    }
    reverse(leader.begin(), leader.end());

    for (auto ele : leader){
        cout << ele << " " ;
    }
}
