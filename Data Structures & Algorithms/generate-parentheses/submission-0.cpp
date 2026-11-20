class Solution {
private:
    void helper(int n, int open, int close, string &temp, vector<string> &res) {
        if(open == n and open == close) {
            res.push_back(temp);
            return;
        }

        if(open < n) {
            temp += '(';
            helper(n, open + 1, close, temp, res);
            temp.pop_back();
        }

        if(close < open) {
            temp += ')';
            helper(n, open, close + 1, temp, res);
            temp.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        int open  = 0;
        int close = 0;
        string temp{};
        vector<string> res{};
        helper(n, open, close, temp, res);
        return res;
    }
};
