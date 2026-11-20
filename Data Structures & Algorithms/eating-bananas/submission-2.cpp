class Solution {
private:
    int findHours(vector<int> &piles, int rate) {
        int hours = 0;
        for(const auto &pile:piles) {
            hours += pile / rate;
            if(pile % rate > 0) {
                hours += 1;
            }
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int total = 0;
        int max_ = 0;
        for(const auto &pile:piles) {
            total += pile;
            max_ = max(max_, pile);
        }

        int l = 1;
        int r = max_;

        while(l < r) {
            int mid = (r + l) /2;
            int num_hours = findHours(piles, mid);
            if(num_hours > h) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
