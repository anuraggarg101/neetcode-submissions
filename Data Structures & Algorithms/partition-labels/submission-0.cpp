class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp{}; // char -> first occurence, last occurence
        
        int n = s.length();

        for(int i = 0; i<n; i++) {
            char c = s[i];
            if(mp.find(c) == mp.end()) {
                mp[c] = {i, i};
            } else {
                mp[c].second = i;
            }
        }

        vector<int> res{};
        int idx = 0;
        while(idx < n) {
            // substring start at idx
            int start = idx;
            char c = s[idx];
            int end = mp[c].second; // candidate end. now this end shall be the max of ending of all chars from [start...end]
            idx = start+1;
            int max_end = end;
            while(idx < n and idx < max_end) {
                char c = s[idx];
                int curr_end = mp[c].second;
                max_end = max(curr_end, max_end);
                idx++;
            }
            end = max_end;
            res.push_back(max_end - start + 1);
            idx = max_end + 1;
        }
        return res;
    }
};
