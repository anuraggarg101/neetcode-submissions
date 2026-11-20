class Solution {
public:
    bool isValid(string s) {
        stack<char> st{};
        for(auto &c:s) {
            if(c == '(' or c == '[' or c == '{') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                bool is_valid_top = ( st.top() == '[' and c== ']');
                is_valid_top |= ( st.top() == '{' and c== '}');
                is_valid_top |= ( st.top() == '(' and c== ')');
                
                if(is_valid_top) {
                    st.pop();
                } else {
                    return false;
                }
            }
            
        }
        return st.empty();
    }
};
