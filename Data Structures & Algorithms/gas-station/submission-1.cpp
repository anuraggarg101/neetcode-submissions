class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int remaining_gas = gas[0] - cost[0];
        int n = gas.size();
        if(n == 1) return (remaining_gas >= 0 ? 0 : -1);
        for(int i=1;i<n;i++) {
            if(remaining_gas < 0) {
                start = i;
                remaining_gas = gas[i] - cost[i];
            } else {
                remaining_gas += gas[i] - cost[i];
            }
        }

        for(int i=0;i<start;i++) {
            remaining_gas += (gas[i]  - cost[i]);
            if(remaining_gas < 0) {
                return -1;
            }
            
        }

        return start;


    }
};
