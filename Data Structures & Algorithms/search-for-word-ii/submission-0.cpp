class Solution {
private:
    struct TrieNode {
        TrieNode* childs[26]{};
        string word;
        ~TrieNode() {
            for(auto child:childs) {
                delete child;
            }
        }
    };

    TrieNode* root;


    void insert(const string& word) {
        TrieNode* curr = root;
        for(const auto&c:word) {
            int idx = c - 'a';
            if(!curr->childs[idx]) {
                curr->childs[idx] = new TrieNode();
            }
            curr = curr->childs[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string> &res) {
        char ch = board[r][c];
        int idx = ch - 'a';

        TrieNode* next = node->childs[idx];
        if(!next) return;

        if(!next->word.empty()) {
            res.push_back(next->word);
            next->word.clear();
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if(r > 0 and board[r-1][c] != '#') {
            dfs(board, r-1, c, next, res);
        }

        if(r+1<rows and board[r+1][c] != '#')
            dfs(board, r+1, c, next, res);
        
        if(c>0 and board[r][c-1] != '#') {
            dfs(board, r, c-1, next, res);
        }

        if(c+1 < cols and board[r][c+1] != '#')
            dfs(board, r, c+1, next, res);
        
        board[r][c] = ch;
    }

public:
    Solution() {
        root = new TrieNode();
    }
    ~Solution() {
        delete root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() or board[0].empty() or words.empty()) {
            return {};
        }

        for(const string& word:words) {
            insert(word);
        }

        vector<string> res;

        int row = board.size();
        int col = board[0].size();

        for(int r=0;r<row;r++) {
            for(int c=0;c<col;c++) {
                dfs(board, r, c, root, res);
            }
        }
        return res;
    }
};
