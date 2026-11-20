class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph{};
        unordered_map<char, int> indegree{};
        int n = words.size();
        
        for(auto &word:words) {
            for(auto &ch:word) {
                indegree[ch] = 0;
            }
        }

        for(int i=0;i<n-1;i++) {
            string &w1 = words[i];
            string &w2 = words[i+1];

            int len = min(w1.length(), w2.length());
            int j = 0;
            while(j<len and w1[j] == w2[j]) {
                j++;
            }
            
            if(j == len and w1.length() > w2.length()) {
                // this case isn't possible
                // ["abc", "ab"] -> invalid sort
                return "";
            }

            if(j < len) {
                // only in this case we can get useful information
                char a = w1[j];
                char b = w2[j];
                if(graph[a].count(b)==0) {
                    graph[a].insert(b);
                    indegree[b]++;
                }
            }
        }

        

        queue<char> q{};
        string res{};
        
        for(auto &it:indegree) {
            if(it.second == 0) {
                q.push(it.first);
            }
        }

        while(!q.empty()) {
            char x = q.front();
            q.pop();
            
            res.push_back(x);
            for(auto &y:graph[x]) {
                indegree[y]--;
                if(indegree[y] == 0) {
                    q.push(y);
                }
            }
        }

        if(res.length() != indegree.size()) return "";
        return res;

    }
};
