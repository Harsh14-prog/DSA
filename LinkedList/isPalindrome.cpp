#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insertAtHead(int value, Node*& head, Node*& tail) {
    Node* newNode = new Node(value);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    
    if (!head || !head->next) return true;

    // Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //  Reverse second half
    Node* secondHalfStart = reverse(slow->next);

    //  Compare both halves
    Node* first = head;
    Node* second = secondHalfStart;
    bool isPalin = true;
    while (second != NULL) {
        if (first->data != second->data) {
            isPalin = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Restore the original list
    slow->next = reverse(secondHalfStart);

    return isPalin;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(10, head, tail);
    // insertAtHead(50, head, tail); 

    print(head);
    bool ans = isPalindrome(head);
    cout << (ans ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
