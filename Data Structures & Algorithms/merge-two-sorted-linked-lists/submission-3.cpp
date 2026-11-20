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
/*
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* a = list1;
        ListNode* b = list2;

        if(a->val > b->val) return mergeTwoLists(list2, list1);

        while(a!=nullptr and a->next != nullptr and b!=nullptr) {
            if(a->next->val > b->val) {
                ListNode* next = a->next;
                a->next = b;
                b = b->next;
                a = a->next;
                a->next = next;
            } else {
                a = a->next;
            }
        }

        if(b != nullptr) {
            a->next = b;
        }

        return list1;
    }
*/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 and list2) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = (list1 == nullptr) ? list2 : list1;
        return dummy.next;
    }
};
