class Solution {
public:
    int findMin(vector<int> &nums) { 
        int n = nums.size();
        int l = 0;
        int h = n-1;
        
        
        while(l <= h) {
            if(nums[l] <= nums[h]) 
                return nums[l];
            
            int mid = (l+h)/2;
            int left = nums[(mid + n - 1) % n];
            int right = nums[(mid + 1)%n];
            if(nums[mid] < left and nums[mid] < right) {
                return nums[mid];
            } else if(nums[l] <= nums[mid]) {
                l = mid + 1;
            } else if(nums[mid] <= nums[h]) {
                h = mid - 1;
            }
        }
        return 0;
    }
};
