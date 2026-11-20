class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars{};
        int n = position.size();
        for(int i=0;i<n;i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        int n_fleets = 0;
        double prev_time = 0;
        for(auto &car:cars) {
            double curr_time = (target - car.first) / static_cast<double>(car.second);

            if(curr_time > prev_time) {
                n_fleets++;
                prev_time = curr_time;
            }
        }
        return n_fleets;
    }
};
