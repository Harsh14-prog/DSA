// #include <iostream>
// #include <vector>
// using namespace std ;

// int celebrity(vector <vector <int>> &arr , int n){

//     // possible candidtaes are from 0 to n-1
//     // we will check who can't be celebrity , and eliminate them to get 
//     // actual celebrity

//     int top = 0 ;
//     int bottom = n-1 ;

//  while (top < bottom){
//     if (arr[top][bottom] == 1){
//         top ++ ;
//     }
//     else if (arr[bottom][top] == 1){
//         bottom -- ;
//     }
//     else{
//         // both did not know each other so any one of them can't be celebrity
//         top++ ;
//         bottom-- ;
//     }
//  }

//   if (top > bottom){
//     return -1 ;
//   }    // this will happen deu to 3rd else case
  
//   // top == bottom  , checking row of top is 0 nd col is 1 to confirm
//   // confirming is considered top is celebrity
//   for (int i = 0 ; i < n ; i++){
        
//        if (i == top) {
//           continue ;     // diagonal skipped
//        }
//         if (arr[top][i] != 0 || arr[i][top] != 1){
//             return -1 ;
//         }
//     }
//     return top ;
//   }


// int main() {
//     vector<vector<int>> arr = {
//         {0, 1, 1, 1},
//         {0, 0, 1, 1},
//         {0, 0, 0, 1},
//         {0, 0, 0, 0}
//     };

//     int n = arr.size();

//     int ans = celebrity(arr, n);
//     cout << ans << endl;

// }

// stack based approch ---------------------------------->>>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>>& arr, int n) {

    //  Push all candidates (0 to n-1) onto the stack
    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    //  Eliminate non-celebrities using pairwise comparison
    while (st.size() > 1) {
        int top1 = st.top(); st.pop();
        int top2 = st.top(); st.pop();

        if (arr[top1][top2] == 1) {
            // top1 knows top2 → top1 can't be celebrity
            st.push(top2);
        } else {
            // top1 does NOT know top2 → top2 can't be celebrity
            st.push(top1);
        }
    }

    // Step 3: One candidate left, might be the celebrity
    int candidate = st.top();

    // Validate candidate by checking:
    //  Candidate knows no one → row should be all 0
    //  Everyone knows candidate → column should be all 1 (except diagonal)
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue; // skip diagonal

        if (arr[candidate][i] != 0 || arr[i][candidate] != 1) {
            return -1;  // Not a celebrity
        }
    }
    return candidate;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    int n = arr.size();

    int ans = celebrity(arr, n);
    cout << ans << endl;
}
