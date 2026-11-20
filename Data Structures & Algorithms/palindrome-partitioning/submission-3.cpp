class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    void helper(string &s, int idx, vector<string>&temp, vector<vector<string>> &res, vector<vector<bool>> &pal) {
        if(idx >= s.length()) {
            res.push_back(temp);
            return;
        }

        for(int i=idx;i<s.length();i++) {
            if(pal[idx][i]) {
                // cut at i
                temp.push_back(s.substr(idx, i-idx+1));
                helper(s, i+1, temp, res, pal);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();

        // pal[i][j] = whether s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // fill DP table
        for(int i = n - 1; i >= 0; i--) {

            for(int j = i; j < n; j++) {

                if(s[i] == s[j]) {

                    // length 1 or 2
                    if(j - i <= 1) {
                        pal[i][j] = true;
                    }
                    else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }

        vector<string> temp{};
        vector<vector<string>> res{};
        helper(s, 0, temp, res, pal);
        return res;
    }
};
