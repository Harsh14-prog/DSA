#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void insertSorted(stack<int> &s, int val) {
    // base case: stack is empty or val >= top (for descending order)
    if (s.empty() || s.top() <= val) {
        s.push(val);
        return;
    }

    // hold top
    int topE = s.top();
    s.pop();

    // insert in remaining stack
    insertSorted(s, val);

    // push back top
    s.push(topE);
}

int main() {
    stack<int> s;
    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    cout << "Initial stack is:\n";
    printStack(s);

    int val = 25;
    insertSorted(s, val);

    cout << "Stack after inserting " << val << " is:\n";
    printStack(s);

    return 0;
}
