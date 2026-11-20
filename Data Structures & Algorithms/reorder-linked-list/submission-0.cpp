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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head2 = reverseList(head2);
        ListNode *head1 = head;
        
        // merge head1 and head2 one by one
        while(head2) {
            ListNode* next = head1->next;
            head1->next = head2;
            head2 = head2->next;
            head1->next->next = next;
            head1 = next;
        }
        
        // return head;
    }
};
