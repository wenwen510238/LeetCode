class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int startTank = 0;
        int currTank = 0;
        int totalTank = 0;
        for(int i=0; i<n; i++){
            int remain = gas[i] - cost[i];
            totalTank += remain;
            currTank += remain;
            if(currTank < 0){
                startTank = i + 1;
                currTank = 0;
            }
        }
        if(totalTank < 0)   return -1;
        else    return startTank;
        return -1;
    }
};