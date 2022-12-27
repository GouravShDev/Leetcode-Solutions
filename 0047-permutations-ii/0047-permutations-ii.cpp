class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int> &nums, int index , vector<vector<int>> &ans){
        if(index == nums.size()){
            if(!st.count(nums)){
            ans.push_back(nums);
                st.insert(nums);
                
            }
            return;
        }
        int lastPicked = -1888;
        for(int i = index; i < nums.size() ; i++){
            if(lastPicked != nums[i]){
                lastPicked = nums[i];
                swap(nums[i], nums[index]);
                solve(nums, index+1, ans);
                swap(nums[i], nums[index]);
            }
        }
            
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
       vector<vector<int>> ans;
        solve(nums , 0, ans);
        return ans;
    }
};