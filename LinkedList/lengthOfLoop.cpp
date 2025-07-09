#include <iostream>
using namespace std;


class ListNode {
public :    
    int val;
    ListNode *next;

    ListNode(int value){
        val = value ;
        next = NULL ;
    }  
};

class Solution {
public:
    ListNode* hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return fast; // cycle detected
            }
        }
        return NULL; // no cycle
    }

    int findLengthOfLoop(ListNode *head) {
        ListNode* fast = hasCycle(head);
        if (fast == NULL) {
            return 0;
        }

        ListNode* slow = fast;
        int count = 1;

        fast = fast->next;
        while (fast != slow) {
            count++;
            fast = fast->next;
        }

        return count;
    }
};

int main() {
    // Creating nodes
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    // Connecting nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3; 

    Solution sol;
    int length = sol.findLengthOfLoop(node1);
    if (length > 0) {
        cout << "Cycle detected! Length of the loop is: " << length << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
