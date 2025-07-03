#include <iostream>
using namespace std;

class stack {
public:
    int* arr;
    int size;
    int top;

    stack(int capacity) {
        arr = new int[capacity];
        size = capacity;
        top = -1;
    }

    void push(int val) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int getsize() {
        return top + 1;
    }

    int getTop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    stack st(6);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.print();

    return 0;
}
