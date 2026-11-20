class Solution {
private:
    double getDist(int x, int y) {
        int dx = x*x;
        int dy = y*y;
        return sqrt(dx+dy);
    }
    using Point = vector<int>;
    using QType = pair<double, Point>;

    struct myComp {
        bool operator()(QType &a, QType &b) {
            return a.first < b.first;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<QType, vector<QType>, myComp> pq{};
       
       for(auto &vec:points) {
            pq.push({getDist(vec[0], vec[1]), {vec[0], vec[1]}});
            if(pq.size() > k) {
                pq.pop();
            }
       }

       vector<vector<int>> res{};
        while(!pq.empty()) {
            res.push_back({pq.top().second[0], pq.top().second[1]});
            pq.pop();
        }
        return res;

    }
};
