class Solution {
private:
    vector<string> keys = {"", //0
                            "", //1
                            "abc", //2
                            "def", //3
                            "ghi", //4
                            "jkl", //5
                            "mno", //6
                            "pqrs", //7
                            "tuv", //8
                            "wxyz"}; //9
    
    void helper(string &digits, int idx, string &temp, vector<string> &res) {
        if(idx >= digits.length()) {
            if(temp.length() > 0)
                res.push_back(temp);
            return;
        }

        int num = digits[idx] - '0';
        for(int i=0;i<keys[num].length();i++) {
            char curr = keys[num][i];
            temp.push_back(curr);
            helper(digits, idx+1, temp, res);
            temp.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        string temp{};
        vector<string> res{};
        helper(digits, 0, temp, res);
        return res;
    }
};
