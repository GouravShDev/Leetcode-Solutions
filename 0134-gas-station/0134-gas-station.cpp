class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int start = 0;
        int n = gas.size();
        int curPetrol = 0;
        int gasSum = 0;
        int costSum = 0;
        while(i < n){
            gasSum+= gas[i];
            costSum += cost[i];
            curPetrol += gas[i];
            curPetrol -= cost[i];
            if(curPetrol < 0){
                curPetrol = 0;
                start = i+1;
            }
            i++;
                
        }
        if(gasSum < costSum)return -1;
        return start ;
    }
};