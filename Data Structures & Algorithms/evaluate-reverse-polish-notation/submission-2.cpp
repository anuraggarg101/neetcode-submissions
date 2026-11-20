class Solution {
private:
    stack<int64_t> st;

    bool isSign(const string &token) {
        return token == "+" or token == "-" or token == "/" or token == "*";
    }
    
    int64_t processSign(int64_t a, int64_t b, const string &token) {
        if(token == "+") {
            return a + b;
        } else if (token == "-") {
            return a - b;
        } else if (token == "/") {
            return a / b;
        } 
        return a * b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        while(!st.empty()) {
            st.pop();
        }
        for(const auto &token:tokens) {
            if(isSign(token)) {
                int64_t b = st.top();
                st.pop();
                int64_t a = st.top();
                st.pop();
                int64_t res = processSign(a, b, token);
                st.push(res);
            } else {
                st.push(std::stoi(token));
            }
        }
        return st.top();
    }
};
