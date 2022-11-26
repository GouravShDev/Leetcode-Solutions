class Job{
public:
    int startTime;
    int endTime;
    int profit;
    Job(int st, int et, int p){
        startTime = st;
        endTime= et;
        profit= p;
    }
};

class Solution {
public:
    // find job with max profit before startTime
    int searchMxProfit(vector<pair<int,int>> &dp, int startTime){
        int start = 0;
        int end = dp.size()-1;
        int ans =0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(dp[mid].first<= startTime){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        // pair < endTime, profit> 
        vector<pair<int , int>>  dp;
        vector<Job> jobs;
        for(int i = 0; i < n ; i++){
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin() , jobs.end(),[](auto &a, auto &b){
           return a.endTime < b.endTime; 
        });
        dp.push_back({0,0});
        for(int i =0  ;i < n ; i++){
            auto job= jobs[i];
            int take = searchMxProfit(dp , job.startTime);
            if(dp[take].second + job.profit > dp.back().second){
                dp.push_back({job.endTime, dp[take].second + job.profit});
            }
        }
        return dp.back().second;
    }
};