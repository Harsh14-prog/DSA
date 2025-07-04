#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

int main () {
    int arr[] = {4,8,5,2,25};
    int n = 5 ;

    stack <int> st ;
    vector <int> NSE(n);

    for (int i = n-1 ; i >= 0 ; i--){
        while (!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if (st.empty()){
            NSE[i] = -1 ;
        }
        else{
            NSE[i] = st.top();
        }
        st.push(arr[i]);
    }

    for (auto ele : NSE){
        cout << ele << " " ; 
    }
}