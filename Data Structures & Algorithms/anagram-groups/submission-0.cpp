class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp{};
        string temp{};
        for(int i=0;i<strs.size();i++) {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }

        int cnt = mp.size();
        vector<vector<string>> res(cnt);
        int i = 0;
        for(auto &it:mp) {
            for(auto &idx:it.second) {
                res[i].push_back(strs[idx]);
            }
            i++;
        }
        return res;
    }
};
