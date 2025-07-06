#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std ;

vector <int> prevSmaller (int height[] , int n) {
   vector <int> pse(n);
   stack <int> st ;

   for (int i = 0 ; i < n ; i++){
     while (!st.empty() && height[st.top()] >= height[i]){
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

vector <int> nextSmaller (int height[] , int n) {
   vector <int> nse(n);
   stack <int> st ;

   for (int i = n-1 ; i >= 0 ; i--){
     while (!st.empty() && height[st.top()] >= height[i]){
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

int maxArea (int height[] , int n){

   vector <int> pSmaller = prevSmaller(height , n);
   vector <int> nSmaller = nextSmaller(height , n);

   int maxi = INT_MIN ;

   for (int i = 0 ; i < n ; i++){
     maxi = max(maxi , ((nSmaller[i] - pSmaller[i]-1)*height[i]));
   }

   return maxi ;
}

int main () {
    int height[] = {2,1,5,6,2,3} ;
    int n = 6 ;

    int ans = maxArea(height , n);
    cout << ans ;
}