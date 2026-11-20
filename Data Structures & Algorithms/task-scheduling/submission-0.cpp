class Solution {
private:
    using QType = pair<int, char>;
    struct myComp {
        bool operator()(QType a, QType b) {
            return a.first < b.first;
        }
    };
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq{};
        for(auto &c:tasks) {
            freq[c]++;
        }

        priority_queue<QType, vector<QType>, myComp> pq{};
        for(auto &it:freq) {
            pq.push({it.second, it.first});
        }

        queue<pair<QType, int>> q{};
        int t = 0;
        vector<char> res{};
        while(!pq.empty() or !q.empty()) {
            while(!q.empty()) {
                auto tp = q.front();
                int t_ = tp.second;
                if(t >= t_) {
                    pq.push(tp.first);
                    q.pop();
                } else {
                    break;
                }
            }

            if(!pq.empty()) {
                auto tp = pq.top();
                pq.pop();
                char c = tp.second;
                int f = tp.first;
                res.push_back(c);
                f--;
                if(f > 0) {
                    q.push({{f,c}, t+n+1});
                }
            } else {
                res.push_back('#');
            }

            
            t++;
        }
        for(auto &c:res) {
            cout << c << ","; 
        }
        return res.size();
    }
};
