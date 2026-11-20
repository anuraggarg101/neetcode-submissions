class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int len = s.length();

        std::array<int, 26> fs{};
        std::array<int, 26> ft{};

        for(int i=0;i<len;i++) {
            fs[s[i]-'a']++;
            ft[t[i]-'a']++;
        }

        return fs == ft;

        
    }
};
