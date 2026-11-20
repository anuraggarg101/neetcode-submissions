class MinStack {
private:
    stack<pair<int, int>> st{};
    int min_ = INT_MAX;
public:
    MinStack() {
        while(!st.empty()) {
            st.pop();
        }
    }
    
    void push(int val) {
        min_ = min(min_, val);
        st.push({val, min_});
    }
    
    void pop() {
        if(!st.empty()) {
            st.pop();
            if(st.empty()) {
                min_ = INT_MAX;
            } else {
                min_ = st.top().second;
            }
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
