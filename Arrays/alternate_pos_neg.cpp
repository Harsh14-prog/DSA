#include <iostream>
#include <vector>
using namespace std ;


int main () {
    int arr[] = {3,1,-2,-5,2,-4};
    int n = 6 ;

    int pos = 0 ;
    int neg = 1 ;
    vector <int> ans(n , 0);

    for (int i = 0 ; i < n ; i++){
        if (arr[i] > 0){
           ans[pos] = arr[i];
           pos += 2 ;  
        }

        else {
            ans[neg] = arr[i];
            neg += 2 ;
        }
    }
    for (auto ele : ans){
        cout << ele << " " ;
    }
}

