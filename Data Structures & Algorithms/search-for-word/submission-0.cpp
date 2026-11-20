class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int i, int j, vector<vector<char>> &board) {
        bool is_valid = (i >= 0);
        is_valid &= (j >= 0);
        is_valid &= (i < board.size());
        is_valid &= (j < board[0].size());
        return is_valid;
    }

    bool helper(vector<vector<char>> &board, string &word, int i, int j, int idx) {
        if(idx >= word.length()) {
            return true;
        }


        if(!isValid(i,j, board)) {
            return false;
        }

        if(board[i][j] != word[idx]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        for(int k=0;k<4;k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(helper(board, word, x,y, idx + 1)) {
                return true;
            } 
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(helper(board, word, i,j,0)) return true;
            }
        }
        return false;
    }
};
