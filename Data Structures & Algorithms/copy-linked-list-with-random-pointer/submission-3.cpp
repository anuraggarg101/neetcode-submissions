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
/*
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
        return head ? copies[head] : nullptr;
    }
*/
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* curr = head;
        while(curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        Node* listCopy = curr->next;

        // join random pointer    
        while(curr) {
            Node* copy = curr->next;

            Node* random = curr->random;
            if(random) {
                copy->random = random->next;
            } else {
                copy->random = nullptr;
            }
            curr = copy->next;
        }

        // delink new nodes and fix next pointer
        curr = head;
        while(curr) {
            Node* copy = curr->next;
            Node* next = copy->next;
            if(next) {
                copy->next = next->next;
                curr->next = next;
            } else {
                copy->next = nullptr;
                curr->next = nullptr;
            }
            curr = curr->next;
        }
        return listCopy;
    }
};
