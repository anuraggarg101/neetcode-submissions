class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for(int r = 0; r<9; r++) {
            for(int c=0; c<9; c++) {
                if(board[r][c] == '.') continue;

                int val = board[r][c] - '1'; // bit idx

                bool present_in_r = rows[r] & (1 << val);
                bool present_in_c = cols[c] & (1 << val);
                int idx_sqr = (r / 3)*3 + c/3;
                bool present_in_sqr = squares[idx_sqr] & ( 1 << val);
                
                if(present_in_r or present_in_c or present_in_sqr) {
                    return false;
                }

                rows[r] |= (1 << val);
                cols[c] |= (1 << val);
                squares[idx_sqr] |= (1 << val);
            }
        }
        return true;
                

    }
};
