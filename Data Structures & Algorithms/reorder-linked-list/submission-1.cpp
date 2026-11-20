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

    ListNode* mergeLists(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        bool is_a_turn = true;
        while(a and b) {
            if(is_a_turn) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
            is_a_turn = !is_a_turn;
        }

        tail->next = !a ? b : a;
        return dummy.next;
    }

public:
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = head;
        ListNode* second = prev->next;
        prev->next = nullptr;
        second = reverseList(second);
        // merge two lists first and second
        head = mergeLists(first, second);
        return;
    }
};
