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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;

        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;

        int carry = 0;
        while(a or b) {
            int sum = (a ? a->val : 0) + (b ? b->val : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            tail->next = new ListNode(sum);
            tail = tail->next;
            if(a) a = a->next;
            if(b) b = b->next;
        }

        if(carry > 0) {
            tail->next = new ListNode(carry);
        }
        return dummy.next;
        
    }
};
