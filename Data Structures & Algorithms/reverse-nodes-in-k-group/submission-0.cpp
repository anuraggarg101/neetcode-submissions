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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

        ListNode* start = head;
        ListNode* end = head;

        for(int i=0;i<k-1;i++) {
            end = end->next;
            if(!end) {
                return head;
            }
        }

        ListNode* next_list = end->next;
        end->next = nullptr;
        reverseList(start);
        start->next = reverseKGroup(next_list, k);
        return end;
    }
};
