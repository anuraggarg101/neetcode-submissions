class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st{};
        for(auto &s:tokens) {
            bool is_operator = (s == "+") or (s == "-") or (s == "/") or (s == "*");
            if(is_operator) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                if(s == "+") {
                    st.push(a+b);    
                } else if (s == "-") {
                    st.push(a-b);    
                } else if (s == "/") {
                    st.push(a/b);    
                } else if (s == "*") {
                    st.push(a*b);    
                }
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
