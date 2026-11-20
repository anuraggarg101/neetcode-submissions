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
        ListNode* curr = head;

        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;
        tail->next = head;
        
        while(curr != nullptr) {
            int count = 0;
            ListNode* start = curr;
            ListNode* prev = tail;
            ListNode* end = curr;

            while(end and count < k) {
                prev = end;
                end = end->next;
                count++;
            }

            if(count < k) {
                tail->next = start;
                break;
            }

            prev->next = nullptr;
            tail->next = reverseList(start);
            tail = start;
            tail->next = end;
            curr = end;
        }
        return dummy.next;
    }
};
