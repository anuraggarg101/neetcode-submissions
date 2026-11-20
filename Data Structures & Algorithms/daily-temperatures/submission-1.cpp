class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // need to find next greater element for each of these
        stack<int> st{};
        int n = temp.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++) {
            int t = temp[i];
            while(!st.empty() and temp[st.top()] < t) {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};
