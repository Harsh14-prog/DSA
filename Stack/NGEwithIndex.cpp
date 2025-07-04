#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ngeIndex(n, -1);
    stack<int> st; // store indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ngeIndex[i] = st.top(); // store index of next greater
        }

        st.push(i);
    }

    cout << "Next Greater Indexes: ";
    for (int i = 0; i < n; i++) {
        cout << ngeIndex[i] << " ";
    }
    cout << endl;

    return 0;
}
