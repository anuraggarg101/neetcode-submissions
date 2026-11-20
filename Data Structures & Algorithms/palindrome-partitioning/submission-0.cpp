class Solution {
private:
    bool isPalindrome(string &s) {
        int start = 0;
        int end = s.length() - 1;
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    void helper(string &s, int idx, vector<string>&temp, vector<vector<string>> &res) {
        if(idx >= s.length()) {
            res.push_back(temp);
            return;
        }

        for(int i=idx;i<s.length();i++) {
            string s_ = s.substr(idx, i-idx+1);
            if(isPalindrome(s_)) {
                // cut at i
                temp.push_back(s_);
                helper(s, i+1, temp, res);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp{};
        vector<vector<string>> res{};
        helper(s, 0, temp, res);
        return res;
    }
};
