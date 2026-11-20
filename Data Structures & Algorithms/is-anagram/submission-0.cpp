class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        std::array<int, 26> s_arr{};
        std::array<int, 26> t_arr{};

        for(auto &c:s) {
            s_arr[c - 'a']++;
        }
        
        for(auto &c:t) {
            t_arr[c - 'a']++;
        }

        for(int i=0;i<26;i++) {
            if(s_arr[i] != t_arr[i]) return false;
        }
        return true;

    }
};
