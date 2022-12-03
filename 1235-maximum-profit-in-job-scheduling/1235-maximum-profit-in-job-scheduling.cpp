class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,int>> dp;
        vector<vector<int>> jobs;
        for(int i = 0 ; i < startTime.size(); i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        dp.push_back({0,0});
        for(auto &job : jobs){
            int end = job[0];
            int start = job[1];
            int prf = job[2];
            auto it = prev(upper_bound(dp.begin() , dp.end(), make_pair(start , INT_MAX)));
            if(dp.back().second < it->second + prf){
                dp.push_back({end, it->second + prf});
            }
        }
        return dp.back().second;
    }
};