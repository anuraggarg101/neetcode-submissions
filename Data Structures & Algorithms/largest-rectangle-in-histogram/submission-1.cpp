class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int max_area = 0;
        for(int i=0;i<n;i++) {
            while(!st.empty() and heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                int curr_area = h*w;
                max_area = max(curr_area, max_area); 
            }
            st.push(i);
        }    

        while(!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? n : n - st.top() - 1;
            max_area = max(h*w, max_area);
        }
        return max_area;
    }
};
