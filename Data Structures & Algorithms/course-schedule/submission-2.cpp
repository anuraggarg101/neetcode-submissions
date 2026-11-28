class Solution {
private:
    bool isCycle(int i, unordered_map<int, vector<int>> &graph, vector<int> &order, vector<int> &visited) {

        visited[i] = 1;
        for(auto &n:graph[i]) {
            if(visited[n] == 1) {
                return true;
            } else if (visited[n] == 0) {
                if(isCycle(n, graph, order, visited)) {
                    return true;
                }
            }
        }

        visited[i] = 2;
        order.push_back(i);
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order{};
        order.reserve(numCourses);

        unordered_map<int, vector<int>> graph{};
        for(const auto &pre:prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        std::vector<int> visited(numCourses, 0);
        for(int i=0;i<numCourses;i++) {
            if(visited[i] == 0) {
                if(isCycle(i, graph, order, visited)) {
                    return false;
                }
            }
        }
        reverse(order.begin(), order.end());
        for(auto &n:order) {
            std::cout << n << ",";
        }
        return true;
    }
};
