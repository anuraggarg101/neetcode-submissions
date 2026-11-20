class Solution {
private:
    bool isAlphaNumeric(char c) {
        bool res  = (c >= 'A') and (c <= 'Z');
        res |= (c >= 'a') and (c <= 'z');
        res |= (c >= '0' and c <= '9');
        return res;
    }

    char toLowerCase(char c) {
        if (c >= 'A' and c <= 'Z') return c - 'A' +  'a';
        return c;
    }
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while(start < end) {
            if(!isAlphaNumeric(s[start])) {
                start++;
                continue;
            }
            if(!isAlphaNumeric(s[end])) {
                end--;
                continue;
            }
            bool is_same = (s[start] == s[end]);
            is_same |= (toLowerCase(s[start]) == toLowerCase(s[end]));
            if(is_same) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};
