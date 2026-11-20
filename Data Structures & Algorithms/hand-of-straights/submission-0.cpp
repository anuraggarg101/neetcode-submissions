class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> cards(hand.begin(), hand.end());
        
        int cnt = 0;
        while(!cards.empty()) {
            int start = *cards.begin();
            for(int i=0;i<groupSize;i++) {
                auto it = cards.find(start);
                if(it == cards.end()) {
                    return false;
                }
                cards.erase(it);
                start++;
            }
        }
        return true;

    }
};
