#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std ;

int main () {

    int arr[] = {2,6,5,8,11};
    int n = 5 ;
    int targetSum = 14 ;
    vector <int> ans;

    unordered_map <int , int> map ;

    for (int i = 0 ; i < n ; i++){
       if (map.find(targetSum - arr[i]) != map.end()){
         ans.push_back(i);
         ans.push_back(map[targetSum - arr[i]]);
       }
       else{
        map[arr[i]] = i ;
       }
    }

    if (ans.empty()){
        cout << -1 ;
    }

    for (auto ele : ans){
        cout << ele << " " ;
    }
}