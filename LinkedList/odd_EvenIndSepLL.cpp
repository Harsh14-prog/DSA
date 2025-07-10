#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummyOdd = new ListNode(-1);
        ListNode* dummyEven = new ListNode(-1);
        ListNode* odd = dummyOdd;
        ListNode* even = dummyEven;
        ListNode* temp = head;
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

        even->next = nullptr;
        odd->next = dummyEven->next;

        ListNode* newHead = dummyOdd->next;
        delete dummyOdd;
        delete dummyEven;

        return newHead;
    }
};

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> input = {2, 1, 3, 5, 6, 4, 7};
    ListNode* head = createList(input);

    Solution sol;
    ListNode* newHead = sol.oddEvenList(head);

    cout << "Reordered list (odd-indexed followed by even-indexed): ";
    printList(newHead);

    return 0;
}
