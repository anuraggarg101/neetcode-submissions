class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;

        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i=0; i<temperatures.size(); i++) {

            while(!st.empty() and temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};
