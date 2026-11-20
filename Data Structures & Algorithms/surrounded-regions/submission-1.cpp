class Solution {
private:
    int n{};
    int m{};
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    bool isValid(int i, int j) {
        return (i>=0) and (i<n) and (j>=0) and (j<m);
    }
    
    void dfs(vector<vector<char>> &board, int r, int c) {
        // if(board[r][c] == '-') return;

        board[r][c] = '-';
        for(int i=0;i<4;i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(isValid(x, y) and board[x][y] == 'O') {
                dfs(board, x, y);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n == 0) return;

        m = board[0].size();

        
        for(int i=0;i<n;i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            
            if(board[i][m-1] == 'O') {
                dfs(board, i, m-1);
            }
        }

        for(int j=0;j<m;j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            
            if(board[n-1][j] == 'O') {
                dfs(board, n-1, j);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == '-') {
                    board[i][j] = 'O';
                }
            }
        }
        return;

    }
};
