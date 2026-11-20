class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st{};

        int max_area = 0;
        for(int i=0;i<n;i++) {
            while(!st.empty() and heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int l = st.empty() ? -1 : st.top();
                int r = i;
                int w = r - l - 1;
                int area = h * w;
                max_area = max(max_area, area);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int l = st.empty() ? -1 : st.top();
            int r = n;
            int w = r - l - 1;
            int area = w * h;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
