class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int square[9] = {0};

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                char c = board[i][j];
                bool is_empty = (c == '.');
                // if(is_empty) continue;
                int square_idx = 3*(i/3) + j/3;
                int num = (c - '0');
                if(!is_empty) {
                    int mask = (1 << num);
                    bool row_valid = (row[i] & mask) == 0;
                    bool col_valid = (col[j] & mask) == 0;
                    bool square_valid = (square[square_idx] & mask) == 0;
                    bool valid = row_valid;
                    valid &= col_valid;
                    valid &= square_valid;
                    if(!valid) return false;

                    row[i] |= mask;
                    col[j] |= mask;
                    square[square_idx] |= mask;
                }

            }
        }
        return true;
    }
};
