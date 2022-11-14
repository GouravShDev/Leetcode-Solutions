class Solution {
public:
    void solve(vector<int> &nums, vector<int> &cur,  vector<int>& taken , vector<vector<int>> &ans){
       if(cur.size() == nums.size()){
           ans.push_back(cur);
           return;
       }
        for(int i =0 ;i < nums.size(); i++){
            if(!taken[i]){
                cur.push_back(nums[i]);
                taken[i] = 1;
                solve(nums, cur, taken, ans);
                taken[i] = 0;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> taken(nums.size());
        vector<vector<int>> ans;
        vector<int> cur;
        solve(nums , cur, taken, ans);
        return ans;
    }
};