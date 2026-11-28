class Solution {
private:
    static constexpr int dx[4] = {1, 0, 0, -1};
    static constexpr int dy[4] = {0, 1, -1, 0};

    int n;
    int m;

    bool valid(int x, int y) {
        return x>=0 and x < n and y>=0 and y < m;
    }

    void dfs(vector<vector<char>> &board, int r, int c) {
        board[r][c] = '#';

        for(int k=0;k<4;k++) {
            int x = r + dx[k];
            int y = c + dy[k];
            if(valid(x,y) and board[x][y] == 'O') {
                dfs(board, x, y);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][m-1] == 'O')
                dfs(board, i, m-1);
        }
        
        for(int j=0;j<m;j++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            if(board[n-1][j] == 'O')
                dfs(board, n-1, j);
        }


        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
