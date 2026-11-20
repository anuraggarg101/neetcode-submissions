class MedianFinder {
private:
    priority_queue<int> max_heap{}; // store first half
    priority_queue<int, vector<int>, greater<int>> min_heap{}; // store second half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);

        min_heap.push(max_heap.top());
        max_heap.pop();
        
        if(min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        int x = min_heap.size();
        int y = max_heap.size();

        if( (x + y) % 2 == 0) {
            return (max_heap.top() + min_heap.top()) * 0.5f;
        } else {
            return max_heap.top();
        }
        return 0;
    }
};
