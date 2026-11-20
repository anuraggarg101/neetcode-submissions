class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size(); 

        int l = 0;
        int r = n*m-1;

        while(l <= r) {
            int mid = (r + l ) /2;
            
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                r = row*m + col - 1;
            } else {
                l = row * m + col + 1;
            }
        }
        return false;
    }
};
