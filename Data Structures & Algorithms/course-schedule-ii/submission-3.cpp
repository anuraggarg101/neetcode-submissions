class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &pre:prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q{};
        for(int i=0;i<numCourses;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // if(q.size() == 0) return {};

        int processed = 0;
        vector<int> res{};
        res.reserve(numCourses);

        while(!q.empty()) {
            int n = q.front();
            q.pop();

            res.push_back(n);
            processed++;
            for(auto &x:graph[n]) {
                indegree[x]--;
                if(indegree[x]==0) {
                    q.push(x);
                }
            }
        }

        if(processed < numCourses) return {};
        return res;
    }
};
