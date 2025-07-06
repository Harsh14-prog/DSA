#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std ;

vector <int> prevSmaller (int arr[] , int n) {
   vector <int> pse(n);
   stack <int> st ;

   for (int i = 0 ; i < n ; i++){
     while (!st.empty() && arr[st.top()] >= arr[i]){
        st.pop() ;
     }

     if (st.empty()){
        pse[i] = -1 ;
     }
     else {
        pse[i] = st.top() ;
     }
     st.push(i);
   }
   return pse ;
}

vector <int> nextSmaller (int arr[] , int n) {
   vector <int> nse(n);
   stack <int> st ;

   for (int i = n-1 ; i >= 0 ; i--){
     while (!st.empty() && arr[st.top()] >= arr[i]){
        st.pop() ;
     }

     if (st.empty()){
        nse[i] = n ;
     }
     else {
        nse[i] = st.top() ;
     }
     st.push(i);
   }
   return nse ;
}

int minSum(int arr[] , int n){
   vector <int> pSmall = prevSmaller(arr , n);
   vector <int> nSmall = nextSmaller(arr , n);

   int mod = 1e9 + 7;
   long long sum = 0 ;

   for (int i = 0 ; i < n ; i++){
     long long product = ((nSmall[i] - i) % mod * (i - pSmall[i]) % mod)%mod;
     sum = (sum + (product * arr[i]) %mod) % mod ;
   }
   return sum ;
}


int main () {
    int arr[] = {0,2,3,4,1,4,3,2,0};
    int n = 9 ;

    int sum = minSum(arr , n);
    cout << sum ;
}