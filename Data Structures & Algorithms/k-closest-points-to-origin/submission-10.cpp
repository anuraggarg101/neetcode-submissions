// struct myComp {
//     static bool operator()(const pair<int64_t, int> &a, const pair<int64_t, int> &b) {
//         return a.first < b.first;
//     }
// };

class Solution {
struct myComp {
    static bool operator()(const pair<int64_t, int> &a, const pair<int64_t, int> &b) {
        return a.first < b.first;
    }
};

private:
    int64_t distance(const vector<int> &a) {
        int64_t dx = (a[0] - 0);
        int64_t dy = (a[1] - 0);
        int64_t dist = dx*dx + dy*dy;
        return dist;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using QType = pair<int64_t, int>;

        priority_queue<QType, vector<QType>, myComp> pq{};

        for(int i=0;i<points.size();i++) {
            const auto dist = distance(points[i]);
            pq.push({dist, i});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        res.reserve(k);
        while(!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
