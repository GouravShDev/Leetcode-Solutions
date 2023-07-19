class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int lastEnd = -1e6;
        int ans = 0;
        for(int i = 0 ; i< intervals.size(); i++){
            if(intervals[i][0] < lastEnd){
                ans++;
                if(lastEnd > intervals[i][1]) lastEnd = intervals[i][1];
                continue;
            }
            lastEnd = intervals[i][1];
        }
        return ans;
    }
};