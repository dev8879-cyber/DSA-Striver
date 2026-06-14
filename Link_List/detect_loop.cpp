#include <iostream>
#include <map>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        map<ListNode*, int> mpp;

        ListNode* temp = head;

        while(temp != NULL) {

            // already visited
            if(mpp.find(temp) != mpp.end()) {
                return true;
            }

            mpp[temp] = 1;

            temp = temp->next;
        }

        return false;
    }
};

int main() {

    // Creating linked list
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating cycle
    fourth->next = second;

    Solution obj;

    if(obj.hasCycle(head)) {
        cout << "Cycle Present";
    }
    else {
        cout << "No Cycle";
    }

    return 0;
}