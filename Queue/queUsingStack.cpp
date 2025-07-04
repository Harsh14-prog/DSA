#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
    
//Amortized
public:
    // Enqueue (push element at end)
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue (remove element from front)
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            // Move all elements from s1 to s2 (reverses order)
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int front = s2.top();
        s2.pop();
        return front;
    }

    // Peek (return front element)
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check if queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Front after dequeue: " << q.front() << endl; // 20

    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl; // 20
    cout << "Dequeued: " << q.dequeue() << endl; // 30
    cout << "Dequeued: " << q.dequeue() << endl; // 40
    cout << "Dequeued: " << q.dequeue() << endl; // Queue is empty

    return 0;
}
