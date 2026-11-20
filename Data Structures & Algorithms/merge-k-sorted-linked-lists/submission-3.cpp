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
struct myComp {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
private:

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, myComp> pq;
        for(auto &node:lists) {
            if(node != nullptr)
                pq.push(node);
        }

        while(!pq.empty()) {
            ListNode* min_node = pq.top();
            pq.pop();

            tail->next = min_node;
            if(min_node->next) {
                min_node = min_node->next;
                pq.push(min_node);
            }
            tail = tail->next;
        }
        return dummy.next;
    }
};
