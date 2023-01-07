class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int gasSum = 0;
        int costSum = 0;
        int curSum = 0;
        for(int i = 0;i < gas.size(); i++){
            gasSum += gas[i];
            costSum += cost[i];
            curSum += gas[i];
            if(curSum < cost[i]){
                curSum = 0;
                start = i+1;
            }else{
                curSum -= cost[i];
            }
        }
        if(gasSum < costSum) return -1;
        return start;
    }
};