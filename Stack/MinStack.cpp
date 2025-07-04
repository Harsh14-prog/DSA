#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;

    // MinStack() {}    does not need to make constructor

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.empty() ? -1 : st.top().first;
    }

    int getMin() {
        return st.empty() ? -1 : st.top().second;
    }
};

int main() {

    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    cout << "Min: " << ms.getMin() << endl;  

    ms.pop();
    cout << "Top: " << ms.top() << endl;     
    cout << "Min: " << ms.getMin() << endl;  

    ms.pop();
    cout << "Top: " << ms.top() << endl;     
    cout << "Min: " << ms.getMin() << endl;  
}
