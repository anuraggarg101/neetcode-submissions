class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq{};
    int capacity = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        for(const auto &n:nums) {
            pq.push(n);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        capacity = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > capacity)
            pq.pop();
        return pq.top();
    }
};
