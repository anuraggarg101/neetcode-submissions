/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = head;
        while(n--) {
            fast = fast->next;
        }
        
        ListNode* prev = &dummy;
        ListNode* slow = head;
        while(fast != nullptr) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        // need to remove node "slow"
        if(prev) {
            prev->next = slow->next;
            delete slow;
        }
        return dummy.next;



    }
};
