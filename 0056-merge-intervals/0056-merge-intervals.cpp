class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),[ ]  (vector<int>& a,vector<int>& b)
             {
                 return a[0] < b[0];
             }
            );
        ans.push_back(intervals[0]);
        int i = 1;
        while(i < intervals.size()){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        
        return ans;
    }
};