class Solution {
private:
    bool canPlaceQueen(vector<string> &board, int r, int c) {
        // if(board[r][c] == 'Q') return false;

        int n = board.size();

        for(int i=0;i<n;i++) {
            if(board[i][c] == 'Q') return false;
        }

        // for(int j=0;j<n;j++) {
        //     if(board[r][j] == 'Q') return false;
        // }

        // four diagonal
        // 1. top left
        int i = r-1;
        int j = c-1;
        while(i>=0 and j>=0) {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        // 2. top right
        i=r-1;
        j=c+1;
        while(i>=0 and j<n) {
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        
        // // 3. bottom right
        // i=r;
        // j=c;
        // while(i<n and j<n) {
        //     if(board[i][j] == 'Q') return false;
        //     i++;
        //     j++;
        // }

        // // 4. bottom left
        // i=r;
        // j=c;
        // while(i<n and j>=0) {
        //     if(board[i][j] == 'Q') return false;
        //     i++;
        //     j--;
        // }
        return true;
    }

    void helper(int n, int idx, vector<string> &board, vector<vector<string>> &res) {
        if(idx == n) {
            res.push_back(board);
            return;
        }

        int row = idx;
        for(int col=0; col<n; col++) {
            if(canPlaceQueen(board, row, col)) {
                board[row][col] = 'Q';
                helper(n, idx + 1, board, res);
                board[row][col] = '.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res{};
        helper(n, 0, board, res);
        return res;
    }
};
