// brute force ----------------------------
// #include <iostream>
// #include <vector>
// using namespace std; 

// void Rotate(int arr[] , int n , int k){
//     vector <int> ans(k , 0);
   
//     for (int i = 0 ; i < k ; i++){    // o(k)
//       ans[i] = arr[i];
//     }

//     for (int i = k ; i < n ; i++){   // o(n-k)
//         arr[i-k] = arr[i];
//     }

//     for (int i = n-k ; i < n ; i++){  // o(k)
//         arr[i] = ans[i-(n-k)];
//     }
    
// }    // overall time complexity -->> o(n) , space complexity --->> o(k)

// int main (){
//     int arr[] = {1,2,3,4,5};
//     int n = 5 ;
//     int k = 2 ;

//     Rotate(arr , n , k);
//     for(auto ele : arr){
//         cout << ele << " " ;
//     }
// }

// optimal ----------------------------
#include <iostream>
#include <algorithm>
using namespace std;

void leftRotate(int arr[], int n, int k) {

    k = k % n;  // Normalize if k > n
    
    reverse(arr, arr + k);         // Step 1: Reverse first k elements
    reverse(arr + k, arr + n);     // Step 2: Reverse rest of array
    reverse(arr, arr + n);         // Step 3: Reverse whole array
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    leftRotate(arr, n, k);

    cout << "Left Rotated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
