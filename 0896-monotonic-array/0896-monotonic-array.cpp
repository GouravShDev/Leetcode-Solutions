class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isAsc = true;
        bool isDesc = true;
        for(int i = 0 ;i < nums.size()-1 ;i++){
            if(nums[i] < nums[i+1]) isDesc = false;
            if(nums[i] > nums[i+1]) isAsc = false;
        }
        return isAsc || isDesc;
    }
};