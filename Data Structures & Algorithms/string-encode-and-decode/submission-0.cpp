class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string res{""};
        for(int i=0;i<n;i++) {
            const auto &curr = strs[i];
            res += to_string(curr.length());
            res += ",";
            res += curr;
        }
        // std::cout << res << "\n";
        return res; 
    }

    vector<string> decode(string s) {
        vector<string> res{};
        int j = 0;

        while(j < s.length()) {
            int i = j;

            while(s[j] != ',') {
                j++;
            }

            int curr_len = std::stoi(s.substr(i, j-i));
            res.push_back(s.substr(j+1, curr_len));
            j = j + curr_len + 1;
        }
        return res;

    }
};
