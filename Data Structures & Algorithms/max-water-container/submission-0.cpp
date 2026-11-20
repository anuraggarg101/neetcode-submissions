class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int n = heights.size();
        int r = n - 1;
        
        int max_l = 0;
        int max_r = n-1;

        int ans = 0;
        while(l < r) {
            if(heights[l] > heights[max_l]) {
                max_l = l;
            }
            if(heights[r] > heights[max_r]) {
                max_r = r;
            }

            int curr_area = min(heights[max_l], heights[max_r]) * (max_r - max_l);
            ans = max(ans, curr_area);
            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
