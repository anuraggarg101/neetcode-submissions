/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* curr = head;

        while(curr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }


        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next;
            if(curr) {
                curr = curr->next;
            } else {
                break;
            }
        }

        curr = head;
        Node* dummy_head = curr->next;
        Node* head2 = dummy_head;
        
        while(curr and curr->next) {
            Node* curr_next = head2->next;
            head2->next = curr_next ? curr_next->next : nullptr;
            curr->next = curr_next;
            head2 = head2->next;
            curr = curr_next;
        }
        
        return dummy_head;
        
    }
};
