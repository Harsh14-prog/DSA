#include <iostream>
using namespace std;

int main () {
    int arr[] = {9,6,4,2,3,5,7,0,1};
    int n = 9;

    int hash[n + 1] = {0};  

    // Count each number's appearance
    for (int i = 0 ; i < n ; i++){
        hash[arr[i]]++;
    }

    // Find the number with 0 count
    for (int i = 0 ; i <= n ; i++){
        if (hash[i] == 0){
            cout << "Missing number: " << i << endl;
        }
    }
}

// m-2 ---->>>> using xor
