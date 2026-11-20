class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp{};
        for(int i=0;i<strs.size();i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        
        vector<vector<string>> res{};
        for(auto &it:mp){
            vector<string> temp{};
            for(auto &n:it.second) {
                temp.push_back(strs[n]);
            }
            res.emplace_back(std::move(temp));
        }
        return res;
    }
};
