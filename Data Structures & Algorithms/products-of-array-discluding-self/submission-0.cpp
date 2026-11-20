class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for(int i=0;i<n;i++) {
            prefix[i] = nums[i] * ( i == 0 ? 1 : prefix[i-1]);
            suffix[n-i-1] = nums[n-i-1] * ( i == 0 ? 1 : suffix[n-i]);
        }

        vector<int> res(n,1);
        for(int i=0;i<n;i++) {
            int pre = (i == 0 ? 1: prefix[i-1]);
            int suf = (i == n-1 ? 1: suffix[i+1]);
            res[i] = pre * suf;
        }
        return res;
        

    }
};
