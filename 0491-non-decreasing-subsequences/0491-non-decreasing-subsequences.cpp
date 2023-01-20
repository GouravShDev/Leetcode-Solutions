class Solution {
public:
    set<vector<int>> st;
    void dfs(vector<int> &nums, vector<int> &cur, int index, vector<vector<int>> &ans){
        if(cur.size() > 1 && !st.count(cur)) {st.insert(cur); ans.push_back(cur);}
        int lastTaken = -101;
        for(int i =index ;i < nums.size() ; i++){
            if(nums[i] != lastTaken && (cur.empty() || nums[i] >= cur.back())){
                cur.push_back(nums[i]);
                dfs(nums, cur, i+1, ans);
                cur.pop_back();
                lastTaken = nums[i];
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, cur, 0, ans);
        return ans;
    }
};