class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n =plantTime.size();
        vector<pair<int,int>> GPTime(n);
        for(int i= 0 ;i  < n ; i++){
            GPTime[i] = {growTime[i], plantTime[i]};
        }
        sort(GPTime.rbegin(), GPTime.rend());
        int pt = 0;
        int ans = 0;
        for(int i= 0; i < n; i++){
            pt += GPTime[i].second;
            ans = max(ans, pt + GPTime[i].first);
        }
        return ans;
    }
};