class Twitter {
private:

    unordered_map<int, vector<pair<int, int>>> tweets{};
    unordered_map<int, unordered_set<int>> following{};
    int t;

    struct Node {
        int time;
        int tweetId;
        int userId;
        int idx;
        
        bool operator<(const Node &other) const {
            return time < other.time;
        } 
    };
public:
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);
        priority_queue<Node> pq{};

        for(auto &followee:following[userId]) {
            auto &vec = tweets[followee];
            if(vec.size() > 0) {
                int idx = vec.size() - 1;
                pq.push({vec[idx].first, vec[idx].second, followee, idx});
            }
        }

        vector<int> res{};
        while(!pq.empty() and res.size() < 10) {
            auto node = pq.top();
            pq.pop();
            res.push_back(node.tweetId);
            int next_idx = node.idx - 1;
            if(next_idx >= 0) {
                pq.push({tweets[node.userId][next_idx].first, tweets[node.userId][next_idx].second, node.userId, next_idx});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);       
    }
    
    void unfollow(int followerId, int followeeId) {
        auto &list_ = following[followerId];
        if(list_.find(followeeId) != list_.end()) {
            list_.erase(followeeId);
        }
    }
};
