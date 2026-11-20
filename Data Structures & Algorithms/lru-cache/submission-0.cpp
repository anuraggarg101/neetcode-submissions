struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int val_) : val(val_), next(nullptr), prev(nullptr) {}
    ListNode() : val(0), next(nullptr), prev(nullptr) {} 
};

class LRUCache {
private:
    // ListNode* nodes;
    ListNode* head;
    ListNode* tail;
    
    int capacity_{};
    int used{};

    unordered_map<int, int> store{};
    unordered_map<int, ListNode*> ref{};
    
    void removeHelper(ListNode* node) {
        // move this node to front of list, to head->next
        ListNode* prev_node = node->prev;
        ListNode* next_node  = node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    void insertHelper(ListNode* node) {
        ListNode *end = tail->prev;
        end->next = node;
        node->prev = end;
        node->next = tail;
        tail->prev = node;
    }

    void accessNode(ListNode* node) {
        removeHelper(node);
        insertHelper(node);    
    }

    void accessKey(int key) {
        ListNode* ref_node = ref[key];
        accessNode(ref_node);
    }
    void insertNode(ListNode* node) {
        insertHelper(node);
    }

    void insertNewKey(int key) {
        ListNode* node = new ListNode(key);
        insertNode(node);
        ref[key] = node;
        used++;
    }

    int findLowestPriorityKey() {
        return head->next->val;
    }

    void removeKey(int key) {
        ListNode *node = ref[key];
        removeHelper(node);
        ref.erase(key);
        delete node;
        used--;
    }

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        used = 0;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        bool is_present = (store.find(key) != store.end());
        if(is_present) {
            int val = store[key];
            accessKey(key);
            return val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        bool already_present = (store.find(key) != store.end());
        if(already_present) {
            // update store
            store[key] = value;
            
            // update priority of this node
            accessKey(key);
        } else {
            if(used < capacity_) {
                store[key] = value;
                insertNewKey(key);
            } else {
                // remove lowest priority
                int key_to_remove = findLowestPriorityKey();
                store.erase(key_to_remove);
                removeKey(key_to_remove);

                store[key] = value;
                insertNewKey(key);
            }
        }
    }
};
