class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> pre_max(n, 0);
        vector<int> suff_max(n, 0);

        for(int i=1;i<n;i++) {
            pre_max[i] = max(height[i-1], pre_max[i-1]);
            suff_max[n-i -1 ] = max(height[n-i], suff_max[n-i]);
        }

        int sum = 0;
        for(int i=0;i<n;i++) {
            int curr_water = min(pre_max[i], suff_max[i]) - height[i];
            sum += max(curr_water, 0);
        }
        return sum;

    }
};
