struct myCompare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq{};
        for(auto &n:nums) {
            freq[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> pq{};
        for(auto &f:freq) {
            pq.push({f.first, f.second});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res{};
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            res.push_back(tp.first);
        }
        return res;
    }
};
