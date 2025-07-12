#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2) {
    Node* temp = head2;
    Node* temp1 = head1;

    unordered_map<int, int> map;
    Node* dummyNode = new Node(-1);
    Node* dummy = dummyNode;

    while (temp != NULL) {
        map[temp->data]++;
        temp = temp->next;
    }

    while (temp1 != NULL) {
        if (map[temp1->data] > 0) {
            dummy->next = new Node(temp1->data); 
            dummy = dummy->next;
            map[temp1->data]--;
        }
        temp1 = temp1->next;
    }

    dummy->next = NULL;
    return dummyNode->next;
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    // Creating first list: 9 -> 6 -> 4 -> 2 -> 3 -> 8
    Node* head1 = new Node(9);
    head1->next = new Node(6);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(3);
    head1->next->next->next->next->next = new Node(8);

    // Creating second list: 1 -> 2 -> 8 -> 6
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(6);

    Node* result = findIntersection(head1, head2);

    cout << "Intersection list: ";
    printList(result);

    return 0;
}
