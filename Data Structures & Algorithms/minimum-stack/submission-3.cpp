class MinStack {
private:
    stack<int64_t> st;
    int minVal = INT_MAX;
public:
    MinStack() {        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minVal = val;
        } else if(val >= minVal) {
            st.push(val);
        } else {
            st.push(2LL*val - minVal);
            minVal = val;
        }
    }
    
    void pop() {
        if(st.top() < minVal) {
            minVal = 2*minVal - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < minVal) {
            return minVal;
        } 
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};
