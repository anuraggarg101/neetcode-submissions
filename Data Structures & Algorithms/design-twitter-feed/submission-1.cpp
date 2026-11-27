class Twitter {
private:
    struct Tweet {
        int timestamp;
        int tweetId;
        int userId;
        int index;

        bool operator<(const Tweet& other) const {
            return timestamp < other.timestamp;
        }
    };

    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> following;

    int timestamp = 0;;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> pq;

        following[userId].insert(userId);

        for(int followeeId:following[userId]) {
            auto it = posts.find(followeeId);

            if(it == posts.end() or it->second.empty()) {
                continue;
            }

            int idx = it->second.size() - 1;
            auto [time, tweetId] = it->second[idx];
            pq.push({time, tweetId, followeeId, idx});
        }

        vector<int> feed;
        feed.reserve(10);

        while(!pq.empty() and feed.size() < 10) {
            Tweet curr = pq.top();
            pq.pop();

            feed.push_back(curr.tweetId);

            if(curr.index > 0) {
                int next_idx = curr.index - 1;

                auto [time, tweet_id] = posts[curr.userId][next_idx];

                pq.push({time, tweet_id,curr.userId,next_idx});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].erase(followeeId);

    }
};
