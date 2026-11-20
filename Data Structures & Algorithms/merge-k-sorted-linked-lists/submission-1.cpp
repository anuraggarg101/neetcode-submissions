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
    int findMin(vector<ListNode*>& lists) {
        // O(k)
        int min_val = INT_MAX;
        int min_idx = 0;
        int k = lists.size();
        for(int i=0;i<k;i++) {
            int curr_val = lists[i] ? lists[i]->val : INT_MAX;
            if(curr_val < min_val) {
                min_val = curr_val;
                min_idx = i;
            }
        }

        return min_val == INT_MAX ? -1 : min_idx;
    }
    
    ListNode* merge(ListNode* a, ListNode *b) {
        if(!a) return b;
        if(!b) return a;

        ListNode* res = new ListNode();
        ListNode* dummy = res;

        while(a and b) {
            if(a->val <= b->val) {
                res->next = a;
                a = a->next;
            } else {
                res->next = b;
                b = b->next;
            }
            res = res->next;
        }
        if(a) res->next = a;
        if(b) res->next = b;
        
        return dummy->next;
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {
        if(start >= end) return lists[start];
        int mid = (start + end)/2;
        return merge(mergeLists(lists, start, mid), mergeLists(lists, mid+1, end));
    }
public:
    /*
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        
        while(true) {
            // runs n times
            int min_val_idx = findMin(lists);
            if(min_val_idx == -1) break;
            head->next = lists[min_val_idx];
            head = head->next;
            lists[min_val_idx] = lists[min_val_idx]->next;
        }
        return dummy->next;
    }
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return mergeLists(lists, 0, lists.size() - 1);
    }
};
