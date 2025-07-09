#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> interleave(queue<int>& q1) {
    vector<int> ans;
    int n = q1.size();
    int half = n / 2;

    queue<int> q2;

    // Push the first half elements into q2
    for (int i = 0; i < half; ++i) {
        q2.push(q1.front());
        q1.pop();
    }

    // Interleave the elements of q2 and q1
    while (!q2.empty() && !q1.empty()) {
        ans.push_back(q2.front()); 
        q2.pop();
        ans.push_back(q1.front());  
        q1.pop();
    } 

    if (!q1.empty()) {
        ans.push_back(q1.front());
        q1.pop();
    }

    return ans;
}

int main() {
    queue<int> q1;
    q1.push(9);
    q1.push(2);
    q1.push(1);
    q1.push(9);
    q1.push(7);
    q1.push(5);
    q1.push(10);
    q1.push(11);
    q1.push(12);
    q1.push(13);
    q1.push(6);
    q1.push(1);
    q1.push(3);

    vector<int> result = interleave(q1);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
