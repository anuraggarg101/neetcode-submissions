class KthLargest {
private:
    struct myComp {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, myComp> min_heap{};
    int k_;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto &n:nums) {
            min_heap.push(n);
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }
        k_ = k;
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size() > k_)
            min_heap.pop();
        int res = min_heap.top();
        return res;
    }
};
