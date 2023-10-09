class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int leftIndex = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int rightIndex = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(leftIndex >= nums.size() || nums[leftIndex] != target) return {-1, -1};
        return {leftIndex, rightIndex-1};
        
    }
};