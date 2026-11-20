class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        // vector<int> pre_max(n, 0);
        // vector<int> suff_max(n, 0);

        // for(int i=1;i<n;i++) {
        //     pre_max[i] = max(height[i-1], pre_max[i-1]);
        //     suff_max[n-i -1 ] = max(height[n-i], suff_max[n-i]);
        // }

        int left_max = 0;
        int right_max = 0;
        int sum = 0;
        while(l < r) {
            if(height[l] < height[r]) {
                left_max = max(left_max, height[l]);
                sum += (left_max - height[l]);
                l++;
            } else {
                right_max = max(right_max, height[r]);
                sum += (right_max - height[r]);
                r--;
            }
        }
        return sum;

    }
};
