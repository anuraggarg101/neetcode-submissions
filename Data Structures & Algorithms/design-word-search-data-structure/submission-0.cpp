class WordDictionary {
private:
    
    struct TrieNode {
        TrieNode* children[26]{};
        bool isEnd = false;
        ~TrieNode() {
            for(auto child:children) {
                delete child;
            }
        }
    };

    TrieNode* root;

    bool dfs(const string& word, int idx, TrieNode* node) {
        if(idx == word.size()) {
            return node->isEnd;
        }

        char c = word[idx];
        
        if(c == '.') {
            for(auto child:node->children) {
                if(child and dfs(word, idx+1, child)) {
                    return true;
                }
            }
            return false;
        }
        int pos = c - 'a';
        if(!node->children[pos]) {
            return false;
        }
        return dfs(word, idx+1, node->children[pos]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }

    void addWord(string word) {
        auto curr = root;
        for(auto c:word) {
            int idx = c - 'a';
            if(!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
