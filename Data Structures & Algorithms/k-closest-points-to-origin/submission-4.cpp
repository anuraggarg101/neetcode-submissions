class Solution {
private:

    double distance(const vector<int> &a) {
        int64_t dx = (a[0] - 0);
        int64_t dy = (a[1] - 0);
        double dist = dx*dx + dy*dy;
        return dist;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq{};

        for(const auto &point:points) {
            const auto dist = distance(point);
            pq.push({dist, point});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res{};
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
