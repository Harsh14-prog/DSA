#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void solve(int arr[], int size, vector<int>& ans, int k) {
    
    deque<int> dq;

    for (int i = 0; i < size; i++) {
        // Remove out-of-window indices
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Store index if it's a negative number
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        // Start recording answers only after the first window is formed
        if (i >= k - 1) {
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]);  // front has first negative
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
    return 0;
}
