#include <iostream>
using namespace std;

void MoveZeros(int arr[], int n) {
    int l = -1;

    // Step 1: Find first zero
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            l = i;
            break;
        }
    }

    // If no zero found, array is already correct
    if (l == -1) return;

    // Step 2: Use h to find non-zeros and swap with l
    int h = l + 1;

    while (h < n) {
        if (arr[h] != 0) {
            swap(arr[l], arr[h]);
            l++;
        }
        h++;
    }
}

int main() {
    int arr[] = {1, 0, 0, 3, 0, 4, 0, 1};
    int n = 8;

    MoveZeros(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
