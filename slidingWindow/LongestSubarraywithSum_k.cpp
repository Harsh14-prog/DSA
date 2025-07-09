#include <iostream>
#include <unordered_map>
using namespace std;

// Brute-force approach
int longestLength(int arr[], int n, int k) {
    int length = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

// Sliding window approach (only for +ve integers)
int optimalLongestLength(int arr[], int n, int k) {
    int i = 0, j = 0;
    int sum = 0, length = 0;

    while (j < n) {
        sum += arr[j];

        while (sum > k && i <= j) {
            sum -= arr[i];
            i++;
        }

        if (sum == k) {
            length = max(length, j - i + 1);
        }

        j++;
    }

    return length;
}

// Most optimal approach using prefix sum + hashmap
int mostOptimalSolution(int arr[], int n, int k) {
    unordered_map<int, int> map;
    int maxLength = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k) {
            maxLength = i + 1;
        }

        if (map.find(sum - k) != map.end()) {
            maxLength = max(maxLength, i - map[sum - k]);
        }

        // stores 1st occurance of sum
        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int n = 10;
    int k = 10;

    int ans1 = longestLength(arr, n, k);
    cout << "Brute Force: " << ans1 << endl;

    int ans2 = optimalLongestLength(arr, n, k);
    cout << "Sliding Window: " << ans2 << endl;

    int ans3 = mostOptimalSolution(arr, n, k);
    cout << "Prefix Sum: " << ans3 << endl;

    return 0;
}
