class Solution {
public:
    int solve(vector<int> &nums, int i , int j){
        if(i > j) return 0;
        if(i == j)return nums[i];
        int s = solve(nums, i+1, j-1);
        int ans = max(
            nums[i] + min(s, solve(nums, i+2, j)),
            nums[j] + min(solve(nums, i, j-2), s)
        );
        return ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int player1= solve(nums, 0, nums.size()-1);
        
        return player1 >= (sum - player1);
    }
};