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

    void helper(int n, int idx, vector<string> &board, vector<int> &col, vector<int> &diag1, vector<int> &diag2, vector<vector<string>> &res) {
        if(idx == n) {
            res.push_back(board);
            return;
        }

        int r = idx;
        for(int c=0; c<n; c++) {
            if(col[c] or diag1[r+c] or diag2[r-c+n-1]) {
                // cannot place quees
                continue;
            }
            // if(canPlaceQueen(board, row, col)) {
                board[r][c] = 'Q';
                col[c] = 1;
                diag1[r+c] = 1;
                diag2[r-c+n-1] = 1;
                helper(n, idx + 1, board, col, diag1, diag2, res);
                col[c] = 0;
                diag1[r+c] = 0;
                diag2[r-c+n-1] = 0;
                board[r][c] = '.';
            // }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res{};
        vector<int> col(n, 0);
        vector<int> diag1(2*n-1,0); // top left
        vector<int> diag2(2*n-1,0); // top right

        helper(n, 0, board, col, diag1, diag2, res);
        return res;
    }
};
