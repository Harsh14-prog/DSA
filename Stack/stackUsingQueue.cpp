#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;

public:
    // Push element x onto stack
    void push(int x) {
        q.push(x);
        int size = q.size();

        // Rotate the queue to bring x to the front
        for (int i = 0; i < size - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the top element
    void pop() {
        if (!q.empty()) {
            q.pop();
        } else {
            cout << "Stack is empty\n";
        }
    }

    // Get the top element
    int top() {
        if (!q.empty()) {
            return q.front();
        }
        cout << "Stack is empty\n";
        return -1;
    }

    // Return whether the stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;  // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20

    st.pop();
    st.pop();
    st.pop(); // Should print "Stack is empty"

    return 0;
}
