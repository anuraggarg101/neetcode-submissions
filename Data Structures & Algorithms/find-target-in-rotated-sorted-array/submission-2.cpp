class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        while(l <= r) {
            int mid = (r+l)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > nums[r]) {
                // left part is sorted
                if(nums[mid] > target and nums[l] <= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // right part is sorted
                if(nums[mid] < target and nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
