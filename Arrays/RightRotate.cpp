#include <iostream>
#include <algorithm>
using namespace std;

void rightRotate(int arr[], int n, int k) {

    k = k % n;  // Normalize if k > n
    
    reverse(arr + (n - k), arr + n); // Step 1: Reverse last k elements
    reverse(arr, arr + (n - k));     // Step 2: Reverse first n-k elements
    reverse(arr, arr + n);          // Step 3: Reverse whole array
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rightRotate(arr, n, k);

    cout << "Right Rotated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
