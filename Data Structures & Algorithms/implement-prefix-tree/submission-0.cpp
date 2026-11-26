class PrefixTree {
private:
    std::array<PrefixTree*, 26> childs;
    bool isEnd = false;

public:
    PrefixTree() {
        childs.fill(nullptr);
    }
    
    ~PrefixTree() {
        for(auto child:childs) {
            delete child;
        }
    }

    void insert(string word) {
        PrefixTree* curr = this;
        for(char c:word) {
            int idx = c - 'a';
            
            if(!curr->childs[idx]) {
                curr->childs[idx] = new PrefixTree();
            }
            
            curr = curr->childs[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        PrefixTree* curr = this;
        for(char c:word) {
            int idx = c - 'a';
            if(!curr->childs[idx]) {
                return false;
            }
            curr = curr->childs[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr = this;
        for(char c:prefix) {
            int idx = c - 'a';
            if(!curr->childs[idx]) {
                return false;
            }
            curr = curr->childs[idx];
        }
        return true;
    }
};
