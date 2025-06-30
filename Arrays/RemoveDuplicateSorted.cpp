
// brute force ----------------->>>>>>>>>>>

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// using namespace std ;

// vector <int> uniqueArray( vector <int> &arr){
//     int n = arr.size();

//     stack <int> st ;
//     st.push(arr[0]);
    
//     for (int i = 1 ; i < n ; i++){
//         if (st.top() != arr[i]){
//             st.push(arr[i]);
//         }
//     }
    
//     vector <int> ans ;
//     while (!st.empty()){
//         int top = st.top();
//         ans.push_back(top);
//         st.pop();
//     }

//     reverse(ans.begin(), ans.end());
//     return ans;
// }

// int main(){
//    vector <int> arr = {1,1,2,2,2,3,3};
//     vector <int> ans = uniqueArray(arr);

//     for(auto ele : ans){
//         cout << ele << " " ;
//     }
// }



// optimal --------------------------------->>>>>>>>>

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std ;

void uniqueArray( vector <int> &arr){
    int n = arr.size();
    
    int i = 0;  // 1st ele is always sorted
    int j = 1;
    while (j < n){
      if (arr[i] == arr[j]){
        j++ ;
      }
      else{
        i++ ;
        swap(arr[i] , arr[j]);
        j++ ;
      }
    }
 
}

int main(){
   vector <int> arr = {1,1,2,2,2,3,3};
    uniqueArray(arr);

    for(auto ele : arr){
        cout << ele << " " ;
    }
}
