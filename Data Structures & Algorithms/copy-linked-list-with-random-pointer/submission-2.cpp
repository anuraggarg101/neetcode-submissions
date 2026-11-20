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
private:
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;
        Node* curr = head;
        while(curr) {
            Node* copy = new Node(curr->val);
            copies[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while(curr) {
            Node* copy = copies[curr];
            if(curr->next) {
                copy->next = copies[curr->next];
            }
            if(curr->random) {
                copy->random = copies[curr->random];
            }
            curr = curr->next;
        }
        return copies[head];
    }
};
