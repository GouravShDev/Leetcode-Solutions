class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
       vector<int> requiredRocks;
        int n = rocks.size();
        for(int i=0 ;i < n ;i++){
            requiredRocks.push_back( capacity[i] - rocks[i]);
        }
        sort(requiredRocks.begin(), requiredRocks.end());
        int ans = 0;
        while( ans < n &&(additionalRocks-requiredRocks[ans]) >= 0){
            additionalRocks -= requiredRocks[ans++];
        }
        return ans;
    }
};