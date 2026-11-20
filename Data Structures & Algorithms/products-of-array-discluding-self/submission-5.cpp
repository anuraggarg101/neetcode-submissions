class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = 1;
        vector<int> res(n, 1);
        for(int i=0;i<n;i++) {
            res[i] *= left;
            left *= nums[i];

            res[n-1-i] *= right;
            right *= nums[n-1-i];
        }
        return res;

        /*
        for(int i=1;i<n;i++) {
            res[i] = res[i-1] * nums[i-1];
        }

        int prod = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            res[i] *= prod;
            prod *= nums[i];
        }*/
        return res;
    }
};
