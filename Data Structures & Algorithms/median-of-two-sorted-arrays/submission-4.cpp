class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(m < n) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n;
        
        int half = (n+m+1)/2;

        while(l <= r) {
            int i = (l+r)/2;
            int j =  half - i;

            int left1 =  (i == 0) ? INT_MIN : nums1[i-1];
            int right1 =  (i == n) ? INT_MAX : nums1[i];


            int left2 =  (j == 0) ? INT_MIN : nums2[j-1];
            int right2 =  (j == m) ? INT_MAX : nums2[j];

            if(left1 > right2) {
                // too many elemts in nums1
                r = i-1;
            } else if(left2 > right1) {
                // too less elemts in nums1
                l = i+1;
            } else {
                if((n+m)%2 == 1) {
                    return max(left1, left2);
                } else {
                    return static_cast<double>(max(left1, left2) + min(right1, right2)) / 2;
                }
            }
            
        }
        return 0;   
    }
};
