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
    if (head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* oddEvenList(Node* head) {
    if (!head || !head->next) return head;

    Node* dummyOdd = new Node(-1);
    Node* dummyEven = new Node(-1);
    Node* odd = dummyOdd;
    Node* even = dummyEven;
    Node* temp = head;
    int index = 1;

    while (temp) {
        if (index % 2 != 0) {
            odd->next = temp;
            odd = odd->next;
        } else {
            even->next = temp;
            even = even->next;
        }
        temp = temp->next;
        index++;
    }

    even->next = NULL;
    odd->next = dummyEven->next;

    Node* newHead = dummyOdd->next;
    delete dummyOdd;
    delete dummyEven;
    return newHead;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    
    insertAtHead(7, head, tail);
    insertAtHead(4, head, tail);
    insertAtHead(6, head, tail);
    insertAtHead(5, head, tail);
    insertAtHead(3, head, tail);
    insertAtHead(1, head, tail);
    insertAtHead(2, head, tail);  

    cout << "Original List: ";
    print(head);

    Node* newHead = oddEvenList(head);

    cout << "Reordered List : ";
    print(newHead);

}
