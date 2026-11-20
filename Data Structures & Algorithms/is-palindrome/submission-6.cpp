class Solution {
private:
    char getChar(char c) {
        char res = '-';
        if(c >= 'a' and c <= 'z') res = c;
        else if(c >= 'A' and c <= 'Z') res = c - 'A' + 'a';
        else if(c >= '0' and c <= '9') res = c;
        else res = '-';
        return res;
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            char left = getChar(s[l]);
            char right = getChar(s[r]);
            if(left == '-') l++;
            else if(right == '-') r--;
            else if(left != right) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};
