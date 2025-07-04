#include <iostream>
#include <stack>
#include <vector>
using namespace std ;

int main(){
  
    int arr[] = {1,2,3,4,3};
    int n = 5 ;
    
    vector <int> NGE(n);
    stack <int> st ;

    for (int i = 2*n-1 ; i >= 0 ; i--){

        while (!st.empty() && arr[i%n] >= st.top()){
            st.pop();
        }

        if (st.empty()){
            NGE[i%n] = -1 ;
        }
        else{
            NGE[i%n] = st.top();
        }
        st.push(arr[i%n]);
     }

    //     for (int i = n-1 ; i >= 0 ; i--){

    //     while (!st.empty() && arr[i] >= st.top()){
    //         st.pop();
    //     }

    //     if (st.empty()){
    //         NGE[i] = -1 ;
    //     }
    //     else{
    //         NGE[i] = st.top();
    //     }
    //     st.push(arr[i]);
    // }

    // instead of putting same 2 for loops we merged in single loop from 2*n -1 to >=0

    for (auto ele : NGE){
        cout << ele << " " ; 
    }

}