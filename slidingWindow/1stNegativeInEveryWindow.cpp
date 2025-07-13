#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve(int arr[], int size, vector<int>& ans, int k) {
    
    queue<int> q;   // no need of dq like max and min que , as we are not doing any comparision between back of q and arr[i]

    for (int i = 0; i < size; i++) {
        // Remove out-of-window indices
        if (!q.empty() && q.front() < i - k+1) {
            q.pop();
        }

        // Store index if it's a negative number
        if (arr[i] < 0) {
            q.push(i);
        }

        // Start recording answers only after the first window is formed
        if (i >= k - 1) {
            if (!q.empty()) {
                ans.push_back(arr[q.front()]);  // front has first negative
            } else {
                ans.push_back(0);  // no negative in this window
            }
        }
    }
}

int main() {
    int arr[] = {10, -1, -2, 3, -4};
    int size = 5;
    int k = 2;

    vector<int> ans;
    solve(arr, size, ans, k);

    for (int x : ans) {
        cout << x << " ";
    }
}
