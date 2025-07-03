#include <iostream>
#include <stack>
using namespace std;

void printMiddle(stack<int> &s, int mid, int count = 0) {
    // Base case: If count reaches middle index, print the element
    if (count == mid) {
        cout << "Middle element: " << s.top() << endl;
        return;
    }

    int topElem = s.top();
    s.pop(); // Remove the top element

    printMiddle(s, mid, count + 1); // Recursive call

    s.push(topElem); // Restore the stack
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int mid = s.size() / 2; // Middle index

    printMiddle(s, mid); // Find and print middle element

    cout << "Initial stack (top to bottom): " << endl;
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
