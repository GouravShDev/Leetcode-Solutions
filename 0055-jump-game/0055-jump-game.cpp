class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0 ;
        int j = 0;
        while(i <= j && i < nums.size()){
            j = max(j , i + nums[i]);
            i++;
        }
        if(i >= nums.size())return true;
        return false;
    }
};