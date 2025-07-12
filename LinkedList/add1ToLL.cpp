#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    return prev;
}


Node* addOne(Node* head) {
    
    Node* reversedHead = reverseLL(head);
    int carry = 1;

    Node* temp = reversedHead;

    while (temp != NULL) {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if (carry == 0)
            break;

        if (temp->next == NULL && carry > 0) {
            temp->next = new Node(carry);
            break;
        }

        temp = temp->next;
    }

    return reverseLL(reversedHead);
}


Node* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return NULL;

    Node* head = new Node(nums[0]);
    Node* current = head;

    for (int i = 1; i < nums.size(); i++) {
        current->next = new Node(nums[i]);
        current = current->next;
    }

    return head;
}


void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> number = {1, 9, 9}; 
    Node* head = createLinkedList(number);

    cout << "Original Linked List: ";
    printLinkedList(head);

    Node* newHead = addOne(head);

    cout << "After Adding One: ";
    printLinkedList(newHead);

}
