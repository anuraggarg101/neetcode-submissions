class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;

        while(l <= h) {
            int mid = (l+h)/2;
            if(nums[mid] == target) return mid;
            // else if(nums[l] == target) return l;
            // else if(nums[h] == target) return h;

            else if(nums[mid] > nums[h]) {
                // left is sorted
                if(nums[mid] > target and nums[l] <= target) {
                    // go left
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // right is sorted
                if(nums[mid] < target and nums[h] >= target) {
                    // go right
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};
