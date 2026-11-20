class Solution {
private:
    int findMax(vector<int> &vec) {
        int max_ = INT_MIN;
        for(auto &n:vec) {
            max_ = max(n, max_);
        }
        return max_;
    }

    int findHours(vector<int> &vec, int speed) {
        int hours = 0;
        for(auto &p:vec) {
            hours += (p + speed - 1) /speed;
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int tgt) {
        int l = 1;
        int h = findMax(piles);
        
        int k = h;
        while(l <= h) {
            int mid = l + (h-l)/2;
            int hours = findHours(piles, mid);
            if(hours <= tgt) {
                // k = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            } 
        }
        return l;
    }
};
