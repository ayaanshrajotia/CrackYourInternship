class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalDiff = 0;
        int index = 0, fuel = 0;

        for (int i=0; i<gas.size(); i++) {
            int diff = gas[i] - cost[i];
            totalDiff += diff;
            fuel += diff;

            if (fuel < 0) {
                index = i + 1;
                fuel = 0;
            }
        }

        return (totalDiff < 0) ? -1 : index;
    }
};