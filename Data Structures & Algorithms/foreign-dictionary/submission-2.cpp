class Solution {
private:
    bool dfs(unordered_map<char, unordered_set<char>> &adj, char ch, unordered_set<char> &chars, unordered_map<char, int> &visited, string &res) {
        
        visited[ch] = 1;
        for(auto &next:adj[ch]) {
            if(visited[next] == 2) {
                continue;
            } else if(visited[next] == 1) {
                return true;
            } else if (dfs(adj, next, chars, visited, res)) {
                return true;
            }
        }
        visited[ch] = 2;
        res += ch;
        return false;
    }
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        
        int n = words.size();

        unordered_set<char> chars;

        for(int i=0;i<n-1;i++) {
            int l1 = words[i].length();
            int l2 = words[i+1].length();


            // invalid prefix
            if(l1 > l2 and words[i].substr(0, l2) == words[i+1]) {
                return "";
            }
            
            for(int idx = 0; idx<min(l1,l2); idx++) {
                char c1 = words[i][idx];
                char c2 = words[i+1][idx];
                if(c1 != c2) {
                    // c1 < c2
                    adj[c1].insert(c2);
                    break;
                }
            }

            chars.insert(words[i].begin(), words[i].end());
        }
        chars.insert(words[n-1].begin(), words[n-1].end());
        
        unordered_map<char, int> visited{};
        string res = "";

        for(auto &c:chars) {
            if(visited.count(c) == 0) {
                if(dfs(adj, c, chars, visited, res)) {
                    return "";
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;

    }
};
