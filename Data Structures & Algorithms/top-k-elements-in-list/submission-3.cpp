class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq{};
        for(auto &n:nums) {
            freq[n]++;
        }

        int n = nums.size();
        vector<vector<int>> sorted_by_freq(n+1, vector<int>());

        for(auto &it:freq) {
            int num = it.first;
            int freq = it.second;
            sorted_by_freq[freq].push_back(num);
        }

        vector<int> res{};
        for(int i=n;i>=0;i--) {
            int freq = i;
            for(int j=0;j<sorted_by_freq[i].size();j++) {
                res.push_back(sorted_by_freq[i][j]);
                if(res.size() == k) return res;
            }
        }

        return res;
    }
};
