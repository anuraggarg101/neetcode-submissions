class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq{};
        for(const auto &n:stones) {
            pq.push(n);
        }

        while(pq.size() > 1) {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            if(x != y) {
                pq.push(abs(x-y));
            } 
        }
        return pq.empty() ? 0 : pq.top();
    }
};
