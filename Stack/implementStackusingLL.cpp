#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;
    int size;  // to keep track of number of elements

public:
    Stack() {
        topNode = nullptr;
        size = 0;     // LL is dynamic so no need to give size
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    void pop() {
        if (topNode == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }

    int top() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();  // Output: Stack (top to bottom): 30 20 10

    cout << "Top element: " << s.top() << endl;      // 30
    cout << "Stack size: " << s.getSize() << endl;   // 3

    s.pop();
    s.display();  // Output: 20 10
    cout << "Stack size after pop: " << s.getSize() << endl;  // 2
}
