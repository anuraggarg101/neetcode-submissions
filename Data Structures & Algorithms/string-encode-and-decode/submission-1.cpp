class Solution {
private:
    int getInteger(string &s, int &idx) {
        char c = s[idx];
        // c should be equal to '#'
        idx++;
        c = s[idx];
        string res = "";
        while(c != '#') {
            res += s[idx++];
            c = s[idx];
        }

        idx++;
        return stoi(res); 
    }

    string getString(int n) {
        string res = "#";
        res += to_string(n);
        res += "#";
        return res;
    }
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        res += getString(n);
        for(auto &str:strs) {
            res += getString(str.size());
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int idx = 0;
        vector<string> res{};
        int n = getInteger(s, idx);
        for(int i=0;i<n;i++) {
            int m = getInteger(s, idx);
            res.push_back(s.substr(idx, m));
            idx += m;
        }
        return res;
    }
};
