class Solution {
public:
    void solve(vector<int> &nums, int index, vector<int> &cur, vector<vector<int>> &ans){
        ans.push_back(cur);
        int last = -1111;
        for(int i = index ; i < nums.size() ; i++){
            if(nums[i] == last) continue;
            cur.push_back(nums[i]);
            solve(nums, i+1, cur, ans);
            cur.pop_back();
            last = nums[i];
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        solve(nums, 0 , cur , ans);
        return ans;
    }
};