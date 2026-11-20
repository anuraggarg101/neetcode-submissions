class Solution {
public:
    bool isValid(string s) {
        stack<char> st{};
        for(const auto &c:s) {
            if(c == '(' or c == '{' or c == '[') {
                st.push(c);
                continue;
            }
            if(st.empty()) return false;
            bool valid = false;
            valid |= (c == ')') and (st.top() == '(');
            valid |= (c == '}') and (st.top() == '{');
            valid |= (c == ']') and (st.top() == '[');
            if(!valid) return false;
            else {
                st.pop();
            }
        }
        return st.empty();
    }
};
