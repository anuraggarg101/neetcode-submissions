class Solution {
private:
    static bool myComp(const pair<int, int>&a, const pair<int, int>& b) {
        return a.first > b.first;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for(int i=0; i<n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), myComp);

        // cars is sorted in decreasing order of position
        stack<float> st;

        int numFleets = 0;
        double lastFleetTime = 0;

        // logic goes here
        for(const auto &car:cars) {
            float time = static_cast<float>(target - car.first)/car.second;

            if(time > lastFleetTime) {
                numFleets++;
                lastFleetTime = time;
            }
        }
        return numFleets;
    }
};
