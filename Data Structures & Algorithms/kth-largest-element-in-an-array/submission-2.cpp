class Solution {
private:
    int partition(vector<int> &nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;

        for(int j=low; j<high; j++) {
            if(nums[j] <= pivot) {
                swap(nums[j], nums[++i]);
            }
        }
        swap(nums[++i], nums[high]);
        return i;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int pivotIdx = partition(nums, low, high);

            if(pivotIdx == target) {
                return nums[target];
            } else if(pivotIdx < target) {
                low = pivotIdx+1;
            } else {
                high = pivotIdx - 1;
            }
        }
        return -1;
    }

    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int>, greater<int>> pq{};
    //     for(const auto &n:nums) {
    //         pq.push(n);
    //         if(pq.size() > k) {
    //             pq.pop();
    //         }
    //     }
    //     return pq.top();
    // }
};
