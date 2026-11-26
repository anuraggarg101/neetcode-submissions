
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
        priority_queue<pair<double, int>> pq{};

        for(int i=0;i<points.size();i++) {
            const auto dist = distance(points[i]);
            pq.push({dist, i});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res{};
        while(!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
